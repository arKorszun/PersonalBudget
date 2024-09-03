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
    string login = "", name = "", surname = "";

    cout << "\nEnter your name: ";
    name = Utils::getLine();
    user.name = name;
    cout << "Enter your surname: ";
    surname = Utils::getLine();
    user.surname = surname;

    if (users.empty() == true)
        user.id = 1;
    else
        user.id = users.back().id + 1;


    do {
        cout << "Enter login: ";
        login = Utils::getLine();
        user.login = login;
    } while (checkIfLoginExist(login) == true);
    string password;
    cout << "Enter password: ";
    password = Utils::getLine();
    user.password = password;
    return user;
}

bool UserManager::checkIfLoginExist(string &login) {
    for (size_t i = 0; i < users.size(); i++ ) {
        if (users[i].login == login) {
            cout  << "\nEntered login exists, choose another !\n" << endl;
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
                    cout << endl << "Logging successful! Welcome " << users[i].name << " " << users[i].surname << endl << endl;
                    this->loggedUserId = users[i].id;
                    system("pause");
                    return;
                }
            }
            cout << "\nYou've entered wrong password 3 times!" << endl;
            Sleep(3000);
            system("pause");
            return;
        }
    }
    cout << "\nEntered login doesn't exist" << endl << endl;
    system("pause");
    return;
}

void UserManager::changeUserPassword() {
    string newPassword = "";
    bool isPasswordChanged = false;
    cout << "\nEnter new password\n";
    newPassword = Utils::getLine();

    for (size_t i = 0; i < users.size(); i++ ) {
        if (users[i].id == loggedUserId) {
            users[i].password = newPassword;
            isPasswordChanged = userFile.changePasswordInFile(loggedUserId, newPassword);
        }
    }
    if (isPasswordChanged) {
        cout <<"\nPassword updated\n";
        Sleep(400);
    } else {
        cout <<"\nSomething went wrong! Password has not been updated \n";
        Sleep(400);
    }
}

bool UserManager::isUserLoggedIn() {
    if (loggedUserId !=0) return true;
    else return false;
}

void UserManager::logoutUser() {
    if (isUserLoggedIn())
    {
       loggedUserId = 0;
    }
}
int UserManager::getLoggedUserId() {
    return loggedUserId;
}

void UserManager::displayAllUsers() {
    for (size_t i = 0; i < users.size(); i++ ) {
        cout << users[i].id << endl;
        cout << users[i].login << endl;
        cout << users[i].password<< endl;
    }
    system("pause");
}
void UserManager::displayLoggedUserId() {
    cout << loggedUserId << endl;
}
