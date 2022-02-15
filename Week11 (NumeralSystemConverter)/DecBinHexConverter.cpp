#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

int Menu(int counter) {
    int x;
    cout << "[1] Decimal to Binary \n" << "[2] Decimal to Hexadecimal \n" 
    << "[3] Binary to Decimal \n" << "[4] Binary to Hexadecimal \n" 
    << "[5] Hexadecimal to Decimal \n" << "[6] Hexadecimal to Binary \n"
    << "[7] Quit \n";
    cin >> x;
    if (x < 1 || x > 7) {
        Menu(counter + 1); // Recursion
    }
    else if (counter > 10) {
        return 0; // Using 0 as an error code
    }
    else {
        return x; // Returns menu number selected
    }
    return 0;
}

string DecBin(int x) {
    int xCopy;
    xCopy = x;
    string result = "";
    int power = 0;
    int counter = 0;
    while (x >= power) { // Find next biggest power
        power = pow(2.0, counter);
        counter += 1;
    }
    while (xCopy != 0) { // Minus the powers that fit until 0
        counter -= 1;
        power = pow(2.0, counter);
        if (xCopy >= power) {
            xCopy -= power;
            result += "1";
        }
        else {
            result += "0";
        }
    }
    return result.erase(0,1);
}

string DecHexSwitcher(int remaining, string result) {
    switch(remaining) {
        case 0:
            result = "0" + result;
            break;
        case 1:
            result = "1" + result;
            break;
        case 2:
            result = "2" + result;
            break;
        case 3:
            result = "3" + result;
            break;
        case 4:
            result = "4" + result;
            break;
        case 5:
            result = "5" + result;
            break;
        case 6:
            result = "6" + result;
            break;
        case 7:
            result = "7" + result;
            break;
        case 8:
            result = "8" + result;
            break;
        case 9:
            result = "9" + result;
            break;
        case 10:
            result = "A" + result;
            break;
        case 11:
            result = "B" + result;
            break;
        case 12:
            result = "C" + result;
            break;
        case 13:
            result = "D" + result;
            break;
        case 14:
            result = "E" + result;
            break;
        case 15:
            result = "F" + result;
            break;
        default:
            break;
    }
    return result;
}

string DecHex(int x) {
    int total;
    total = x;
    string result = "";
    bool flag = true;
    while (flag) {
        int intDiv = total / 16; // Find the quotient
        int remaining = total - (intDiv*16); //  Find the remainder
        result = DecHexSwitcher(remaining, result); // Calculate what is sent to results
        total = intDiv; 
        if (total <= 0) { // Repeat until 0
            flag = false;
        }
    }
    return result;
}

int BinDec(int x) {
    int xCopy;
    xCopy = x;
    int result = 0;

    int len = 1;
    if (xCopy > 0) { // Get length of number
        for (len = 0; xCopy > 0; len++) {
            xCopy = xCopy / 10;
        }
    }

    int lenCount;
    lenCount = len;
    for (int i=len-1; i>=0; i--) { 
        // Get digit individually
        int y = pow(10, i);
        int z = x/y;
        int x2 = x / (y * 10);
        int digit = z - x2*10;

        // Check if its a 1 and add appropriate power of 2
        if (digit == 1) {
            int power = pow(2, (lenCount-1));
            result += power;
        }
        lenCount -= 1;
    }
    return result;
}

int HexDecSwitcher(char x) {
    if (x == '0') {
        return 0;
    }
    else if (x == '1') {
        return 1;
    }
    else if (x == '2') {
        return 2;
    }
    else if (x == '3') {
        return 3;
    }
    else if (x == '4') {
        return 4;
    }
    else if (x == '5') {
        return 5;
    }
    else if (x == '6') {
        return 6;
    }
    else if (x == '7') {
        return 7;
    }
    else if (x == '8') {
        return 8;
    }
    else if (x == '9') {
        return 9;
    }
    else if (x == 'A' || x == 'a') {
        return 10;
    }
    else if (x == 'B' || x == 'b') {
        return 11;
    }
    else if (x == 'C' || x == 'c') {
        return 12;
    }
    else if (x == 'D' || x == 'd') {
        return 13;
    }
    else if (x == 'E' || x == 'e') {
        return 14;
    }
    else if (x == 'F' || x == 'f') {
        return 15;
    }
    return 0;
}

int HexDec(string x) {
    string xCopy;
    xCopy = x;
    int result = 0;

    int len = x.length();
    len -= 1;
    int lenCount = 0;
    while (lenCount <= len) {
        int val = HexDecSwitcher(x[lenCount]);
        result += pow(16, len-lenCount)*val;
        lenCount += 1;
    }

    return result;
}

int getIntX() {
    int x;
    cout << "Please enter the original positive integer value \n";
    cin >> x;
    if (x < 1) {
        cout << "Not a positive number";
        return -1;
    }
    else {
        return x;
    }
}

string getStrY() {
    string x;
    cout << "Please enter the original positive integer value \n";
    cin >> x;
    return x;
}

bool Decision(int option) {
    if (option != 0) {
        int x;
        string y;
        switch(option) {
            case 1:
                x = getIntX();
                if (x < 0) {
                    break;
                }
                else {
                    cout << x << " as a binary number is " << DecBin(x) << endl;
                }
                break;

            case 2:
                x = getIntX();
                if (x < 0) {
                    break;
                }
                else {
                    cout << x << " as a hexadecimal number is " << DecHex(x) << endl;
                }
                break;

            case 3:
                x = getIntX();
                if (x < 0) {
                    break;
                }
                else {
                    cout << x << " as a decimal number is " << BinDec(x) << endl;
                    break;
                }
                break;

            case 4:
                x = getIntX();
                if (x < 0) {
                    break;
                }
                else {
                    cout << x << " as a hexadecimal number is " << DecHex(BinDec(x)) << endl;
                    break;
                }
            case 5:
                y = getStrY();
                cout << y << " as a deciaml number is " << HexDec(y) << endl;
                break;

            case 6:
                y = getStrY();
                cout << y << " as a binary number is " << DecBin(HexDec(y)) << endl;
                break;

            case 7:
                return true;
                break;

            default:
                cout << "An error has occured \n";
        }
    }
    return false;
}

int main() {
    bool quit = false;
    while (quit != true){
        int counter = 0; // Used to stop infinite recursion of Menu()
        int returnVal;
        returnVal = Menu(counter);
        quit = Decision(returnVal);
    }

    return 0;
}