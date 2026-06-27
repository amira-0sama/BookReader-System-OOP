#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User {
private:
    string username;
    string password;
    string name;
    string email;
    bool is_admin;

public:
    User();
    User(string un, string pw, string n, string em, bool admin);

    string get_username() const;
    string get_password() const;
    string get_name() const;
    string get_email() const;
    bool get_is_admin() const;
};

#endif