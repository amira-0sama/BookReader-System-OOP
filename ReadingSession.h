#ifndef READINGSESSION_H
#define READINGSESSION_H

#include <string>
using namespace std;

class ReadingSession {
private:
    string book_isbn;
    int current_page;
    string last_read_date;

public:
    ReadingSession();
    ReadingSession(string id, int page, string date);

    string get_book_isbn() const;
    int get_current_page() const;
    string get_last_read_date() const;

    void set_current_page(int page);
    void set_last_read_date(string date);
};

#endif