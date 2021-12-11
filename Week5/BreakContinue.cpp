#include <iostream>
using namespace std;

int main() {
	int i;
	for (i = 0; i < 10; i++) {
		if (i == 4) {
			break;
		}
		cout << i << endl;
	}

	i = 0;
	while (i < 10) {
		i++;
		if (i == 4) {
			continue;
		}
		cout << i << endl;
	}

	return 0;
}
