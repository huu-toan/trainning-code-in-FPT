#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QThread>
#include <chrono>
#include <thread>

// Các hàm giả lập từ đoạn mã gốc
bool HAL_GPIO_ReadPin(int pin) {
    // Giả lập trạng thái của nút bấm
    return false;
}

void HAL_GPIO_WritePin(int pin, bool state) {
    // Giả lập ghi trạng thái của nút bấm
}

class MyCarWidget : public QWidget {
public:
    MyCarWidget(QWidget *parent = nullptr) : QWidget(parent) {
        layout = new QVBoxLayout(this);
        label = new QLabel("Clock time: 0", this);
        layout->addWidget(label);
        setLayout(layout);

        connect(&timer, &QTimer::timeout, this, &MyCarWidget::updateClock);
        timer.start(1000); // Cập nhật mỗi giây
    }

    void updateClock() {
        // Cập nhật thời gian
        static int second = 0;
        label->setText("Clock time: " + QString::number(++second));
    }

private:
    QVBoxLayout *layout;
    QLabel *label;
    QTimer timer;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MyCarWidget widget;
    widget.show();

    return app.exec();
}
