#include "imagereceiver.h"
#include <QDataStream>
#include <QBuffer>
#include <QDebug>

ImageReceiver::ImageReceiver(QObject *parent) : QObject(parent), socket(new QUdpSocket(this)), tempFrameNumber(0) {
    connect(socket, &QUdpSocket::readyRead, this, &ImageReceiver::onReadyRead);
}

void ImageReceiver::bindSocket(const QHostAddress &address, quint16 port) {
    bool bindResult = socket->bind(address, port);
    if (!bindResult) {
        qDebug() << "Ошибка привязки к порту";
    }
}

QUdpSocket* ImageReceiver::getSocket() const {
    return socket;
}

int ImageReceiver::getFrameNumber(){
    return tempFrameNumber;
}

void ImageReceiver::onReadyRead() {
    while (socket->hasPendingDatagrams()) {
        QByteArray buffer;
        buffer.resize(socket->pendingDatagramSize());
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

        if (imageFragments.size() == totalRows) {
            QByteArray imageData;
            QByteArray blackRow(rowSize, 0);

            for (int i = 0; i < totalRows; ++i) {
                if (imageFragments.contains(i)) {
                    imageData.append(imageFragments[i]);
                } else {
                    imageData.append(blackRow);
                }
            }

            QImage image(reinterpret_cast<const uchar*>(imageData.constData()), rowSize / bytesPerPixel, totalRows, rowSize, QImage::Format_RGB32);

            QByteArray byteArray;
            QBuffer buffer(&byteArray);
            buffer.open(QIODevice::WriteOnly);

            if (!image.save(&buffer, "JPEG")) {
                qDebug() << "Ошибка: не удалось сохранить изображение в QByteArray.";
                return;
            }


            if (!image.isNull()) {
                emit imageReceived(byteArray);
            }

            imageFragments.clear();
        }
    }
}
