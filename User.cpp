#include "User.h"

User::User() : is_admin(false) {}

User::User(string un, string pw, string n, string em, bool admin) 
    : username(un), password(pw), name(n), email(em), is_admin(admin) {}

string User::get_username() const { return username; }
string User::get_password() const { return password; }
string User::get_name() const { return name; }
string User::get_email() const { return email; }
bool User::get_is_admin() const { return is_admin; }