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
#include <QSizePolicy>

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

    QSizePolicy sp_retain = ui->label->sizePolicy();
    sp_retain.setRetainSizeWhenHidden(true);
    ui->label->setSizePolicy(sp_retain);

    targetAddress = configManager->getTargetAddress();
    targetPort = configManager->getTargetPort();

    connect(imageReceiver, &ImageReceiver::imageReceived, this, &MainWindow::displayImage);
    connect(imageReceiver, &ImageReceiver::startCameraCommand, this, &MainWindow::startCamera);
    connect(imageReceiver, &ImageReceiver::stopCameraCommand, this, &MainWindow::stopCamera);
    connect(imageReceiver, &ImageReceiver::startDisplayCommand, this, &MainWindow::startDisplay);
    connect(imageReceiver, &ImageReceiver::stopDisplayCommand, this, &MainWindow::stopDisplay);

    imageReceiver->bindSocket(QHostAddress::Any, 12346);
}

MainWindow::~MainWindow()
{
    delete ui;
    socket->close();
}

void MainWindow::displayImage(const QImage &image) {
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

void MainWindow::startCamera(){
    ui->cameraButton->setChecked(true);
    ui->cameraButton->setText("КАМЕРА ВЫКЛ");
    ui->cameraOFFButton->setChecked(false);
    ui->cameraONButton->setChecked(true);
    ui->label->show();
}

void MainWindow::stopCamera(){
    ui->cameraButton->setChecked(false);
    ui->cameraButton->setText("КАМЕРА ВКЛ");
    ui->cameraOFFButton->setChecked(true);
    ui->cameraONButton->setChecked(false);
    ui->label->hide();
    tempFrameNumber = 0;
}

void MainWindow::startDisplay(){
    ui->displayButton->setChecked(true);
    ui->displayButton->setText("ТРАНСЛЯЦИЯ ВЫКЛ");
    ui->displayOFFButton->setChecked(false);
    ui->displayONButton->setChecked(true);
    ui->label->show();
}

void MainWindow::stopDisplay(){
    ui->displayButton->setChecked(false);
    ui->displayButton->setText("ТРАНСЛЯЦИЯ ВКЛ");
    ui->displayOFFButton->setChecked(true);
    ui->displayONButton->setChecked(false);
    tempFrameNumber = 0;
}
