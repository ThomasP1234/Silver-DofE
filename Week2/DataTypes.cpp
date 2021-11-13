/* Author: Thomas Preston
ref: www.w3school.com/cpp */

#include <iostream>
#include <string>
using namespace std;

int main() {
	int myNum = 150;
	cout << myNum << endl;
	
	float myFloat = 10.7;
	cout << myFloat << endl;
	
	double myDouble = 105.25; // doubles are more accurate than floats
	cout << myDouble << endl;
	
	cout << "\n\n";
	
	double sciDouble = 15E5;
	float sciFloat = 13e4;
	cout << sciDouble << "\n" << sciFloat << endl;
	
	cout << "\n\n";
	
	bool myBool1 = true;
	bool myBool2 = false;
	cout << myBool1 << endl;  // Outputs 1 (true)
	cout << myBool2 << endl; // Outputs 0 (false)
	
	cout << "\n\n";
	
	char a = 65, b = 66, c = 67; // This uses ASCII valuses
	cout << a << endl; // A
	cout << b << endl; // B
	cout << c << endl; // C
	
	cout << "\n\n";
	
	string myText = "Hello"; // Strings are not a built in type, additional header file is needed
	cout << myText << endl;
	
	return 0;
}
