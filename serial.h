#ifndef SERIAL_H
#define SERIAL_H

#include <QSerialPort>
#include <QSerialPortInfo>

class Serial: QObject
{
public:
    Serial();

    void init();


public slots:

    void onReadyRead();



private:

    QSerialPort *m_pinRX = nullptr;
    QList<QSerialPortInfo> listPort;
    //QList <QSerialPort> m_listPort;
};

#endif // SERIAL_H
