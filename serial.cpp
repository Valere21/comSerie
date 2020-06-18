#include "serial.h"
#include "QtDebug"
Serial::Serial()
{

}

void Serial::init(){
    // /dev/ttyAMA0 ou /dev/ttyS0


    //m_pinRX = new QSerialPort(listPort.at(1));
    m_pinRX = new QSerialPort();

    m_pinRX->setBaudRate(QSerialPort::Baud115200);
    m_pinRX->setDataBits(QSerialPort::Data8);
    m_pinRX->setStopBits(QSerialPort::OneStop);
    m_pinRX->setParity(QSerialPort::NoParity);
    m_pinRX->setFlowControl(QSerialPort::NoFlowControl);
    m_pinRX->open(QIODevice::ReadWrite);

 //   listPort.append(QSerialPortInfo::availablePorts());
    listPort = QSerialPortInfo::availablePorts();

    int i = 0;
    qDebug() << "ListSize: " << listPort.size();

    while (i < listPort.size()){

        qDebug() << "test while" << Qt::endl << listPort.at(i).portName();
        if (listPort.at(i).isNull()){
            qDebug() << "port null" << listPort.at(i).portName();
        }
        else if (listPort.at(i).isNull() != listPort.at(i).isNull()){
            qDebug() << m_pinRX->readAll();
        }
        i++;
    }
}


