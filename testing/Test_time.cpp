#include <iostream>
#include <chrono>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace chrono;

// Định nghĩa các macro cho các nút bấm
enum ButtonType {
    ButtonFuel,
    ButtonSpeed,
    ButtonTemp,
    ButtonReset,
    ButtonOut,
    ButtonCheck
};

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

// Hàm giả lập trạng thái reset các nút bấm
void HAL_GPIO_RESET_PIN() { 
    HAL_GPIO_WritePin(ButtonFuel, false);
    HAL_GPIO_WritePin(ButtonSpeed, false);
    HAL_GPIO_WritePin(ButtonTemp, false);
    HAL_GPIO_WritePin(ButtonReset, false);
    HAL_GPIO_WritePin(ButtonOut, false);
    HAL_GPIO_WritePin(ButtonCheck, false);
}

class myCar {
private:
    int speed = rand() % 100 + 1;
    int temp = rand() % 30 + 10;   
    int fuel = rand() % 200 + 50;
public:
    int reset_time = 0;
    myCar() {
        auto start = high_resolution_clock::now(); // Bắt đầu đếm thời gian

    while (true) {
        auto end = high_resolution_clock::now(); // Lấy thời gian hiện tại
        auto duration = duration_cast<seconds>(end - start); // Tính thời lượng đã trôi qua

        system("cls");
        cout << "Time elapsed: " << duration.count() << " seconds" << endl;

        cout << "Select the option: \n1) ButtonFuel\n2) ButtonSpeed\n3) ButtonTemp\n4) ButtonReset\n5) ButtonOut\n";
        int n;
        cout << "Please fill your option here: ";
        cin >> n;

        if (duration.count() >= 30) { // Nếu đã trôi qua 30 giây
            system("cls");
            cout << "No activity detected within 30 seconds. Resetting the program..." << endl;
            exit(0);
        }
            // Ghi trạng thái của nút bấm tương ứng
            switch (n) {
                case 1:
                    HAL_GPIO_WritePin(ButtonFuel, true);
                    break;
                case 2:
                    HAL_GPIO_WritePin(ButtonSpeed, true);
                    break; 
                case 3:
                    HAL_GPIO_WritePin(ButtonTemp, true);
                    break;
                case 4:
                    HAL_GPIO_WritePin(ButtonReset, true);
                    break;  
                case 5:
                    HAL_GPIO_WritePin(ButtonOut, true);
                    break;              
            }

            // Khai báo inneroption ở đây để reset giá trị của inneroption sau mỗi lần lặp
            int inneroption = 0; 

            // Đọc trạng thái của các nút bấm
            if (HAL_GPIO_ReadPin(ButtonFuel)) {
                inneroption = 1;
            }
            else if (HAL_GPIO_ReadPin(ButtonSpeed)) {
                inneroption = 2;
            }
            else if (HAL_GPIO_ReadPin(ButtonTemp)) {
                inneroption = 3;
            }
            else if (HAL_GPIO_ReadPin(ButtonReset)) {
                inneroption = 0; 
            }
            else if (HAL_GPIO_ReadPin(ButtonOut)) {
                break;
            }

            // Hiển thị thông tin và thực hiện các tác vụ
            if (inneroption != 0) {
                system("cls");
                cout << "Your option is: " << inneroption << endl;
                Sleep(1000);
                system("cls");
                cout << "Move to option: " << inneroption << endl;
                Sleep(1000);
                system("cls");
            }
            else {
                system("cls");
                cout << "restart";
                Sleep(1000);
            }

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
                    if (optioncheck) {
                        HAL_GPIO_WritePin(ButtonCheck, true);
                    } else {
                        HAL_GPIO_WritePin(ButtonReset, true);
                    }
                    
                    if (HAL_GPIO_ReadPin(ButtonReset)) {
                        system("cls");
                        break;
                    } else if(HAL_GPIO_ReadPin(ButtonCheck)) {
                        system("cls");
                        if (inneroption == 1) {
                            cout << "Your information is: " << fuel << "ml" << endl;
                            
                        }
                        else if (inneroption == 2) {
                            cout << "Your information is: " << speed << "km/h" << endl;
                        }
                        else if (inneroption == 3)
                        {
                            cout << "Your information is: " << temp << "*C" << endl;
                        }
                        Sleep(2000);
                    }
                    break;
            }
            HAL_GPIO_RESET_PIN();
        }
    }

    virtual ~myCar() {
        cout << "Calling destructor";
    }
};

class myCar_shutdown : public myCar {
public:
    myCar_shutdown () {
        system("cls"); 
        cout << "Shutdown"; 
        Sleep(2000);
        system("cls"); 

        cout << "Press any key to start...";
        getch(); 

        system("cls"); 
        cout << "Restarting...";
    }
    ~myCar_shutdown () {}
};

int main() {
    myCar_shutdown *ArcadiaCar_shutdown = new myCar_shutdown();
    myCar *ArcadiaCar = ArcadiaCar_shutdown;
    delete ArcadiaCar;
    return 0;
}
