#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>

using namespace std;

// Định nghĩa lớp Appointment đại diện cho cuộc hẹn
class Appointment {
private:
    string time;
    string date;
    string reason;

public:
    Appointment(string t, string d, string r) : time(t), date(d), reason(r) {}

    // Getter cho các thông tin của cuộc hẹn
    string getTime() const { return time; }
    string getDate() const { return date; }
    string getReason() const { return reason; }
};

// Định nghĩa lớp Participant đại diện cho người tham gia cuộc hẹn (bác sĩ hoặc bệnh nhân)
class Participant {
protected:
    string name;
    string phone;
    string address;
    int age;

public:
    Participant(string n, string p, string add, int a)
        : name(n), phone(p), address(add), age(a) {}

    // Getter cho các thông tin cá nhân của người tham gia
    string getName() const { return name; }
    string getPhone() const { return phone; }
    string getAddress() const { return address; }
    int getAge() const { return age; }
};

// Định nghĩa lớp Doctor kế thừa từ lớp Participant, đại diện cho bác sĩ
class Doctor : public Participant {
private:
    string major;

public:
    Doctor(string n, string m) : Participant(n, "", "", 0), major(m) {}

    // Phương thức hiển thị thông tin của bác sĩ
    void showInfo(int index) {
        ifstream inFile;
        string filePath = "C:/Users/vanpe/Desktop/TEST CODE/Doctor/doctorlist.txt";
        inFile.open(filePath);

        if (!inFile) {
            cerr << "Error: Unable to open doctorlist.txt" << endl;
            return;
        }

        string line;
        int count = 0;
        while (getline(inFile, line)) {
            ++count;
            if (count == index) {
                stringstream ss(line);
                string no, doctorName, major;
                if (getline(ss, no, ',') && getline(ss, doctorName, ',') && getline(ss, major, ',')) {
                    cout << "Doctor " << index << ": " << doctorName << ", Major: " << major << endl;
                }
                break;
            }
        }
        inFile.close();
    }
};

// Định nghĩa lớp Patient kế thừa từ lớp Participant, đại diện cho bệnh nhân
class Patient : public Participant {
private:
    vector<Appointment> appointments;

public:
    Patient(string n, string p, string add, int a) : Participant(n, p, add, a) {}

    // Phương thức đặt cuộc hẹn
    void makeAppointment(int doctorIndex, string time, string date, string reason) {
        Appointment appointment(time, date, reason);
        appointments.push_back(appointment);

        // Đọc tệp doctorlist.txt để lấy thông tin bác sĩ
        ifstream inFile("doctorlist.txt");
        if (!inFile) {
            cerr << "Error: Unable to open doctorlist.txt" << endl;
            return;
        }

        string line;
        int count = 0;
        string doctorName, major;
        while (getline(inFile, line)) {
            ++count;
            if (count == doctorIndex) {
                stringstream ss(line);
                string id;
                if (getline(ss, id, ',') && getline(ss, doctorName, ',') && getline(ss, major, ',')) {
                    break;
                }
            }
        }
        inFile.close();

        // Lưu thông tin cuộc hẹn vào file appointments.txt
        ofstream outFile("appointments.txt", ios::app);
        if (!outFile) {
            cerr << "Error: Unable to open appointments.txt" << endl;
            return;
        }

        outFile << getName() << "," << getPhone() << "," << doctorName << "," << time << "," << date << "," << reason << endl;
        outFile.close();

        cout << "Appointment made successfully." << endl;
    }

    // Phương thức kiểm tra lịch sử cuộc hẹn của bệnh nhân
    void checkAppointmentHistory(const string& phoneNumber) {
        bool found = false;
        cout << "Appointment History for " << phoneNumber << ":" << endl;
        ifstream inFile("appointments.txt");
        if (!inFile) {
            cerr << "Error: Unable to open appointments.txt" << endl;
            return;
        }

        string line;
        while (getline(inFile, line)) {
            stringstream ss(line);
            string name, phone, doctorName, time, date, reason;
            if (getline(ss, name, ',') && getline(ss, phone, ',') && getline(ss, doctorName, ',') &&
                getline(ss, time, ',') && getline(ss, date, ',') && getline(ss, reason, ',')) {
                if (phone == phoneNumber) {
                    found = true;
                    cout <<"---------------------"<<endl;
                    cout << "Name: " << name <<endl;
                    cout << "Doctor: " << doctorName <<endl;
                    cout << "Time: " << time <<endl;
                    cout << "Date: " << date <<endl;
                    cout << "Reason: " << reason <<endl;
                }
            }
        }
        inFile.close();

        if (!found) {
            cout << "No appointment found for this phone number." << endl;
        }
    }

    // Phương thức hủy cuộc hẹn của bệnh nhân
    void cancelAppointment(const string& phoneNumber) {
        // Đọc dữ liệu từ tệp appointments.txt và kiểm tra số điện thoại
        ifstream inFile("appointments.txt");
        if (!inFile) {
            cerr << "Error: Unable to open appointments.txt" << endl;
            return;
        }

        vector<string> appointmentsForPhone;
        string line;
        while (getline(inFile, line)) {
            stringstream ss(line);
            string name, phone, doctorName, time, date, reason;
            if (getline(ss, name, ',') && getline(ss, phone, ',') && getline(ss, doctorName, ',') &&
                getline(ss, time, ',') && getline(ss, date, ',') && getline(ss, reason, ',')) {
                if (phone == phoneNumber) {
                    appointmentsForPhone.push_back(line);
                }
            }
        }
        inFile.close();

        if (appointmentsForPhone.empty()) {
            cout << "No appointment found for this phone number." << endl;
            return;
        }

        // Hiển thị danh sách cuộc hẹn theo thứ tự và cho phép người dùng chọn để hủy
        cout << "Appointment(s) for " << phoneNumber << ":" << endl;
        for (size_t i = 0; i < appointmentsForPhone.size(); ++i) {
            cout << i + 1 << ". " << appointmentsForPhone[i] << endl;
        }
        cout << "Enter the number of the appointment you want to cancel: ";
        int choice;
        cin >> choice;

        if (choice < 1 || choice > static_cast<int>(appointmentsForPhone.size())) {
            cout << "Invalid choice." << endl;
            return;
        } else {
            // Xóa cuộc hẹn cụ thể được chọn
            appointmentsForPhone.erase(appointmentsForPhone.begin() + choice - 1);
        }

        // Ghi lại các dòng còn lại vào tệp appointments.txt
        ofstream outFile("appointments.txt");
        if (!outFile) {
            cerr << "Error: Unable to open appointments.txt" << endl;
            return;
        }

        for (const string& remainingLine : appointmentsForPhone) {
            outFile << remainingLine << endl;
        }
        outFile.close();

        cout << "Appointment(s) canceled successfully." << endl;
    }

};

// Hàm nhập thông tin người đặt lịch hẹn
Patient enterPatientInfo() {
    string name, phone, address;
    int age;

    cout << "Enter patient information:" << endl;
    cout << "Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Phone: ";
    cin >> phone;
    cout << "Address: ";
    cin.ignore();
    getline(cin, address);
    cout << "Age: ";
    cin >> age;

    return Patient(name, phone, address, age);
}

// Hàm hiển thị danh sách bác sĩ từ file doctorlist.txt
void displayDoctorList() {
    ifstream inFile("doctorlist.txt");
    if (!inFile) {
        cerr << "Error: Unable to open doctorlist.txt" << endl;
        return;
    }

    cout << "Doctor List:" << endl;
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
}

int main() {
    // Đọc danh sách bác sĩ từ file doctorlist.txt
    ifstream inFile("doctorlist.txt");
    if (!inFile) {
        cerr << "Error: Unable to open doctorlist.txt" << endl;
        return 1;
    }

    vector<Doctor> doctors;
    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        string name, major;

        if (ss >> name >> major) {
            doctors.emplace_back(name, major);
        }
    }

    int choice;
    Patient patient("", "", "", 0);

    // Menu chương trình
    do {
        cout << "---------------------" << endl;
        cout << "1. Make an appointment" << endl;
        cout << "2. Check appointment history" << endl;
        cout << "3. Cancel an appointment" << endl;
        cout << "4. Display doctor list" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // Xử lý lựa chọn của người dùng
        switch(choice) {
            case 1: {
                // Nhập thông tin người đặt lịch hẹn
                Patient newPatient = enterPatientInfo();

                // Chọn bác sĩ từ danh sách
                cout << "Choose a doctor from the list:" << endl;
                for (size_t i = 1; i <= doctors.size(); ++i) {
                    cout << i << ". ";
                    doctors[i - 1].showInfo(i);
                }

                int doctorChoice;
                cout << "Enter your choice: ";
                cin >> doctorChoice;

                if (doctorChoice < 1 || doctorChoice > doctors.size()) {
                    cout << "Invalid choice. Please try again." << endl;
                    break;
                }

                Doctor selectedDoctor = doctors[doctorChoice - 1];

                // Nhập thông tin lịch hẹn
                string time, date, reason;
                cout << "Enter appointment details:" << endl;
                cout << "Time (HH:MM): ";
                cin >> time;
                cout << "Date (YYYY-MM-DD): ";
                cin >> date;
                cout << "Reason: ";
                cin.ignore();
                getline(cin, reason);

                // Thực hiện đặt lịch hẹn, truyền chỉ số của bác sĩ được chọn
                newPatient.makeAppointment(doctorChoice, time, date, reason);
                break;
            }

            case 2: {
                string phoneNumber;
                cout << "Enter patient's phone number to check appointment history: ";
                cin >> phoneNumber;
                patient.checkAppointmentHistory(phoneNumber);
                break;
            }
            case 3: {
                string phoneNumber;
                cout << "Enter patient's phone number to cancel appointment: ";
                cin >> phoneNumber;
                patient.cancelAppointment(phoneNumber);
                break;
            }
            case 4:
                displayDoctorList();
                break;
            case 5:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while(choice != 5);

    return 0;
}
