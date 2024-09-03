#include "UserFile.h"

void UserFile::addUserToFile(User user) {

    bool fileExists = xml.Load( USER_FILE_NAME.c_str() );

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }
    xml.FindElem(); // root USERS element
    xml.IntoElem(); // inside USERS
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("Name", user.name);
    xml.AddElem("Surname", user.surname);
    xml.AddElem("UserId", user.id);
    xml.AddElem("Login", user.login);
    xml.AddElem("Password", user.password);
    xml.Save(USER_FILE_NAME.c_str());
}

vector <User> UserFile::loadUsersFromFile() {
    User user;
    vector <User> users;
    bool fileExists = xml.Load( USER_FILE_NAME.c_str() );
    string userIdTemp = "";
    if (!fileExists) {
    } else {
        xml.ResetPos();
        xml.FindElem(); // root USERS element
        xml.IntoElem(); // inside USERS
        while ( xml.FindElem("User") ) {
            xml.IntoElem();  // inside USER
            xml.FindElem( "Name" );
            user.name = xml.GetData();
            xml.FindElem( "Surname" );
            user.surname = xml.GetData();
            xml.FindElem( "UserId" );
            userIdTemp = xml.GetData();
            user.id = stoi(userIdTemp);
            xml.FindElem( "Login" );
            user.login = xml.GetData();
            xml.FindElem( "Password" );
            user.password = xml.GetData();
            users.push_back(user);
            xml.OutOfElem(); // get back to USERS
        }
    }
    return users;
}

bool UserFile::changePasswordInFile(int id, string password) {

    bool fileExists = xml.Load( USER_FILE_NAME.c_str() );
    string tempString = "";
    int userId = 0;
    if (!fileExists) {
        cout << "File doesn't exist";
    } else {
        xml.ResetPos();
        xml.FindElem(); // root USERS element
        xml.IntoElem(); // inside USERS
        while ( xml.FindElem("User") ) {
            xml.IntoElem();  // inside USER
            xml.FindElem( "UserId" );
            tempString = xml.GetData();
            userId = stoi(tempString);
            if (userId == id) {
                xml.FindElem( "Password" );
                xml.RemoveElem();
                xml.AddElem("Password", password);
                xml.Save(USER_FILE_NAME.c_str());
                return true;
            } else xml.OutOfElem(); // get back to USERS
        }
    }
    return false;
}
