#ifndef DATE_METHODS_H
#define DATE_METHODS_H
#include <iostream>

using namespace std;

class DateMethods {
    void calculateCurrentDate(map<string, int> &currentDate) : void
    int isYearLeap(int year);
public:

    bool validateDate(string &date);
    int convertStringDateToInt(const string &dateAsString);
    string convertIntDateToStringWithDashes(int dateAsInt);
    int getCurrentDate();
    int getCurrentMonthFirstDayDate();
    int getPreviousMonthLastDayDate();
    int getPreviousMonthFirstDayDate();



};
#endif // DATE_METHODS_H
