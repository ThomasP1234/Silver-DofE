#include <iostream>
#include <string>
using namespace std;

int main() {
    { // For scope of variables
        string cars[4] = {"BMW", "Ford", "Fiat", "Toyota"}; // Creates an arry with space for 4 elements, leave blank and compiler will set it to number of elements
        int nums[4] = {10, 15, 20, 5};

        cout << cars[0] << endl;
        cout << nums[1] << endl;

        nums[1] = 17; // Change value of element
        cout << nums[1] << endl;

        cout << endl;

        int arrSize = sizeof(cars)/sizeof(cars[0]); // Get size of array
        for(int i = 0; i < arrSize; i++) {
            cout << i << ": " << cars[i] << endl; // Print each element eg. 0: BMW
        }

    }
    cout << endl;
    { // Scope

        string cars[6] = {"BMW", "Ford", "Fiat", "Toyota"}; // This array has space for 6 elements but only 4 declared which can be declared later
        cars[4] = "Tesla"; // These are added after the array was declared
        cars[5] = "Mazda";

        int arrSize = sizeof(cars)/sizeof(cars[0]); // Get size of array
        for(int i = 0; i < arrSize; i++) {
            cout << i << ": " << cars[i] << endl; // Print each element eg. 0: BMW
        }

    }
    cout << endl;
    cout << endl;
    {
        string cars[3];
        cars[0] = "BMW"; // All the elements of the array are declare afterwards
        cars[1] = "Ford";
        cars[2] = "Fiat";

        int arrSize = sizeof(cars)/sizeof(cars[0]); // Get size of array
        for(int i = 0; i < arrSize; i++) {
            cout << i << ": " << cars[i] << endl; // Print each element eg. 0: BMW
        }
    }

    return 0;
}