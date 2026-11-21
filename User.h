#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    std::string username;
    std::string password;
    std::string name;
    std::string email;
    bool is_admin;

public:
    User();
    User(std::string un, std::string pw, std::string n, std::string em, bool admin);

    std::string get_username() const;
    std::string get_password() const;
    std::string get_name() const;
    std::string get_email() const;
    bool get_is_admin() const;
};

#endif
