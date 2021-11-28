#include <iostream>
#include <string>
using namespace std;

int main() {
	if (20 > 10) {
		cout << "20 is greater than 10" << endl;
	}
	int x = 15;
	int y = 6;
	if (x == y) {
		cout << "x and y and equal" << endl;
	} else {
		cout << "x and y are not equal" << endl;
	}

	if (x > y) {
		cout << "x is greater than y" << endl;
	} else if (x < y) {
		cout << "x is less than y" << endl;
	} else {
		cout << "x is equal to y" << endl;
	}

	string result = (x == y) ? "x is equal to y" : "x is not equal to y";
	cout << result << endl;
	
	return 0;
}
