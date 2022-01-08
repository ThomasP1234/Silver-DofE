#include <iostream>
using namespace std;

void myFunction() { // Declaration - has to come before main()
    cout << "Function has been called" << endl; // Definition - can come after main() see newFunction
}

void newFunction(); // Declaration

int main() {
    myFunction(); // Calls the function
    myFunction(); // Function can be called multiple times
    myFunction(); // Everytime it does the same thing

    newFunction();
    
    return 0;
}

void newFunction() { // Defintion 
    cout << "Function has been called" << endl;
}