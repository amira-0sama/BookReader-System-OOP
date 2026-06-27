#ifndef USERSMANAGER_H
#define USERSMANAGER_H

#include <map>
#include <string>
#include "User.h"

using namespace std;

class UsersManager {
private:
    map<string, User> users_map;
    User* current_user;

public:
    UsersManager();
    bool verify_user(string username, string password);
    bool is_username_taken(string username);
    void add_new_user(string un, string pw, string name, string email);
    User* get_current_user();
    void logout();
};

#endif