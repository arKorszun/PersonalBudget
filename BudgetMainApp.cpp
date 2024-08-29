#include "BudgetMainApp.h"

bool BudgetMainApp::isUserLoggedIn() {
    return userManager.isUserLoggedIn();
}
void BudgetMainApp::registerUser() {
    userManager.registerUser();
}
void BudgetMainApp::loginUser() {
    userManager.loginUser();
    if (userManager.isUserLoggedIn()) {
        budgetManager = new BudgetManager(userManager.getLoggedUserId(),INCOMES_FILE_NAME,EXPENSES_FILE_NAME );
    }
}
void BudgetMainApp::changeUserPassword() {
    userManager.changeUserPassword();
}
void BudgetMainApp::logoutUser() {
    userManager.logoutUser();
    delete budgetManager;
    budgetManager = NULL;
}
void BudgetMainApp::addIncome() {
    budgetManager->addIncome();
}
void BudgetMainApp::addExpense() {
    budgetManager->addExpense();
}
void BudgetMainApp::showCurrentMonthBalance() {
    budgetManager->showCurrentMonthBalance();
}
void BudgetMainApp::showPreviousMonthBalance() {
    budgetManager->showPreviousMonthBalance();
}
void BudgetMainApp::showCustomPeriodBalance() {
    budgetManager->showCustomPeriodBalance();
}

