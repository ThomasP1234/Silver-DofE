#include <iostream>
using namespace std;

int main() {
    string food = "Pizza";
    string &meal = food; // & is used to create a refernce variable
    string* ptr = &food; // 8 is used to create a pointer
    // string * ptr = &food; // These methods can also be used but the above one is prefered
    // string *ptr = &food 

    cout << food << endl; // All output Pizza
    cout << meal << endl;
    cout << *ptr << endl; // * can also be used as a dereference operator

    cout << endl;

    cout << &food << endl; // & can also be used to get the address of a variable in memory
    cout << &meal << endl; // These have the same address in memory
    cout << ptr << endl;

    cout << endl;

    *ptr = "Burger";

    cout << food << endl; // The variable and the pointer's data have been changed
    cout << *ptr << endl;
    
    return 0;
}