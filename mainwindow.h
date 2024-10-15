#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "imagereceiver.h"
#include "configmanager.h"
#include <QMainWindow>
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QMainWindow>
#include <QUdpSocket>
#include <QHostAddress>
#include <QLabel>
#include <QMap>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_displayButton_clicked(bool checked);
    void on_cameraButton_clicked(bool checked);
    void on_pushButton_3_clicked();
    void sendCommand(const QString &comand);
    void displayImage(const QByteArray &imageData);

private:
    Ui::MainWindow *ui;
    QUdpSocket *udpSocket;
    QLabel *imageLabel;
    QUdpSocket *socket;
    ImageReceiver *imageReceiver;
    ConfigManager *configManager;

    static QString targetAddress;
    static quint16 targetPort;
    QMap<int, QByteArray> imageFragments;
    int tempFrameNumber;

};
#endif
