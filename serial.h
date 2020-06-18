#ifndef SERIAL_H
#define SERIAL_H

#include <QSerialPort>
#include <QSerialPortInfo>

class Serial: QObject
{
public:
    Serial();

    void init();


<<<<<<< HEAD
public slots:
=======
protected slots:
>>>>>>> 57d7248e618a641e798b616652b30a0b724f834d

    void onReadyRead();



private:

    QSerialPort *m_pinRX = nullptr;
    QList<QSerialPortInfo> listPort;
    //QList <QSerialPort> m_listPort;
};

#endif // SERIAL_H
