#include "UserManager.h"

void UserManager::registerUser() {
    User user = enterUserData();
    users.push_back(user);

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
        cin >> login;
        user.login = login;
    } while (checkIfLoginExist(login) == true);
    string password;
    cout << "\nEnter password:\n";
    cin >> password;
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
