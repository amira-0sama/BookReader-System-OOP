#ifndef BOOKREADERUI_H
#define BOOKREADERUI_H

#include "UsersManager.h"
#include "BooksManager.h"

class BookReaderUI {
private:
    UsersManager users_manager;
    BooksManager books_manager;
    int read_int(int low, int high);

public:
    void start();
    void handle_login();
    void handle_signup();
    void admin_menu();
    void customer_menu();
    void list_and_select_books();
    void view_history();
    void open_session(ReadingSession *session);
};

#endif