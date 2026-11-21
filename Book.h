#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
private:
    std::string isbn;
    std::string title;
    std::string author_name;
    int pages_count;

public:
    Book();
    Book(std::string id, std::string t, std::string auth, int pages);

    std::string get_isbn() const;
    std::string get_title() const;
    std::string get_author() const;
    int get_pages_count() const;
};

#endif
