#include "DateMethods.h"

bool DateMethods::validateDate(string &date) {
    DateMethods dateMethods;
    map <string, int> currentDate;
    bool leapOrNot = false;
    string yearString = "", monthString = "", dayString = "";
    int year = 0, month = 0, day = 0;

    if (date[4] != '-' || date[7] != '-' || date.length() !=10)
        return false;



    for (int i = 0; i < 10; i++) {
        if (i<4) yearString += date[i];
        else if (i>4 && i<7) monthString += date[i];
        else if (i>7 && i<10) dayString += date[i];
    }
    year = stoi(yearString);
    month = stoi(monthString);
    day = stoi(dayString);
    leapOrNot = dateMethods.isYearLeap(year);

    if (year < 2000) return false;

    if( month > 12) return false;
    if( day > 31 ) return false;
    if( day == 31 && ( month == 2 || month == 4 || month == 6 || month == 9 || month == 11 ) ) return false; //30 days in Apr, Jun, Sep, Nov and 28\29 in Feb
    if( month == 2) {
        if( day > 29 ) return false;
        if( day == 29 && leapOrNot) return false;
    }

    dateMethods.calculateCurrentDate(currentDate);
    if (year == currentDate["year"] && month > currentDate["month"]) return false;

    return true;
}

bool DateMethods::isYearLeap(int year) {
    if((year%4==0 && year%100!=0) || year%400==0) return true;
    else return false;
}


int DateMethods::convertStringDateToInt(const string &dateAsString) {
    string dateStringNoDashes = "";
    int dateAsInt = 0;
    for (int i = 0; i < 10; i++) {
        if (dateAsString[i] == '-') {
            continue;
        } else
            dateStringNoDashes += dateAsString[i];
    }
    dateAsInt = stoi(dateStringNoDashes);
    return dateAsInt;
}

int DateMethods::getCurrentDate() {
    DateMethods dateMethods;
    map <string, int> currentDate;
    string currentDateString = "";
    string yearSt = "", monthSt = "", daySt = "";

    dateMethods.calculateCurrentDate(currentDate);
    yearSt = Utils::stringToIntConversion(currentDate["year"]);

    if(currentDate["month"] >= 10) monthSt = Utils::stringToIntConversion(currentDate["month"]);
    else monthSt = '0' + Utils::stringToIntConversion(currentDate["month"]);

    if(currentDate["day"] >= 10) daySt = Utils::stringToIntConversion(currentDate["day"]);
    else daySt = '0' + Utils::stringToIntConversion(currentDate["day"]);

    currentDateString = yearSt + monthSt + daySt;

    return dateMethods.convertStringDateToInt(currentDateString);
}

void DateMethods::calculateCurrentDate(map <string, int> &currentDate) {
    int year = 0, month = 0, day = 0;
    time_t ttime = time(0);

    tm *local_time = localtime(&ttime);
    year = 1900 + local_time->tm_year;
    month = 1 + local_time->tm_mon;
    day = local_time->tm_mday ;

    currentDate["year"] = year;
    currentDate["month"] = month;
    currentDate["day"] = day;
}


