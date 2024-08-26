#include "BudgetManager.h"

void BudgetManager::addIncome() {
    Operation operation = addOperationDetails(INCOME);
    incomes.push_back(operation);
    //incomeFile.addOperationToFile(operation);
    cout << "\nIncome successfully added!\n" << endl;
    system("pause");
}

void BudgetManager::addExpense() {
    Operation operation = addOperationDetails(EXPENSE);
    expenses.push_back(operation);
    //expenseFile.addOperationToFile(operation);
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
        else operation.id = 1;//incomeFile.getLastId(INCOME) +1;
        typeDescription = "income";
        break;
    case EXPENSE:
        if(expenses.empty()) operation.id = 1;
        else operation.id = 1;//expenseFile.getLastId(EXPENSE) +1;
        typeDescription = "expense";
        break;
    }

    operation.userId = 1; //LOGGEDIN_USER_ID;

    do{
        cout << "Enter " << typeDescription << " date (yyyy-mm-dd). Type 't' if you want to enter current date: ";
        tempDate = Utils::getLine();
        if (tempDate == "t"){
            tempDate = dateMethods.getCurrentDate();
            isDateValid = true;
        }
        else {
            isDateValid=dateMethods.validateDate(tempDate);
            if (!isDateValid) cout << "Date out of range or wrong format.\n";
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
