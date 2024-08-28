#ifndef BUDGET_MAIN_APP_H
#define BUDGET_MAIN_APP_H
#include <iostream>
#include "UserManager.h"
#include "BudgetManager.h"

using namespace std;

class BudgetMainApp {
    UserManager userManager;
    BudgetManager *budgetManager;
    const string INCOMES_FILE_NAME;
    const string EXPENSES_FILE_NAME;

public:
    BudgetMainApp(string userFileName, string incomesFileName, string expensesFileName)
        : userManager(userFileName), INCOMES_FILE_NAME(incomesFileName), EXPENSES_FILE_NAME(expensesFileName) {
        budgetManager = NULL;
    };
    ~BudgetMainApp(){
        delete budgetManager;
        budgetManager = NULL;
        }
    bool isUserLoggedIn();
    void registerUser();
    void loginUser();
    void changeUserPassword();
    void logoutUser();

    void addIncome();
    void addExpense();
    void showCurrentMonthBalance();
    void showPreviousMonthBalance();
    void showCustomPeriodBalance();

    void dispAllUserInc();//test

};
#endif // BUDGET_MAIN_APP_H
