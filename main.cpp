#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

double extractNumeric(const string &str) {
    bool hasDecimal = false;
    bool hasDigits = false;
    string numericPart = "";

    for (int i = 0; i < str.length(); i++) {
        char c = str[i];

        
        if (isdigit(c)) {
            numericPart += c;
            hasDigits = true;
        }
        
        else if (c == '.' && !hasDecimal) {
            numericPart += c;
            hasDecimal = true;
        }
        // + or - 
        else if ((c == '+' || c == '-') && i == 0) {
            numericPart += c;
        }
        // invalid char
        else {
            return -999999.99;
        }
    }

int main() {
    string input;

    while (true) {
        cout << "Enter a string (or 'END' to quit): ";
        cin >> input;

        if (input == "END") {
            break;
        }

        double number = extractNumeric(input);

        if (number != -999999.99) {
            cout << "The input is: " << fixed << setprecision(4) << number << endl;
        } else {
            cout << "The input is invalid." << endl;
        }
    }

    return 0;
}