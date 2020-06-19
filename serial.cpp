#include "serial.h"
#include "QtDebug"
Serial::Serial()
{
    init();
}
void Serial::init(){
    // /dev/ttyAMA0 ou /dev/ttyS0
    
    
    m_listPort = QSerialPortInfo::availablePorts();
    qDebug() << "ListSize: " << m_listPort.size();
    m_pinRX = new QSerialPort(m_listPort.at(1));
    
    //m_pinRX = new QSerialPort();
    
    int i = 0;
    while (i < m_listPort.size()){
        i++;
    }
    
    m_pinRX->setBaudRate(QSerialPort::Baud115200);
    m_pinRX->setDataBits(QSerialPort::Data8);
    m_pinRX->setStopBits(QSerialPort::OneStop);
    m_pinRX->setParity(QSerialPort::NoParity);
    m_pinRX->setFlowControl(QSerialPort::NoFlowControl);
    m_pinRX->open(QIODevice::ReadWrite);
    if (m_pinRX->isOpen() == true){
        qDebug() << "Ouverture de port";
    }
    else {
        qDebug() << "Problème d'ouverture de port";
    }
    qDebug() << "init du port" << Q_FUNC_INFO;
    
    //connect(server, SIGNAL(newConnection()),this, SLOT(onNewConnection()));
    connect(m_pinRX, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
}

void Serial::onReadyRead(){
    
    qDebug() << "test du read" << Q_FUNC_INFO;
    char size = 8;
    m_pinRX->setReadBufferSize(size);
    
    while (m_pinRX->bytesAvailable()) {
        QByteArray msg;
        QByteArray msgAll;
        
        while (msg.contains('\0') !=msg.contains('\0')){
            msg = m_pinRX->readAll();
            msgAll.append(msg);
        }
        qDebug() << msgAll;
    }
}

//m_pinRX->waitForReadyRead();
// m_pinRX->setDataBits(size);
//QString::fromStdString(msg.toStdString());
//Serial::se
//QString allMsg;


