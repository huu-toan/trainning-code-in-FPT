#include <iostream>
using namespace std;

// Class GPIO đại diện cho các phương thức điều khiển GPIO
class GPIO {
    // Phương thức ghi trạng thái pin
    void writePin() {
        // implement here
    }

    // Phương thức đọc trạng thái pin
    void readPin() {
        // implement here
    }
};

// Class BaseCar đại diện cho thông tin chung của một chiếc xe
class BaseCar {
private:
    string ownerName; // Tên chủ sở hữu
    int manufacturingYear; // Năm sản xuất

protected:
    // Thêm các thuộc tính hoặc phương thức bảo vệ nếu cần

public:
    // Thêm các phương thức công cộng và các hàm khởi tạo nếu cần
};

// Class CarCheck là lớp con của BaseCar, kiểm tra trạng thái di chuyển và trang thiết bị trong xe
class CarCheck : public BaseCar {
public:
    // Kiểm tra trạng thái di chuyển của xe
    void checkMovementStatus() {
        // implement here
    }

    // Kiểm tra trạng thái các thiết bị trong xe (cửa kính, xăng dầu, nhiệt độ, tốc độ, vv.)
    void checkDevicesStatus() {
        // implement here
    }
};

// Class CarInformation là lớp con của BaseCar, chứa thông tin cơ bản về xe
class CarInformation : public BaseCar {
public:
    string carName; // Tên xe
    string licensePlate; // Biển số xe
    string carBrand; // Hãng xe
    // Thêm các thông tin khác nếu cần
};

// Class button đại diện cho các phím trên màn hình hoặc điều khiển bên ngoài
class Button {
    // implement here
};

// Hàm screenprint dùng để in ra màn hình
void screenprint() {
    // implement here
}

int main() {
    // implement your main code here
    return 0;
}
