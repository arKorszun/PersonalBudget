#include "UserManager.h"

void UserManager::registerUser() {
    User user = enterUserData();
    users.push_back(user);
    userFile.addUserToFile(user);
    cout << "\nNew account successfully added!\n" << endl;
    system("pause");
}

User UserManager::enterUserData() {

    User user;

    if (users.empty() == true)
        user.id = 1;
    else
        user.id = users.back().id + 1;

    string login;
    do {
        cout << "\nEnter login:\n";
        login = Utils::getLine();
        user.login = login;
    } while (checkIfLoginExist(login) == true);
    string password;
    cout << "\nEnter password:\n";
    password = Utils::getLine();
    user.password = password;
    return user;
}

bool UserManager::checkIfLoginExist(string &login) {
    for (size_t i = 0; i < users.size(); i++ ) {
        if (users[i].login == login) {
            cout  << "\nEntered login exists, choose another\n" << endl;
            Sleep(600);
            return true;
        }
    }
    return false;
}

void UserManager::loginUser() {
    User user;
    string login = "", password = "";
    loggedUserId = 0;
    cout << "\nEnter login:\n";
    login = Utils::getLine();

    for (size_t i = 0; i < users.size(); i++ ) {
        if (users[i].login == login) {
            for (int attemptsNum = 3; attemptsNum > 0; attemptsNum--) {
                cout << "Enter password, attempts left: " << attemptsNum << ": ";
                password = Utils::getLine();

                if (users[i].password == password) {
                    cout << endl << "Logging successful! Welcome " << login << endl << endl;
                    this->loggedUserId = users[i].id;
                    system("pause");
                    return;
                }
            }
            cout << "\nYou've entered wrong password 3 times!" << endl;
            system("pause");
            return;
        }
    }
    cout << "\nEntered login doesn't exist" << endl << endl;
    system("pause");
    return;
}

void UserManager::displayAllUsers() {
    for (size_t i = 0; i < users.size(); i++ ) {
        cout << users[i].id << endl;
        cout << users[i].login << endl;
        cout << users[i].password<< endl;

    }
}
