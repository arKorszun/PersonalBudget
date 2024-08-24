#ifndef USERFILE_H
#define USERFILE_H
#include <iostream>
#include <vector>
#include "User.h"
#include "Utils.h"
#include "Markup.h"
#include "File.h"

class UserFile :public File {
    const string USER_FILE_NAME;

public:
    UserFile(string userFileName): File(userFileName), USER_FILE_NAME(userFileName) {};
    void addUserToFile(User user);
    vector <User> loadUsersFromFile();
    bool changePasswordInFile(int id, string password);

};

#endif // USERFILE_H
