#include "UserFile.h"

void UserFile::addUserToFile(User user) {

    bool fileExists = xml.Load( "users.xml" );

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }
    xml.FindElem(); // root USERS element
    xml.IntoElem(); // inside USERS
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", user.id);
    xml.AddElem("Login", user.login);
    xml.AddElem("Password", user.password);
    xml.Save("users.xml");
}

vector <User> UserFile::loadUsersFromFile() {
    User user;
    vector <User> users;
    bool fileExists = xml.Load( "users.xml" );
    string userIdTemp = "";
    if (!fileExists) {
        cout << "Plik nie istnieje";
    } else {
        xml.ResetPos();
        xml.FindElem(); // root USERS element
        xml.IntoElem(); // inside USERS
        while ( xml.FindElem("User") ) {
            xml.IntoElem();  // inside USER
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
