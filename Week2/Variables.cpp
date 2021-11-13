/* Author: Thomas Preston
ref: www.w3school.com/cpp */

#include <iostream>
#include <string>
using namespace std;

int main() {
    int myInt; // Variables dont have
    myInt = 10; // to be assigned straight away
    cout << myInt << endl;

    double myFloat = 11.85;
    cout << myFloat << endl;

    char myLetter = 'T'; // Must use '' not ""
    cout << myLetter << endl;
    
    string myText = "Hello"; // Must use "" not ''
    cout << myText << endl;

    bool myBool = true;
    cout << myBool << endl;
    
    cout << "\n\n";

    int myAge = 20;
    cout << "I am " << myAge << " years old\n";
    
    cout << "\n\n";
    
    int x = 10;
    int y = 15;
    int z = 7;
    int sum = x + y + z;
    cout << sum << endl;
    
    cout << "\n\n";
    
    int a = 5, b = 6, c = 10;
    cout << a + b + c << endl;
    
    cout << "\n\n";
    
    const int t = 10; // t will always be 10

    return 0;
}
