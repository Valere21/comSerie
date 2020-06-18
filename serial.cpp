#include "serial.h"
#include "QtDebug"
Serial::Serial()
{

}

void Serial::init(){
    // /dev/ttyAMA0 ou /dev/ttyS0


    m_pinRX = new QSerialPort(listPort.at(1));


    m_pinRX->setBaudRate(QSerialPort::Baud115200);
    m_pinRX->setDataBits(QSerialPort::Data8);
    m_pinRX->setStopBits(QSerialPort::OneStop);
    m_pinRX->setParity(QSerialPort::NoParity);
    m_pinRX->setFlowControl(QSerialPort::NoFlowControl);
    m_pinRX->open(QIODevice::ReadWrite);

    listPort = QSerialPortInfo::availablePorts();
    int i = 0;
    qDebug() << "ListSize: " << listPort.size();

    while (i < listPort.size()){

        qDebug() << listPort.at(i).portName();
        i++;
    }

    qDebug() << m_pinRX->readAll();
}

// QString portName = "";
// m_pinRX->setParity()
//  m_pinRX->setPort(listPort.at(5));
//  m_pinRX->open(QSerialPort::Input);


