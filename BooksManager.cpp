#include "BooksManager.h"
#include <sstream>
#include <ctime>
using namespace std;

BooksManager::BooksManager() {
    books_map["111"] = Book("111", "C++ Programming", "Dr. Moataz", 50);
    books_map["222"] = Book("222", "Data Structures", "Author X", 30);
}

void BooksManager::add_book(string isbn, string title, string author, int pages) {
    books_map[isbn] = Book(isbn, title, author, pages);
}

const map<string, Book>& BooksManager::get_books() const {
    return books_map;
}

vector<ReadingSession>& BooksManager::get_user_sessions(string username) {
    return user_sessions[username];
}

ReadingSession* BooksManager::get_or_create_session(string username, string isbn) {
    auto &sessions = user_sessions[username];
    for (auto &s : sessions) {
        if (s.get_book_isbn() == isbn) return &s;
    }
    ReadingSession new_s(isbn, 1, get_current_date());
    sessions.push_back(new_s);
    return &sessions.back();
}

Book BooksManager::get_book_by_isbn(string isbn) {
    return books_map[isbn];
}

string BooksManager::get_current_date() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    stringstream ss;
    ss << 1900 + ltm->tm_year << "-" << 1 + ltm->tm_mon << "-" << ltm->tm_mday;
    return ss.str();
}
