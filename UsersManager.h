#ifndef USERSMANAGER_H
#define USERSMANAGER_H

#include <map>
#include <string>
#include "User.h"


class UsersManager {
private:
    std::map<std::string, User> users_map;
    User* current_user;

public:
    UsersManager();
    bool verify_user(std::string username, std::string password);
    bool is_username_taken(std::string username);
    void add_new_user(std::string un, std::string pw, std::string name, std::string email);
    User* get_current_user();
    void logout();
};

#endif
