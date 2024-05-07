#include <iostream>
#include <fstream>
#include <cstdlib>

int main() {
    // Thực thi lệnh hệ thống để chạy MediaInfo và ghi thông tin vào tệp temp.txt
    std::system("MediaInfo --Inform=\"General;%CompleteName% | %Format% | %FileSize% | %Duration%\" DieuTaVietMuaXaNhau-DoanMinhQuanTienFami-9957796.mp3 > temp.txt");

    // Mở tệp văn bản để đọc thông tin đã ghi
    std::ifstream infile("temp.txt");
    if (!infile) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    // Đọc và hiển thị thông tin từ tệp văn bản
    std::string line;
    while (std::getline(infile, line)) {
        std::cout << line << std::endl;
    }

    // Đóng tệp văn bản
    infile.close();

    // Xóa tệp temp.txt sau khi sử dụng
    std::remove("temp.txt");

    return 0;
}
