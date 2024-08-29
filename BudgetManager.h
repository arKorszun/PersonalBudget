#ifndef BUDGET_MANAGER_H
#define BUDGET_MANAGER_H
#include <iostream>
#include <vector>
#include <algorithm>
#include "Operation.h"
#include "OperationFile.h"
#include "Type.h"
#include "Utils.h"
#include "DateMethods.h"
#include "CashMethods.h"

using namespace std;

class BudgetManager {
    const int LOGGED_USER_ID;

    OperationFile incomeFile;
    OperationFile expenseFile;
    vector <Operation> incomes;
    vector <Operation> expenses;
    Operation addOperationDetails(const Type &type);
    void showBalance(int startDate, int endDate);
    double calculateBalance(int startDate, int endDate, const Type &type);

public:
    BudgetManager (int loggedUserId,string incomeFileName, string expenseFileName)
        : LOGGED_USER_ID(loggedUserId), incomeFile(incomeFileName), expenseFile(expenseFileName) {
        incomes = incomeFile.loadOperationsFromFile(LOGGED_USER_ID);
        expenses = expenseFile.loadOperationsFromFile(LOGGED_USER_ID);
    };
    void addIncome();
    void addExpense();
    void showCurrentMonthBalance();
    void showPreviousMonthBalance();
    void showCustomPeriodBalance();

};
#endif // BUDGET_MANAGER_H
