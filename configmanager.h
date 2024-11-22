#ifndef CONFIGMANAGER_H
#define CONFIGMANAGER_H

#include <QObject>
#include <QString>
#include <QSettings>

class ConfigManager : public QObject
{
    Q_OBJECT

public:
    explicit ConfigManager(QObject *parent = nullptr);

    QString getTargetAddress() const;
    quint16 getTargetPort() const;

private:
    QSettings *settings;

    QString targetAddress;
    quint16 targetPort;

    void loadConfig();
};

#endif // CONFIGMANAGER_H

