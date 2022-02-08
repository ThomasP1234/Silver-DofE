#include <iostream>
using namespace std;

class Vehicle { // Base Class (parent)
    public:
        string brand = "Mercedes";
        void horn() {
            cout << "Tuut, tuut\n";
        }
};

class Car: public Vehicle { // Derived Class (child) - colon to show inheritance
    public:
        string model = "AMG";
};

class CarType: public Car { // Derived Class (grandchild)
    public:
        string vehicleClass = "Sedan";
};


class myBaseClass {
    public:
        void myFunction() {
            cout << "Hello" << endl;
        }
};

class myOtherBaseClass {
    public:
        void myOtherFunction() {
            cout << "Good morning" << endl;
        }
};

class greetings: public myBaseClass, public myOtherBaseClass {
    public:
        void myFinalFunction() {
            cout << "Hi" << endl;
        }
};


class Employee {
    protected: // Protected Access Specifier
        int salary;
};

class Programmer: public Employee {
    public:
        int bonus;
        void setSalary(int s) {
            salary = s;
        }
        int getSalary() {
            return salary;
        }
};

int main() {
    Car myCar;
    myCar.horn();
    cout << myCar.brand << " " << myCar.model << endl;

    CarType myNewCar;
    myNewCar.horn();
    cout << myNewCar.vehicleClass << " " << myNewCar.brand << " " << myNewCar.model << endl;


    greetings myObj;
    myObj.myFunction();
    myObj.myOtherFunction();
    myObj.myFinalFunction();

    
    Programmer myNewObj;
    myNewObj.setSalary(50000);
    myNewObj.bonus = 15000;
    cout << "Salary: " << myNewObj.getSalary() << endl;
    cout << "Bonus: " << myNewObj.bonus << endl;
    
    return 0;
}