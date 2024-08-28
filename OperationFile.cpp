#include "OperationFile.h"

vector <Operation> OperationFile::loadOperationsFromFile (const int loggedUserId) {

    Operation operation;
    CMarkup xml;
    vector <Operation> operations;
    bool fileExists = xml.Load( OPERATION_FILE_NAME.c_str() );//nazwa? , kod razy dwa dla kazdego pliku?
    string idTemp = "", userIdTemp = "", dateTemp = "", amountTemp = "";
    if (!fileExists) {
    } else {
        xml.ResetPos();
        xml.FindElem(); // root Root element
        xml.IntoElem(); // inside Root
        while ( xml.FindElem("Operation") ) {
            xml.IntoElem();  // inside Operation
            xml.FindElem( "Id" );
            idTemp = xml.GetData();
            operation.id = stoi(idTemp);
            xml.FindElem( "UserId" );
            userIdTemp = xml.GetData();
            operation.userId = stoi(userIdTemp);
            xml.FindElem( "Date" );
            dateTemp = xml.GetData();
            operation.date = stoi(dateTemp);
            xml.FindElem( "Item" );
            operation.item = xml.GetData();
            xml.FindElem( "Amount" );
            amountTemp = xml.GetData();
            operation.amount = stod(amountTemp);

            if (operation.userId == loggedUserId) {
                operations.push_back(operation);
            }

            xml.OutOfElem(); // get back to Root
        }
    }
    return operations;

}
void OperationFile::addOperationToFile (const Operation &operation) {

    CMarkup xml;
    bool fileExists = xml.Load( OPERATION_FILE_NAME.c_str() );
    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Root");
    }
    xml.FindElem(); // root Root element
    xml.IntoElem(); // inside Root
    xml.AddElem("Operation");
    xml.IntoElem();
    xml.AddElem("Id", operation.id);
    xml.AddElem("UserId", operation.userId);
    xml.AddElem("Date", operation.date);
    xml.AddElem("Item", operation.item);
    xml.AddElem("Amount", operation.amount);
    xml.Save(OPERATION_FILE_NAME.c_str());
}

int OperationFile::getLastId() {

    bool fileExists = xml.Load( OPERATION_FILE_NAME.c_str() );
    string tempString = "";
    int lastId = 0;
    if (!fileExists) {
        cout << "File doesn't exist";
    } else {
        xml.ResetPos();
        xml.FindElem(); // root Root element
        xml.IntoElem(); // inside Root
        while ( xml.FindElem("Operation") ) {
            xml.IntoElem();  // inside Operation
            xml.FindElem( "Id" );
            tempString = xml.GetData();
            lastId = stoi(tempString);
            xml.OutOfElem(); // get back to Root
        }
    }
    return lastId;
}

