/* Author: Thomas Preston
ref www.w3school.com/cpp/*/

#include <iostream>
#include <string>
using namespace std;

int main() {
	string firstname = "Thomas";
	string lastname = "Preston";
	string fullname = firstname + " " + lastname;
	cout << fullname << endl;

	string fullname2 = firstname.append(" ");
	fullname2 = fullname2.append(lastname);
	cout << fullname2 << endl;

	string x = "10";
	string y = "20";
	string z = x + y;
	cout << z << endl;

	string myStr = "abcd";
	cout << "The length of the string is: " << myStr.length() << endl;
	cout << "The length of the string is: " << myStr.size() << endl;

	cout << "The first character is: " << myStr[0] << endl;
	myStr[0] = 'A';
	cout << "New string: " << myStr << endl;

	string fullName3;
	cout << "Enter full name: ";
	getline(cin, fullName3); // Use getline() instead of cin for strings as  cin thinks a space is a terminating char
	cout << "Your name is " << fullName3 << endl;

	return 0;
}
