#ifndef BUDGET_MAIN_APP_H
#define BUDGET_MAIN_APP_H
#include <iostream>
#include "UserManager.h"

using namespace std;

class BudgetMainApp {
    UserManager userManager;

public:
    BudgetMainApp(string userFileName): userManager(userFileName) {};
    bool isUserLoggedIn();
    void registerUser();
    void loginUser();
    void changeUserPassword();
    void logoutUser();

};
#endif // BUDGET_MAIN_APP_H
