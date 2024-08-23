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
