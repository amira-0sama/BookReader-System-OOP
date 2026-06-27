#include "UsersManager.h"

UsersManager::UsersManager() : current_user(nullptr) {
    users_map["admin"] = User("admin", "admin", "Miro Admin", "admin@fayoum.edu.eg", true);
}

bool UsersManager::verify_user(string username, string password) {
    if (users_map.count(username) && users_map[username].get_password() == password) {
        current_user = &users_map[username];
        return true;
    }
    return false;
}

bool UsersManager::is_username_taken(string username) {
    return users_map.count(username) > 0;
}

void UsersManager::add_new_user(string un, string pw, string name, string email) {
    users_map[un] = User(un, pw, name, email, false);
    current_user = &users_map[un];
}

User* UsersManager::get_current_user() {
    return current_user;
}

void UsersManager::logout() {
    current_user = nullptr;
}