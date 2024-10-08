#ifndef USERMANAGER_H
#define USERMANAGER_H
#include <iostream>
#include <windows.h>
#include <vector>
#include "User.h"
#include "Utils.h"
#include "UserFile.h"

using namespace std;

class UserManager
{
    int loggedUserId;
    vector <User> users;
    UserFile userFile;
    User enterUserData();
    bool checkIfLoginExist(string &login);

public:
    UserManager(string userFileName):userFile(userFileName){
    users = userFile.loadUsersFromFile();
    loggedUserId = 0;
    }

    void registerUser();
    void loginUser();
    void changeUserPassword();
    bool isUserLoggedIn();
    void logoutUser();
    int getLoggedUserId();


    void displayAllUsers();
    void displayLoggedUserId();



};

#endif // USER_USERMANAGER_H
