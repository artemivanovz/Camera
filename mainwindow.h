#ifndef MAINWINDOW_H
#define MAINWINDOW_H
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

//    void on_pushButton_clicked(bool checked);
    void readPendingDatagrams();

    void on_displayButton_clicked(bool checked);

    void on_cameraButton_clicked(bool checked);

    void on_pushButton_3_clicked();

    void sendCommand(const QString &comand);

private:
    Ui::MainWindow *ui;
    QUdpSocket *udpSocket;
    QLabel *imageLabel;
    QString targetAddress;
    quint16 targetPort;
    QUdpSocket *socket;
    QMap<int, QByteArray> imageFragments;
    int tempFrameNumber;
    void displayImage(const QByteArray &imageData);
};
#endif
