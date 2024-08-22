#ifndef USER_H
#define USER_H
#include <iostream>
#include <windows.h>
#include <vector>
#include "User.h"
#include "Utils.h"

using namespace std;

class UserManager
{
    int loggedUserId;
    vector <User> users;
    //UserFile userFile;
    User enterUserData();
    bool checkIfLoginExist(string &login);

public:
    void registerUser();
    void loginUser();


    void displayAllUsers();



};

#endif // USER_H
