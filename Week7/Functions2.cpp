#include <iostream>
using namespace std;

void function1(string name) { // Parameter(s)
    cout << "Hi " << name << endl;
}

void function2(string country = "UK") { // Equals sets a default parameter or an optional parameter
    cout << country << endl;
}

void function3(string name, int age) { // Multiple Parameters
    cout << name << ", " << age << endl;
}

int add(int x, int y) {
    return x + y;
}

void refFunction(int &x, int &y) {
    int z = x;
    x = y;
    y = z;
}

int addFunc(int x, int y) {
    return x + y;
}

float addFunc(float x, float y) {
    return x + y;
}

int main() {
    {
    function1("Tom"); // Argument(s)
    function1("John");
    function1("Bob");
    cout << endl;
    }
    {
    function3("Tom", 26); // Arguments
    function3("John", 27);
    function3("Bob", 25);
    cout << endl;
    }
    {
    cout << add(10,2) << endl;
    int val = add(9,4);
    cout << val << endl;
    cout << add(16,4) << endl;
    cout << endl;
    }
    {
    int a = 15;
    int b = 12;
    cout << "Before Swap: " << a << " " << b << endl;
    refFunction(a, b);
    cout << "After Swap: " << a << " " << b << endl;
    cout << endl;
    }
    {
    int a = 15;
    int b = 12;    
    float c = 15.6;
    float d = 12.2;
    int val = addFunc(a, b);
    float val2 = addFunc(c, d);
    cout << val << " " << val2 << endl;
    cout << endl;
    }
    
    return 0;
}