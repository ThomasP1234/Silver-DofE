#include <iostream>
using namespace std;

class MyClass { // The Class
    public: // Access specifier
        MyClass(); // Constructor

        // Class members:

        int myNum;
        string myString;

        void myMethod() { // Declared and defined inside the class
            cout << myNum << endl; 
            cout << myString << endl;
        }

        void myMethod2(); // Declared in the class, defined outside the class

        int myMethod3(int val) { // Using parameters and return value
            int total = val + myNum;
            return total;
        }
};

class MyClass2 {
    int myNum; // By default all members are private but it is good pratice to put the in the private access specifier like the one below
    private:
        int myNum2; /* This is not accessable outside the class
        to read/write to private variables/attributes, we can use a get and set public method.
        This is called encapsulation
        */
    public:
        int myNum3;
        string myString;
        
        MyClass2(int x, string y) {
            cout << "Class constructed" << endl;
            myNum3 = x;
            myString = y;
        }
        
        void myMethod() {
            cout << myNum3 << endl; 
            cout << myString << endl;
        }

        void mySet(int x) {
            myNum = x;
        }

        int myGet() {
            return myNum;
        }
};

MyClass::MyClass() { // Using the " scope resolution operator :: " to define the method (in this case the constructor) outside the class
    cout << "Class constructed" << endl;
}

void MyClass::myMethod2() {
    cout << myString << endl;
    cout << myNum << endl; 
}

int main() {
    MyClass myObj;

    myObj.myNum = 20;
    myObj.myString = "Banana";

    cout << myObj.myNum << endl;
    cout << myObj.myString << endl;

    myObj.myMethod();

    MyClass myObj2;

    myObj2.myNum = 40;
    myObj2.myString = "Apple";

    cout << myObj2.myNum << endl;
    cout << myObj2.myString << endl;

    myObj2.myMethod2();
    cout << myObj2.myMethod3(10) << endl;


    MyClass2 myObj3(10, "Orange");
    MyClass2 myObj4(30, "Kiwi");

    myObj3.myMethod();
    myObj4.myMethod();

    myObj3.mySet(20);
    cout << myObj3.myGet() << endl;

    return 0;
}