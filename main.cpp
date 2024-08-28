#include <iostream>
#include "BudgetMainApp.h"
#include "BudgetManager.h"
#include "Menus.h"


using namespace std;

int main() {
BudgetMainApp budgetMainApp("users.xml", "incomes.xml", "expenses.xml");
BudgetManager budgetManager(1,"incomes.xml", "expenses.xml");
budgetManager.addIncome();
    return 0;
}



/*int main() {
    BudgetMainApp budgetMainApp("users.xml", "incomes.xml", "expenses.xml");
    char choice;

    while (true) {
        if (!budgetMainApp.isUserLoggedIn()) {
            Menus::showMainMenu();
            choice = Utils::getCharacter();

            switch (choice) {
            case '1':
                budgetMainApp.registerUser();
                break;
            case '2':
                budgetMainApp.loginUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "You have chosen an option that doesn't exist ." << endl << endl;
                system("pause");
                break;
            }
        } else {
            Menus::showUserMenu();
            choice = Utils::getCharacter();

            switch (choice) {
            case '1':
                //Add Income
                break;
            case '2':
                //Add Expense
                break;
            case '3':
                //Show current month balance
                break;
            case '4':
                //Show previous month balance
                break;
            case '5':
                // Show custom period balance
                break;
            case '8':
                // change password
                break;
            case '9':
                // logout
                break;
            default:
                cout << endl << "You have chosen an option that doesn't exist ." << endl << endl;
                system("pause");
                break;
            }
        }
    }
    return 0;
}*/
