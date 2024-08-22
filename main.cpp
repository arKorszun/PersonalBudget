#include <iostream>
#include "UserManager.h"

using namespace std;

int main()
{
    UserManager userManager;

    userManager.registerUser();
    //userManager.registerUser();
    userManager.displayAllUsers();
    userManager.loginUser();
    cout << "Hello world!" << endl;
    return 0;
}
