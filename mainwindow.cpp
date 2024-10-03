#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QCamera>
#include <QCameraViewfinder>
#include <QVBoxLayout>
#include <QBuffer>
#include <QDebug>
#include <QtGlobal>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , targetAddress("127.0.0.1")
    , targetPort(12345)
    , tempFrameNumber(0)
{
    ui->setupUi(this);

    ui->label->setScaledContents(false);

    ui->cameraButton->setCheckable(true);
    ui->cameraButton->setChecked(false);

    ui->displayButton->setCheckable(true);
    ui->displayButton->setChecked(false);

    ui->displayOFFButton->setChecked(true);
    ui->cameraOFFButton->setChecked(true);

    socket = new QUdpSocket(this);
    bool bindResult = socket->bind(QHostAddress::LocalHost, 12346);
    if (!bindResult) {
        qDebug() << "Ошибка привязки к порту";
    }
    connect(socket, &QUdpSocket::readyRead, this, &MainWindow::readPendingDatagrams);
}

MainWindow::~MainWindow()
{
    delete ui;
    socket->close();
}

void MainWindow::readPendingDatagrams() {
    while (socket->hasPendingDatagrams()) {
        QByteArray buffer;
        qint64 pendingSize = socket->pendingDatagramSize();
        if (pendingSize <= 0) {
            qDebug() << "Ошибка: некорректный размер ожидаемых данных:" << pendingSize;
            return;
        }
        buffer.resize(pendingSize);

        QHostAddress sender;
        quint16 senderPort;

        qint64 bytesRead = socket->readDatagram(buffer.data(), buffer.size(), &sender, &senderPort);
        if (bytesRead == -1) {
            qDebug() << "Ошибка при получении данных:" << socket->errorString();
            return;
        }

        QDataStream stream(&buffer, QIODevice::ReadOnly);
        quint16 frameNumber, totalRows, rowNumber, rowSize;
        quint8 bytesPerPixel, reserved;
        stream >> frameNumber >> totalRows >> rowNumber >> rowSize >> bytesPerPixel >> reserved;

        tempFrameNumber = frameNumber;

        QByteArray rowData;
        rowData.resize(rowSize);
        stream.readRawData(rowData.data(), rowSize);

        if (rowSize % bytesPerPixel != 0) {
            qDebug() << "Ошибка: некорректный размер строки данных.";
            return;
        }

        if (!imageFragments.contains(rowNumber)) {
            imageFragments.insert(rowNumber, rowData);
        }

        // Проверяем, все ли строки получены
        if (imageFragments.size() == totalRows) {
            // Создаем массив байтов для хранения всех строк изображения
            QByteArray imageData;

            // Собираем строки в единый массив
            for (int i = 0; i < totalRows; ++i) {
                if (imageFragments.contains(i)) {
                    imageData.append(imageFragments[i]);
                } else {
                    qDebug() << "Ошибка: отсутствует строка " << i;
                    return;
                }
            }

            // Создаем QImage из собранного массива байтов
            QImage image(reinterpret_cast<const uchar*>(imageData.constData()),
                         rowSize / bytesPerPixel,
                         totalRows,
                         rowSize, // stride (количество байт на строку)
                         QImage::Format_Grayscale8);  // Формат изображения

            if (image.isNull()) {
                qDebug() << "Ошибка: не удалось создать изображение из массива данных.";
                return;
            }

            // Отображение изображения
            QByteArray byteArray;
            QBuffer buffer(&byteArray);
            buffer.open(QIODevice::WriteOnly);

            // Сохраняем изображение в формат JPEG в byteArray
            if (!image.save(&buffer, "JPEG")) {
                qDebug() << "Ошибка: не удалось сохранить изображение в QByteArray.";
                return;
            }

            // Теперь передаем QByteArray в displayImage
            displayImage(byteArray);

            // Очистка после сборки
            imageFragments.clear();
        }
    }
}

void MainWindow::displayImage(const QByteArray &imageData) {
    QImage image;
    if (!image.loadFromData(imageData, "JPEG")) {
        qDebug() << "Ошибка: не удалось загрузить изображение из данных.";
        return;
    }
    if (!image.isNull()) {
        QSize labelSize = ui->label->size();
        QPixmap pixmap = QPixmap::fromImage(image).scaled(labelSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        ui->label->setPixmap(pixmap);
    } else {
        qDebug() << "Ошибка при загрузке изображения";
    }
}

void MainWindow::on_displayButton_clicked(bool checked)
{
    if(checked){
        ui->displayButton->setText("ТРАНСЛЯЦИЯ ВЫКЛ");
        sendCommand("startDisplay");
        ui->displayOFFButton->setChecked(false);
        ui->displayONButton->setChecked(true);
        ui->label->show();
    }
    else{
        ui->displayButton->setText("ТРАНСЛЯЦИЯ ВКЛ");
        sendCommand("stopDisplay");
        ui->displayOFFButton->setChecked(true);
        ui->displayONButton->setChecked(false);
        ui->label->hide();
    }

}


void MainWindow::on_cameraButton_clicked(bool checked)
{
    if(checked){
        ui->cameraButton->setText("КАМЕРА ВЫКЛ");
        sendCommand("startCamera");
        ui->cameraOFFButton->setChecked(false);
        ui->cameraONButton->setChecked(true);
        ui->label->show();
    }
    else{
        ui->cameraButton->setText("КАМЕРА ВКЛ");
        sendCommand("stopCamera");
        ui->cameraOFFButton->setChecked(true);
        ui->cameraONButton->setChecked(false);
        ui->label->hide();
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    struct Flags{
        unsigned int IsCamOn : 1;
        unsigned int IsDisOn : 1;
    };
    Flags flags;
    if(ui->cameraOFFButton->isChecked()){
        flags.IsCamOn = 0;
    }
    else{
        flags.IsCamOn = 1;
    }
    if(ui->displayOFFButton->isChecked()){
        flags.IsDisOn = 0;
    }
    else{
        flags.IsDisOn = 1;
    }
    QString message = QString("Статус камеры : %1.\nСтатус отображения : %2.\nВсего кадров передано : %3.").arg(flags.IsCamOn).arg(flags.IsDisOn).arg(tempFrameNumber);
    QMessageBox::information(this,"ИНФОРМАЦИЯ", message);
}

void MainWindow::sendCommand(const QString &command){
    QByteArray data = command.toUtf8();
    socket->writeDatagram(data,QHostAddress(targetAddress),targetPort);
}

