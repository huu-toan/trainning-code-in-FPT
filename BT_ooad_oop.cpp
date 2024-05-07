#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>   
#include <bits/stdc++.h>

using namespace std;

union Check {
    unsigned int buttonfuel : 1;  
    unsigned int buttonspeed : 1; 
    unsigned int buttontemp : 1;
    unsigned int buttonreset : 1;
} checkbutton;

int HAL_GPIO_WritePin(int pin, int state) {
    if (pin == checkbutton.buttonfuel) {
        cout << "Nhập dữ liệu cho Fuel: ";
        cin >> checkbutton.buttonfuel;
    }
    else if (pin == checkbutton.buttonspeed) {
        cout << "Nhập dữ liệu cho Fuel: ";
        cin >> checkbutton.buttontemp;
    }
    else if (pin == checkbutton.buttontemp) {
        cout << "Nhập dữ liệu cho Fuel: ";
        cin >> checkbutton.buttontemp;
    }
    else if (pin == checkbutton.buttonreset) {
        cout << "Nhập dữ liệu cho Fuel: ";
        cin >> checkbutton.buttonreset;
    }
    return 0;
}

int HAL_GPIO_ReadPin(int pin) {
    return 0;
}

class myCar 
{
public:
    float speed;
    float temp;
    float fuel;

    float calspeed() {
        return speed;
    }
    float caltemp() {
        return temp;
    }
    float calfuel() {
        return fuel;
    }
};

class carcheck
{
private:
    /* data */
public:
 carcheck(/* args */);
     carcheck();
};

int main() {
    myCar car;

    int inneroption = 0;

toan:
    cout << "Select the option: \n1) Option 1\n2) Option 2\n3) Option 3\n4) Select again" << endl;
    if (HAL_GPIO_ReadPin(checkbutton.buttonfuel) == 1) {
        inneroption = 1;
        //phải sử dụng cái ##
    }
    else if (HAL_GPIO_ReadPin(checkbutton.buttonspeed) == 1) {
        inneroption = 2;
    }
    else if (HAL_GPIO_ReadPin(checkbutton.buttontemp) == 1) {
        inneroption = 3;
    }
    else if (HAL_GPIO_ReadPin(buttonreset) == 1) {
        goto toan;
    }

    system("cls");

    cout << "Your option is: " << inneroption << "\nMove to option: " << inneroption << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    system("cls");

    // Delay 500 milliseconds trước khi tiếp tục
    this_thread::sleep_for(chrono::milliseconds(500));

    switch (inneroption) {
        case 1:
        case 2:
        case 3: 
            cout << "Your option: " << inneroption << endl;
            cout << "Do you want to continue?\n1) Yes\n0) No\n";
            cout << "Your option: ";
            if (HAL_GPIO_ReadPin(buttonreset) == 1) {
                break;
            }
            else if(HAL_GPIO_ReadPin(buttoncheck) == 1) {
                cout << "Your information is: " << HAL_GPIO_ReadPin(...);
            }
            break;
        case 4:
            goto toan;
    }

    return 0;
}
