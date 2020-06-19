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

    // m_msg = m_pinRX->readAll();


    /*for (int i = 0; i < m_msg.size(); i++){
        m_msgAll.append(m_msg.at(i));
        if (m_msg.at(i) == '\0'){
            m_pinRX->close();
            break;*/

    char size = 64;
    m_pinRX->setReadBufferSize(size);

    while (m_pinRX->bytesAvailable()) {

        while (m_flag == false){
            m_msg = m_pinRX->readAll();
            m_msgAll.append(m_msg);

            qDebug() << "boucle while de lecture";

            if (m_msg == "\0"){

                qDebug() << "détection du caractère de fin de chaine";
                m_msgAll.append(m_msg);
                m_flag = !m_flag;
                qDebug() << m_msgAll;

            }
        }
    }

}

//m_pinRX->waitForReadyRead();
// m_pinRX->setDataBits(size);
//QString::fromStdString(msg.toStdString());
//Serial::se
//QString allMsg;


