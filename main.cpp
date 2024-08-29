#include <iostream>
#include "BudgetMainApp.h"
#include "BudgetManager.h"
#include "Menus.h"
#include "CashMethods.h"

using namespace std;

int main() {
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
                budgetMainApp.addIncome();
                break;
            case '2':
                budgetMainApp.addExpense();
                break;
            case '3':
                budgetMainApp.showCurrentMonthBalance();
                break;
            case '4':
                budgetMainApp.showPreviousMonthBalance();
                break;
            case '5':
                budgetMainApp.showCustomPeriodBalance();
                break;
            case '8':
                budgetMainApp.changeUserPassword();
                break;
            case '9':
                budgetMainApp.logoutUser();
                break;
            default:
                cout << endl << "You have chosen an option that doesn't exist ." << endl << endl;
                system("pause");
                break;
            }
        }
    }
    return 0;
}
