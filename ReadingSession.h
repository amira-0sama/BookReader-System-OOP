#ifndef READINGSESSION_H
#define READINGSESSION_H

#include <string>

class ReadingSession {
private:
    std::string book_isbn;
    int current_page;
    std::string last_read_date;

public:
    ReadingSession();
    ReadingSession(std::string id, int page, std::string date);

    std::string get_book_isbn() const;
    int get_current_page() const;
    std::string get_last_read_date() const;

    void set_current_page(int page);
    void set_last_read_date(std::string date);
};

#endif
