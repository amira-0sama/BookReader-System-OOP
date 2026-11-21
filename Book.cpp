#include "Book.h"
using namespace std;

Book::Book() : pages_count(0) {}

Book::Book(string id, string t, string auth, int pages) 
    : isbn(id), title(t), author_name(auth), pages_count(pages) {}

string Book::get_isbn() const { return isbn; }
string Book::get_title() const { return title; }
string Book::get_author() const { return author_name; }
int Book::get_pages_count() const { return pages_count; }
