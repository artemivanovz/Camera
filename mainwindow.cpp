#include "mainwindow.h"
#include "imagereceiver.h"
#include "./ui_mainwindow.h"
#include <QCamera>
#include <QCameraViewfinder>
#include <QVBoxLayout>
#include <QBuffer>
#include <QDebug>
#include <QtGlobal>
#include <QMessageBox>

QString MainWindow::targetAddress = "";
quint16 MainWindow::targetPort = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , imageReceiver(new ImageReceiver(this))
    , configManager(new ConfigManager(this))
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

    ui->label->setScaledContents(false);

    targetAddress = configManager->getTargetAddress();
    targetPort = configManager->getTargetPort();

    connect(imageReceiver, &ImageReceiver::imageReceived, this, &MainWindow::displayImage);

    imageReceiver->bindSocket(QHostAddress::LocalHost, 12346);
}

MainWindow::~MainWindow()
{
    delete ui;
    socket->close();
}

void MainWindow::displayImage(const QImage &image) {
    // QImage image;
    // if (!image.loadFromData(imageData, "JPEG")) {
    //     qDebug() << "Ошибка: не удалось загрузить изображение из данных.";
    //     return;
    // }
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
        tempFrameNumber = 0;
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
        tempFrameNumber = 0;
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    QString message = QString("Статус камеры : %1.\nСтатус отображения : %2.\nВсего кадров передано : %3.").arg(ui->cameraButton->isChecked() ? "Вкл" : "Выкл")
                          .arg(ui->displayButton->isChecked() ? "Вкл" : "Выкл")
                          .arg(imageReceiver->getFrameNumber());
    QMessageBox::information(this,"ИНФОРМАЦИЯ", message);
}

void MainWindow::sendCommand(const QString &command){
    QUdpSocket *commandSocket = imageReceiver->getSocket();
    QByteArray data = command.toUtf8();
    commandSocket->writeDatagram(data,QHostAddress(targetAddress),targetPort);
}
