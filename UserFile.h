#ifndef USERFILE_H
#define USERFILE_H
#include <iostream>
#include <vector>
#include "User.h"
#include "Utils.h"
#include "Markup.h"

class UserFile{
    CMarkup xml;
public:
    void addUserToFile(User user);
    vector <User> loadUsersFromFile();
    bool changePasswordInFile(int id, string password);

};

#endif // USERFILE_H
