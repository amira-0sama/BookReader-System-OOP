#ifndef BOOKSMANAGER_H
#define BOOKSMANAGER_H

#include <map>
#include <vector>
#include <string>
#include "Book.h"
#include "ReadingSession.h"


class BooksManager {
private:
    std::map<std::string, Book> books_map;
    std::map<std::string, std::vector<ReadingSession>> user_sessions;

public:
    BooksManager();
    void add_book(std::string isbn, std::string title, std::string author, int pages);
    const std::map<std::string, Book>& get_books() const;
    std::vector<ReadingSession>& get_user_sessions(std::string username);
    ReadingSession* get_or_create_session(std::string username, std::string isbn);
    Book get_book_by_isbn(std::string isbn);
    std::string get_current_date();
};

#endif
