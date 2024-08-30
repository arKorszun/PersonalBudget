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
        operation.id = incomeFile.getLastId() + 1;
        typeDescription = "income";
        break;
    case EXPENSE:
        operation.id = expenseFile.getLastId() + 1;
        typeDescription = "expense";
        break;
    }

    operation.userId = LOGGED_USER_ID;

    do {
        cout << "Enter " << typeDescription << " date (yyyy-mm-dd). Type 't' if you want to enter current date: ";
        tempDate = Utils::getLine();
        if (tempDate == "t") {
            tempDate = dateMethods.convertIntDateToStringWithDashes(dateMethods.getCurrentDate());
            isDateValid = true;
        } else {
            isDateValid=dateMethods.validateDate(tempDate);
        }
    } while (!isDateValid);
    operation.date = dateMethods.convertStringDateToInt(tempDate);

    cout << "Enter " << typeDescription << " name: ";
    operation.item = Utils::getLine();

    do {
        cout << "Enter " << typeDescription << " amount with up to two decimal places: ";
        tempAmount = Utils::getLine();
    } while (!cashMethods.validateAmount(tempAmount));
    double doubleTempAmount = stod(tempAmount);
    operation.amount = doubleTempAmount;


    return operation;
}

double BudgetManager::calculateBalance(int startDate, int endDate, const Type &type) {
    double sum = 0;
    switch (type) {

    case INCOME:

        for (size_t i = 0; i < incomes.size(); i++ ) {
            if ((incomes[i].date >= startDate) && (incomes[i].date <= endDate)) {
                sum += incomes[i].amount;
            }
        }
        return sum;
        break;
    case EXPENSE:
         for (size_t i = 0; i < expenses.size(); i++ ) {
            if ((expenses[i].date >= startDate) && (expenses[i].date <= endDate)) {
                sum += expenses[i].amount;
            }
        }
        return sum;
        break;
    }
    return 0;
}

void BudgetManager::showBalance(int startDate, int endDate) {
    DateMethods dateMethods;
    int incomesNumber = 1, expensesNumber = 1;
    double incomesBalance = 0, expensesBalance = 0, balance = 0;

    system("cls");
    cout << fixed << setprecision(2);
    sort( incomes.begin(), incomes.end(),
    []( const Operation &left, const Operation &right ) {
        return ( left.date > right.date );
    } );
    if (!incomes.empty()) {
        cout << "         >>> INCOMES <<<" << endl;
        cout << "--------------------------------------" << endl;
        for (size_t i = 0; i < incomes.size(); i++ ) {
            if ((incomes[i].date >= startDate) && (incomes[i].date <= endDate)) {
                cout <<"No.     " << incomesNumber << endl;
                cout <<"Date:   " << dateMethods.convertIntDateToStringWithDashes(incomes[i].date) << endl;
                cout <<"Item:   " << incomes[i].item << endl;
                cout <<"Amount: " << incomes[i].amount << endl << endl;
                incomesNumber++;
            }
        }
        cout << endl;
        incomesBalance = BudgetManager::calculateBalance(startDate, endDate, INCOME);
    } else {
        cout << endl << "Your Incomes book is empty" << endl << endl;
    }

    sort( expenses.begin(), expenses.end(),
    []( const Operation &left, const Operation &right ) {
        return ( left.date > right.date );
    } );
    if (!expenses.empty()) {
        cout << "         >>> EXPENSES <<<" << endl;
        cout << "--------------------------------------" << endl;
        for (size_t i = 0; i < expenses.size(); i++ ) {
            if ((expenses[i].date >= startDate) && (expenses[i].date <= endDate)) {
                cout <<"No.     " << expensesNumber << endl;
                cout <<"Date:   " << dateMethods.convertIntDateToStringWithDashes(expenses[i].date) << endl;
                cout <<"Item:   " << expenses[i].item << endl;
                cout <<"Amount: " << expenses[i].amount << endl << endl;
                expensesNumber++;
            }
        }
        cout << endl;
        expensesBalance = BudgetManager::calculateBalance(startDate, endDate, EXPENSE);

    } else {
        cout << endl << "Your Expenses book is empty" << endl << endl;
    }

    balance = incomesBalance - expensesBalance;
    cout << "         >>> BALANCE <<<" << endl;
    cout << "--------------------------------------" << endl;
    cout << "Incomes =  " << incomesBalance << " PLN" << endl;
    cout << "Expenses = " << expensesBalance << " PLN" << endl << endl;
    if (balance > 0) {
        cout << "Congratulations ! you managed to save :" << balance << " PLN" << endl;
    } else if (balance < 0) {
        cout << "Unfortunately, your expenses have exceeded your income, the balance is:  :" << balance << " PLN" << endl;
    } else if (balance == 0) {
        cout << "Your balance is equal :" << balance << " PLN" << endl;
    }
    system("pause");
}

void BudgetManager::showCurrentMonthBalance() {
    DateMethods dateMethods;
    int startDate = 0, endDate = 0;
    startDate = dateMethods.getCurrentMonthFirstDayDate();
    endDate = dateMethods.getCurrentDate();
    BudgetManager::showBalance(startDate, endDate);
}

void BudgetManager::showPreviousMonthBalance() {
    DateMethods dateMethods;
    int startDate = 0, endDate = 0;
    startDate = dateMethods.getCurrentMonthFirstDayDate();
    endDate = dateMethods.getCurrentDate();
    BudgetManager::showBalance(startDate, endDate);

}
void BudgetManager::showCustomPeriodBalance() {
    DateMethods dateMethods;
    int startDate = 0, endDate = 0;
    string tempStartDate = "", tempEndDate = "";
    bool isDateValid = false;

    do {
        cout << "Enter start date (yyyy-mm-dd): ";
        tempStartDate = Utils::getLine();
        isDateValid=dateMethods.validateDate(tempStartDate);
    } while (!isDateValid);
    startDate = dateMethods.convertStringDateToInt(tempStartDate);

    do {
        cout << "Enter end date (yyyy-mm-dd). Type 't' if you want to enter current date: ";
        tempEndDate = Utils::getLine();
        if (tempEndDate == "t") {
            tempEndDate = dateMethods.convertIntDateToStringWithDashes(dateMethods.getCurrentDate());
            isDateValid = true;
        } else {
            isDateValid=dateMethods.validateDate(tempEndDate);
            if (startDate > (dateMethods.convertStringDateToInt(tempEndDate))){
                cout << "The start date can't be later than the end date" << endl;
                isDateValid = false;
            }
        }
    } while (!isDateValid);
    endDate = dateMethods.convertStringDateToInt(tempEndDate);

    BudgetManager::showBalance(startDate, endDate);

}

