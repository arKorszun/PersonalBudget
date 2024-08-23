#include <iostream>
#include "UserManager.h"

using namespace std;

int main()
{
    UserManager userManager;

    //userManager.registerUser();
    //userManager.registerUser();
    userManager.displayAllUsers();
    userManager.loginUser();
    userManager.displayLoggedUserId();
    userManager.changeUserPassword();
    return 0;
}
