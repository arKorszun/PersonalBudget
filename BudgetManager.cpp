#include "BudgetManager.h"

void BudgetManager::addIncome() {
    Operation operation = addOperationDetails(INCOME);
    incomes.push_back(operation);
    incomeFile.addOperationToFile(operation);
    cout << "\nIncome successfully added!\n" << endl;
    system("pause");
}

void BudgetManager::addExpense() {
    Operation operation = addOperationDetails(EXPENSE);
    expenses.push_back(operation);
    expenseFile.addOperationToFile(operation);
    cout << "\nExpense successfully added!\n" << endl;
    system("pause");
}

Operation BudgetManager::addOperationDetails(const Type &type) {
    string typeDescription, tempDate, tempAmount;
    Operation operation;
    DateMethods dateMethods;
    CashMethods cashMethods;
    bool isDateValid = false;

    switch (type) {

    case INCOME:
        if(incomes.empty()) operation.id = 1;
        else operation.id = incomeFile.getLastId() + 1;
        typeDescription = "income";
        break;
    case EXPENSE:
        if(expenses.empty()) operation.id = 1;
        else operation.id = expenseFile.getLastId() + 1;
        typeDescription = "expense";
        break;
    }

    operation.userId = LOGGED_USER_ID;

    do{
        cout << "Enter " << typeDescription << " date (yyyy-mm-dd). Type 't' if you want to enter current date: ";
        tempDate = Utils::getLine();
        if (tempDate == "t"){
            tempDate = dateMethods.convertIntDateToStringWithDashes(dateMethods.getCurrentDate());  //mozna optymalizowac
            isDateValid = true;
        }
        else {
            isDateValid=dateMethods.validateDate(tempDate);
        }
    } while (!isDateValid);
    operation.date = dateMethods.convertStringDateToInt(tempDate);

    cout << "Enter " << typeDescription << " name: ";
    operation.item = Utils::getLine();

     do{
        cout << "Enter " << typeDescription << " amount with up to two decimal places: ";
        tempAmount = Utils::getLine();
    } while (!cashMethods.validateAmount(tempAmount));
    operation.amount = stod(tempAmount);

    return operation;
}

void BudgetManager::displayAllExpenses() {
    for (size_t i = 0; i < expenses.size(); i++ ) {
        cout << expenses[i].id << endl;
        cout << expenses[i].userId << endl;
        cout << expenses[i].date<< endl;
        cout << expenses[i].item<< endl;
        cout << expenses[i].amount<< endl;
    }

    }
