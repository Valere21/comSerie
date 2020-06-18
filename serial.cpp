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
        i++;
    }

    m_pinRX->setBaudRate(QSerialPort::Baud115200);
    m_pinRX->setDataBits(QSerialPort::Data8);
    m_pinRX->setStopBits(QSerialPort::OneStop);
    m_pinRX->setParity(QSerialPort::NoParity);
    m_pinRX->setFlowControl(QSerialPort::NoFlowControl);
    m_pinRX->open(QIODevice::ReadWrite);

    qDebug() << "init du port" << Q_FUNC_INFO;

    //connect(server, SIGNAL(newConnection()),this, SLOT(onNewConnection()));
    connect(m_pinRX, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    }

void Serial::onReadyRead(){

    qDebug() << "test du read" << Q_FUNC_INFO;

    qDebug() << m_pinRX->readAll();

}

