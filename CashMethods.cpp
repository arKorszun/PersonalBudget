#include "CashMethods.h"

bool CashMethods::validateAmount(string &amount){
    for ( size_t i = 0; i < amount.length(); i++ ){
        if (amount[i] == ',') amount[i] = '.';
    }
    if(amount == "0" || amount == "0.00") {
            cout << "Amount have to be higher than 0! ";
            return false;
    }
    return true;
}
