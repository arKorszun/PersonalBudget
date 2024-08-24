#include <iostream>
#include "BudgetMainApp.h"
#include "UserManager.h"

using namespace std;

int main()
{
    BudgetMainApp budgetMainApp("users.xml");

    budgetMainApp.registerUser();
    //userManager.registerUser();
    //userManager.displayAllUsers();
    budgetMainApp.loginUser();
    //userManager.displayLoggedUserId();
    budgetMainApp.changeUserPassword();
    return 0;
}
