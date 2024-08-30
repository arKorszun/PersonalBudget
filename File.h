#ifndef FILE_H
#define FILE_H
#include <iostream>
#include "Markup.h"
#include "Utils.h"

using namespace std;

class File{
const string FILE_NAME;

protected:
    CMarkup xml;
    string getFileName();
    File(string fileName): FILE_NAME(fileName){};
};

#endif // FILE_H
