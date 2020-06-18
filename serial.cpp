#include "serial.h"
#include "QtDebug"
Serial::Serial()
{

}
void Serial::init(){
    // /dev/ttyAMA0 ou /dev/ttyS0


    listPort = QSerialPortInfo::availablePorts();
    qDebug() << "ListSize: " << listPort.size();
    m_pinRX = new QSerialPort(listPort.at(0));

    //m_pinRX = new QSerialPort();

    int i = 0;
    while (i < listPort.size()){
        qDebug() << m_pinRX->readAll();
    }

    m_pinRX->setBaudRate(QSerialPort::Baud115200);
    m_pinRX->setDataBits(QSerialPort::Data8);
    m_pinRX->setStopBits(QSerialPort::OneStop);
    m_pinRX->setParity(QSerialPort::NoParity);
    m_pinRX->setFlowControl(QSerialPort::NoFlowControl);
    m_pinRX->open(QIODevice::ReadWrite);

    qDebug() << "init du port" << Q_FUNC_INFO;
 //   listPort.append(QSerialPortInfo::availablePorts());

        //qDebug() << "test while" << listPort.at(i).portName();
        /*if (listPort.at(i).isNull()){
            qDebug() << "port null" << listPort.at(i).portName();
        else if (listPort.at(i).isNull() != listPort.at(i).isNull()){*/

        i++;
    }

