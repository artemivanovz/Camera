#ifndef IMAGERECEIVER_H
#define IMAGERECEIVER_H

#include <QObject>
#include <QUdpSocket>
#include <QImage>
#include <QMap>

class ImageReceiver : public QObject {
    Q_OBJECT

public:
    explicit ImageReceiver(QObject *parent = nullptr);
    void bindSocket(const QHostAddress &address, quint16 port);
    QImage receiveImage();
    QUdpSocket* getSocket() const;
    int getFrameNumber();

signals:
    void imageReceived(const QByteArray &imageData);

private slots:
    void onReadyRead();

private:
    QUdpSocket *socket;
    QMap<int, QByteArray> imageFragments;
    int tempFrameNumber;
};

#endif // IMAGERECEIVER_H
