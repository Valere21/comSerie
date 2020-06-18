#ifndef SERIAL_H
#define SERIAL_H

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QObject>

class Serial: public QObject

{
    Q_OBJECT


public:
    Serial();

    void init();


public slots:

    void onReadyRead();



private:

    QSerialPort *m_pinRX = nullptr;
    QList<QSerialPortInfo> m_listPort;
    //QList <QSerialPort> m_listPort;
};

#endif // SERIAL_H
