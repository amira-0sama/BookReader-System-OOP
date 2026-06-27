#ifndef BOOKSMANAGER_H
#define BOOKSMANAGER_H

#include <map>
#include <vector>
#include <string>
#include "Book.h"
#include "ReadingSession.h"

using namespace std;

class BooksManager {
private:
    map<string, Book> books_map;
    map<string, vector<ReadingSession>> user_sessions;

public:
    BooksManager();
    void add_book(string isbn, string title, string author, int pages);
    const map<string, Book>& get_books() const;
    vector<ReadingSession>& get_user_sessions(string username);
    ReadingSession* get_or_create_session(string username, string isbn);
    Book get_book_by_isbn(string isbn);
    string get_current_date();
};

#endif