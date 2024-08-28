#ifndef OPERATION_FILE_H
#define OPERATION_FILE_H
#include <iostream>
#include <vector>
#include "File.h"
#include "Operation.h"

using namespace std;

class OperationFile : public File {
    const string OPERATION_FILE_NAME;
    int lastOperationId;

public:
     OperationFile(string operationFileName)
     :File(operationFileName), OPERATION_FILE_NAME(operationFileName) {
        lastOperationId = 0;
    };
    vector <Operation> loadOperationsFromFile (const int loggedUserId);
    void addOperationToFile (const Operation &operation); //mozna dac bool sprawdzajcy czy dodalo wpis
    int getLastId();



};


#endif // OPERATION_FILE_H
