#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book {
private:
    string isbn;
    string title;
    string author_name;
    int pages_count;

public:
    Book();
    Book(string id, string t, string auth, int pages);

    string get_isbn() const;
    string get_title() const;
    string get_author() const;
    int get_pages_count() const;
};

#endif