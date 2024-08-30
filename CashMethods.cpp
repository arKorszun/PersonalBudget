#include "CashMethods.h"

bool CashMethods::validateAmount(string &amount){ //158,2586
    string amountTemp = "";
    int dotPosition = 0, endOfAmountPosition = 0, length = 0;
    for ( size_t i = 0; i < amount.length(); i++ ){
        if (amount[i] == ','){
            amount[i] = '.';
            dotPosition =i;
        }
        if (amount[i] == '.') dotPosition =i;
    }
    length = amount.length() + 1;
    endOfAmountPosition = dotPosition+2;
    amount = amount.erase(endOfAmountPosition,(length - endOfAmountPosition));
    if(amount == "0" || amount == "0.00") {
            cout << "Amount have to be higher than 0! ";
            return false;
    }
    return true;
}
