#include "Utils.h"

string Utils::getLine() {
    string input = "";
    getline(cin, input);
    return input;
}
char Utils::getCharacter() {
    string input = "";
    char character  = {0};

    while (true) {
        getline(cin, input);

        if (input.length() == 1) {
            character = input[0];
            break;
        }
        cout << "\nIt is not character.Try again\n";
    }
    return character;
}

string Utils::intToStringConversion (int integer){
    ostringstream ss;
    ss << integer;
    string str = ss.str();
    return str;
}
