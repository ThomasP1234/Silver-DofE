#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string defaultGPIO = "/sys/class/gpio/";
    string GPIO;
    string GPIONum;

    cout << "Enter location of the gpio system folder \nIf 0 is entered '/sys/class/gpio/' will be used \n";
    cin >> GPIO;
    if (GPIO == "0"){
        GPIO = defaultGPIO;
    }

    cout << "Enter the number of the gpio pin\n";
    cin >> GPIONum;
    
    string GPIOExport = GPIO + "/export";
    string GPIOUnexport = GPIO + "/unexport";
    string GPIODirection = GPIO + "/gpio" + GPIONum + "/direction";
    string GPIOValue = GPIO + "/gpio" + GPIONum + "/value";

    ofstream exportFile(GPIOExport);
    exportFile << GPIONum;
    exportFile.close();

    ofstream directionFile(GPIODirection);
    directionFile << "out";
    directionFile.close();

    bool valid = false;
    int answer;
    while (!valid){
        answer = 0;
        cout << "[1] Turn LED on \n[2] Turn LED off \n[3] Quit";
        cin >> answer;
        if (answer == 1){
            ofstream valueFile(GPIOValue);
            valueFile << "1";
            valueFile.close();
        }
        else if (answer == 2){
            ofstream valueFile(GPIOValue);
            valueFile << "0";
            valueFile.close();
        }
        else if (answer == 3){
            ofstream unexportFile(GPIOUnexport);
            unexportFile << GPIONum;
            unexportFile.close();

            valid = true;
        }
    }

    return 0;
}