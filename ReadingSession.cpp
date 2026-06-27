#include "ReadingSession.h"

ReadingSession::ReadingSession() : current_page(1) {}

ReadingSession::ReadingSession(string id, int page, string date) 
    : book_isbn(id), current_page(page), last_read_date(date) {}

string ReadingSession::get_book_isbn() const { return book_isbn; }
int ReadingSession::get_current_page() const { return current_page; }
string ReadingSession::get_last_read_date() const { return last_read_date; }

void ReadingSession::set_current_page(int page) { current_page = page; }
void ReadingSession::set_last_read_date(string date) { last_read_date = date; }