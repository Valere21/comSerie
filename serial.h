#ifndef SERIAL_H
#define SERIAL_H

#include <QSerialPort>
#include <QSerialPortInfo>

class Serial
{
public:
    Serial();

    void init();

private:

    QSerialPort *m_pinRX;
    QList<QSerialPortInfo> listPort;

};

#endif // SERIAL_H
