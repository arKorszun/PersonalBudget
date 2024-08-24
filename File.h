#ifndef FILE_H
#define FILE_H
#include <iostream>
#include "Markup.h"

using namespace std;

class File{
const string FILE_NAME;

protected:
    int lastId;
    CMarkup xml;
    string getFileName();
    File(string fileName): FILE_NAME(fileName){};

public:
    int getLastId();


};

#endif // FILE_H
