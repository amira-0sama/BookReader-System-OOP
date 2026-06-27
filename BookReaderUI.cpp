#include "BookReaderUI.h"
#include <iostream>

int BookReaderUI::read_int(int low, int high) {
    int value;
    while (true) {
        cout << "\nEnter number in range " << low << " - " << high << ": ";
        if (cin >> value && value >= low && value <= high) {
            return value;
        }
        cout << "ERROR: invalid number...Try again\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

void BookReaderUI::start() {
    while (true) {
        cout << "\nMenu:\n\t1: Login\n\t2: Sign Up\n\t3: Exit\n";
        int choice = read_int(1, 3);

        if (choice == 1) {
            handle_login();
        } else if (choice == 2) {
            handle_signup();
        } else {
            break;
        }
    }
}

void BookReaderUI::handle_login() {
    string un, pw;
    cout << "Enter user name & password: ";
    cin >> un >> pw;
    if (!users_manager.verify_user(un, pw)) {
        cout << "\nInvalid user name or password. Try again\n";
        return;
    }
    if (users_manager.get_current_user()->get_is_admin()) admin_menu();
    else customer_menu();
}

void BookReaderUI::handle_signup() {
    string un, pw, name, email;
    while (true) {
        cout << "Enter user name (No spaces): ";
        cin >> un;
        if (users_manager.is_username_taken(un)) cout << "Already used. Try again\n";
        else break;
    }
    cout << "Enter password: "; cin >> pw;
    cout << "Enter name: "; cin >> name;
    cout << "Enter email: "; cin >> email;

    users_manager.add_new_user(un, pw, name, email);
    customer_menu();
}

void BookReaderUI::admin_menu() {
    while (true) {
        User* current = users_manager.get_current_user();
        cout << "\nMenu:\n\t1: View Profile\n\t2: Add Book\n\t3: Logout\n";
        int choice = read_int(1, 3);

        if (choice == 1) {
            cout << "\nUser " << current->get_username() << ", " << current->get_name() << ", " << current->get_email() << "\n";
        } else if (choice == 2) {
            string isbn, title, auth;
            int pages;
            cout << "Enter ISBN: "; cin >> isbn;
            cout << "Enter Title: "; cin >> title;
            cout << "Enter Author: "; cin >> auth;
            cout << "Enter Pages: "; cin >> pages;
            books_manager.add_book(isbn, title, auth, pages);
        } else {
            users_manager.logout();
            break;
        }
    }
}

void BookReaderUI::customer_menu() {
    while (true) {
        User* current = users_manager.get_current_user();
        cout << "\nMenu:\n\t1: View Profile\n\t2: List & Select From System Books\n\t3: View Reading History\n\t4: Logout\n";
        int choice = read_int(1, 4);

        if (choice == 1) {
            cout << "\nUser " << current->get_username() << ", " << current->get_name() << ", " << current->get_email() << "\n";
        } else if (choice == 2) {
            list_and_select_books();
        } else if (choice == 3) {
            view_history();
        } else {
            users_manager.logout();
            break;
        }
    }
}

void BookReaderUI::list_and_select_books() {
    vector<string> isbns;
    int idx = 1;
    cout << "\nOur Current Books:\n";
    for (auto &pair : books_manager.get_books()) {
        cout << "\t" << idx++ << ": ISBN: " << pair.second.get_isbn() << " - Title: " << pair.second.get_title() << "\n";
        isbns.push_back(pair.second.get_isbn());
    }
    cout << "\t" << idx << ": Cancel\n";
    int b_choice = read_int(1, idx);
    if (b_choice != idx) {
        ReadingSession* session = books_manager.get_or_create_session(users_manager.get_current_user()->get_username(), isbns[b_choice - 1]);
        open_session(session);
    }
}

void BookReaderUI::view_history() {
    auto &sessions = books_manager.get_user_sessions(users_manager.get_current_user()->get_username());
    if (sessions.empty()) {
        cout << "\nNo historic sessions\n";
        return;
    }
    for (int i = 0; i < (int)sessions.size(); i++) {
        Book b = books_manager.get_book_by_isbn(sessions[i].get_book_isbn());
        cout << "\t" << i + 1 << ": " << b.get_title() << " Page: " << sessions[i].get_current_page() << "/" << b.get_pages_count() << " - Date: " << sessions[i].get_last_read_date() << "\n";
    }
    cout << "\t" << sessions.size() + 1 << ": Cancel\n";
    int s_choice = read_int(1, sessions.size() + 1);
    if (s_choice != (int)sessions.size() + 1) {
        open_session(&sessions[s_choice - 1]);
    }
}

void BookReaderUI::open_session(ReadingSession *session) {
    Book b = books_manager.get_book_by_isbn(session->get_book_isbn());
    while (true) {
        cout << "\nBook: " << b.get_title() << "\nPage: " << session->get_current_page() << " / " << b.get_pages_count() << "\n";
        cout << "Menu:\n\t1: Next Page\n\t2: Previous Page\n\t3: Stop Reading\n";
        int choice = read_int(1, 3);

        if (choice == 1) {
            if (session->get_current_page() < b.get_pages_count()) {
                session->set_current_page(session->get_current_page() + 1);
                session->set_last_read_date(books_manager.get_current_date());
            } else {
                cout << "\nYou are at the last page.\n";
            }
        } else if (choice == 2) {
            if (session->get_current_page() > 1) {
                session->set_current_page(session->get_current_page() - 1);
                session->set_last_read_date(books_manager.get_current_date());
            } else {
                cout << "\nYou are at the first page.\n";
            }
        } else {
            break;
        }
    }
}