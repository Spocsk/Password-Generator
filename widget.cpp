#include "widget.h"
#include "ui_widget.h"
#include <QString>
#include <QDebug>
#include <QRandomGenerator64>
#include <QTimer>

Widget::Widget(QWidget *parent): QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    timer->start(100);

    const QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
    std::uniform_int_distribution<int> distribution(0,possibleCharacters.size());

    int taille_pass = 12;
    QString password;

    for(int i=0; i<taille_pass;i++)
    {
        int value = distribution(*QRandomGenerator::global());
        int index = value % possibleCharacters.length();
        QChar nextChar = possibleCharacters.at(index);

        password.append(nextChar);
    }
    qDebug() << password;
}

void Widget::update(){

    ui->progressBar->setValue(ui->horizontalSlider->value());
    //ui->progressBar->setPalette()

}
