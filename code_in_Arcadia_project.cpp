#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>   
#include <bits/stdc++.h>

using namespace std;

// Khởi tạo các nút bấm
enum ButtonType {
    ButtonFuel,
    ButtonSpeed,
    ButtonTemp,
    ButtonReset,
    ButtonCheck
};

// Định nghĩa union để đại diện cho các nút bấm
union Button {
    struct {
        unsigned int buttonFuel : 1;
        unsigned int buttonSpeed : 1;
        unsigned int buttonTemp : 1;
        unsigned int buttonReset : 1;
        unsigned int buttonCheck : 1;
    } state;
    unsigned int allButtons;
};

void ResetButtonintoZero() {
    buttonState.allButtons = 0;
}

int HAL_GPIO_WritePin(int pin, int state) {
    //code
    return 0; 
}

int HAL_GPIO_ReadPin(int pin) {
    //code
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

int main() {

    

    myCar car;

    int inneroption = 0;

toan:
    cout << "Select the option: \n1) Option 1\n2) Option 2\n3) Option 3\n4) Select again" << endl;
    if (HAL_GPIO_ReadPin(buttonState.state.buttonFuel) == 1) {
        inneroption = 1;
    }
    else if (HAL_GPIO_ReadPin(buttonState.state.buttonSpeed) == 1) {
        inneroption = 2;
    }
    else if (HAL_GPIO_ReadPin(buttonState.state.buttonTemp) == 1) {
        inneroption = 3;
    }
    else if (HAL_GPIO_ReadPin(buttonState.state.buttonReset = 1) == 1) {
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
