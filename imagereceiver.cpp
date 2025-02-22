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

        QString packetType;
        stream >> packetType;

        if (packetType == "CMD") {
            // Прием команды
            QString command;
            stream >> command;
            handleCommand(command);

        }
        else if (packetType == "IMG"){
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

            QImage image(reinterpret_cast<const uchar*>(imageData.constData()), rowSize / bytesPerPixel, totalRows, rowSize, QImage::Format_Grayscale8);

            if (!image.isNull()) {
                emit imageReceived(image);
            }

            imageFragments.clear();
        }
        }
        else {
            qDebug() << "Неизвестный тип пакета: " << packetType;
        }
    }
}

void ImageReceiver::handleCommand(const QString &command)
{
    if (command == "startCamera") {
        qDebug() << "Запуск камеры.";
        emit startCameraCommand();
    } else if (command == "stopCamera") {
        qDebug() << "Остановка камеры.";
        emit stopCameraCommand();
    } else if (command == "startDisplay") {
        qDebug() << "Запуск отображения.";
        emit startDisplayCommand();
    } else if (command == "stopDisplay") {
        qDebug() << "Остановка отображения.";
        emit stopDisplayCommand();
    } else {
        qDebug() << "Неизвестная команда: " << command;
    }
}
