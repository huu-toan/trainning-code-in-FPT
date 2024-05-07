#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>

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

// Khai báo cấu trúc cho các ComSignal
struct ComSignal {
    bool state;
};

// Khai báo cấu trúc cho các Port
struct Port {
    ComSignal fuel;
    ComSignal speed;
    ComSignal temp;
    ComSignal reset;
    ComSignal out;
    ComSignal check;
} port;

// Hàm giả lập việc ghi trạng thái của nút bấm
void HAL_GPIO_WritePin(ButtonType pin, bool state) {
    switch (pin) {
        case ButtonFuel:
            port.fuel.state = state;
            break;
        case ButtonSpeed:
            port.speed.state = state;
            break;
        case ButtonTemp:
            port.temp.state = state;
            break;
        case ButtonReset:
            port.reset.state = state;
            break;
        case ButtonOut:
            port.out.state = state;
            break;
        case ButtonCheck:
            port.check.state = state;
            break;
    }
}

// Hàm giả lập việc đọc trạng thái của nút bấm
bool HAL_GPIO_ReadPin(ButtonType pin) {
    switch (pin) {
        case ButtonFuel:
            return port.fuel.state;
        case ButtonSpeed:
            return port.speed.state;
        case ButtonTemp:
            return port.temp.state;
        case ButtonReset:
            return port.reset.state;
        case ButtonOut:
            return port.out.state;
        case ButtonCheck:
            return port.check.state;
    }
    return false; // Trường hợp không xác định
}

class myCar {
private:
    float speed = 40;
    float temp = 27;
    float fuel = 100;
public:
    myCar() {
        // Đây là constructor của myCar
    }

    // Hàm khởi động lại xe
    void restart() {
        // In ra thông báo và thực hiện các thao tác cần thiết để khởi động lại
        cout << "Restarting...";
        // Thực hiện các thao tác cần thiết để khởi động lại
    }

    // Hàm hiển thị thông tin của xe
    void displayInfo(int option) {
        switch (option) {
            case 1:
                cout << "Your information is: " << speed << "km/h" << endl;
                break;
            case 2:
                cout << "Your information is: " << temp << "*C" << endl;
                break;
            case 3:
                cout << "Your information is: " << fuel << "l" << endl;
                break;
        }
    }

    ~myCar() {
        // Đây là destructor của myCar
        cout << "Calling destructor";
    }
};

int main() {
    myCar car; // Khởi tạo đối tượng myCar

    while (true) {
        system("cls");
        cout << "Select the option: \n1) ButtonFuel\n2) ButtonSpeed\n3) ButtonTemp\n4) ButtonReset\n5) ButtonOut\n";
        int n;
        cout << "Please fill your option here: ";
        cin >> n;

        // Ghi trạng thái của nút bấm tương ứng
        switch (n) {
            case 1:
                HAL_GPIO_WritePin(BUTTON_FUEL, true);
                break;
            case 2:
                HAL_GPIO_WritePin(BUTTON_SPEED, true);
                break; 
            case 3:
                HAL_GPIO_WritePin(BUTTON_TEMP, true);
                break;
            case 4:
                HAL_GPIO_WritePin(BUTTON_RESET, true);
                break;  
            case 5:
                HAL_GPIO_WritePin(BUTTON_OUT, true);
                break;              
        }

        // Kiểm tra xem có cần khởi động lại không
        if (HAL_GPIO_ReadPin(BUTTON_RESET)) {
            car.restart();
            continue; // Quay lại vòng lặp để chọn lại option
        }

        // Hiển thị thông tin nếu cần thiết
        car.displayInfo(n);
        Sleep(2000);
    }

    return 0;
}
