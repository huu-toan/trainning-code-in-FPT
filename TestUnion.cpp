#include <iostream>
#include <windows.h>

using namespace std;

// Định nghĩa các macro cho các nút bấm
#define BUTTON_FUEL ButtonType::ButtonFuel
#define BUTTON_SPEED ButtonType::ButtonSpeed
#define BUTTON_TEMP ButtonType::ButtonTemp
#define BUTTON_RESET ButtonType::ButtonReset
#define BUTTON_OUT ButtonType::ButtonOut
#define BUTTON_CHECK ButtonType::ButtonCheck

// Định nghĩa các macro cho việc đọc và ghi trạng thái của các nút bấm
#define WRITE_PIN(pin, state) HAL_GPIO_WritePin(pin, state)
#define READ_PIN(pin) HAL_GPIO_ReadPin(pin)

// Khởi tạo các nút bấm
enum ButtonType {
    ButtonFuel,
    ButtonSpeed,
    ButtonTemp,
    ButtonReset,
    ButtonOut,
    ButtonCheck
};

// Định nghĩa union để đại diện cho các nút bấm
union Button {
    struct {
        unsigned int buttonFuel : 1;
        unsigned int buttonSpeed : 1;
        unsigned int buttonTemp : 1;
        unsigned int buttonReset : 1;
        unsigned int buttonOut : 1;
        unsigned int buttonCheck : 1;
    } state;
    unsigned int allButtons;
};

Button buttonState; // Khai báo buttonState ở ngoài hàm main

// Hàm giả lập việc ghi trạng thái của nút bấm
int HAL_GPIO_WritePin(ButtonType pin, int state) {
    switch (pin) {
        case ButtonFuel:
            buttonState.state.buttonFuel = state;
            break;
        case ButtonSpeed:
            buttonState.state.buttonSpeed = state;
            break;
        case ButtonTemp:
            buttonState.state.buttonTemp = state;
            break;
        case ButtonReset:
            buttonState.state.buttonReset = state;
            break;
        case ButtonOut:  // Thay đổi đây để gán giá trị cho buttonOut
            buttonState.state.buttonOut = state;
            break;
        case ButtonCheck:
            buttonState.state.buttonCheck = state;
            break;
    }
    return 0; 
}

// Hàm giả lập việc đọc trạng thái của nút bấm
int HAL_GPIO_ReadPin(ButtonType pin) {
    switch (pin) {
        case ButtonFuel:
            return buttonState.state.buttonFuel;
        case ButtonSpeed:
            return buttonState.state.buttonSpeed;
        case ButtonTemp:
            return buttonState.state.buttonTemp;
        case ButtonReset:
            return buttonState.state.buttonReset;
        case ButtonOut:
            return buttonState.state.buttonOut;
        case ButtonCheck:
            return buttonState.state.buttonCheck;
    }
    return -1; // Trường hợp không xác định
}

class myCar {
private:
    float speed;
    float temp;
    float fuel;
public:
    myCar() {
        int prevOption = 0; // Biến mới để lưu trạng thái của inneroption trước khi reset

        while(true) {
            system("cls");
            cout << "Select the option: \n1) ButtonFuel\n2) ButtonSpeed\n3) ButtonTemp\n4) ButtonReset\n5) ButtonOut\n";
            int n;
            cout << "Please fill your option here: ";
            cin >> n;

            // Ghi trạng thái của nút bấm tương ứng
            switch (n) {
                case 1:
                    WRITE_PIN(BUTTON_FUEL, 1);
                    break;
                case 2:
                    WRITE_PIN(BUTTON_SPEED, 1);
                    break; 
                case 3:
                    WRITE_PIN(BUTTON_TEMP, 1);
                    break;
                case 4:
                    WRITE_PIN(BUTTON_RESET, 1);
                    break;  
                case 5:
                    WRITE_PIN(BUTTON_OUT, 1);
                    break;              
            }

            // Đọc trạng thái của các nút bấm
            int inneroption = 0; // Khai báo ở đây để reset giá trị của inneroption sau mỗi lần lặp
            if (READ_PIN(BUTTON_FUEL) == 1) {
                inneroption = 1;
            }
            if (READ_PIN(BUTTON_SPEED) == 1) {
                inneroption = 2;
            }
            if (READ_PIN(BUTTON_TEMP) == 1) {
                inneroption = 3;
            }
            if (READ_PIN(BUTTON_RESET) == 1) {
                inneroption = prevOption; // Gán giá trị trước khi reset cho inneroption
            }
            if (READ_PIN(BUTTON_OUT) == 1) {
                break;
            }

            // Cập nhật giá trị của prevOption
            if (inneroption != 0) {
                prevOption = inneroption;
            }

            // Hiển thị thông tin và thực hiện các tác vụ
            system("cls");
            cout << "Your option is: " << inneroption << endl;
            Sleep(1000);
            system("cls");
            cout << "Move to option: " << inneroption << endl;
            Sleep(1000);
            system("cls");

            // Kiểm tra các tác vụ nếu cần thiết
            switch (inneroption) {
                case 1:
                case 2:
                case 3: 
                    cout << "Your option: " << inneroption << endl;
                    cout << "Do you want to continue?\n1) Yes\n0) No\n";
                    cout << "Your option: ";
                    bool optioncheck;
                    cin >> optioncheck;
                    if (optioncheck == 1) {
                        WRITE_PIN(BUTTON_CHECK, 1);
                    } else {
                        WRITE_PIN(BUTTON_RESET, 1);
                    }
                    
                    if (READ_PIN(BUTTON_RESET) == 1) {
                        system("cls");
                        break;
                    } else if(READ_PIN(BUTTON_CHECK) == 1) {
                        system("cls");
                        cout << "Your information is: " << READ_PIN(BUTTON_TEMP) << endl;
                        Sleep(2000);
                    }
                    break;
            }
        }
    }

    float calspeed() {
        return speed;
    }
    float caltemp() {
        return temp;
    }
    float calfuel() {
        return fuel;
    }

    ~myCar() {
        cout << "Calling destructor";
    }
};

int main() {
    myCar car;
    return 0;
}
