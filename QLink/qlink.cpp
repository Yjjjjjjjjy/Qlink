#include "qlink.h"
#include "menu.h"



QLink::QLink(QWidget *parent)
    : QWidget(parent)
{
    Menu *menu = new Menu();
    background.load("D:/C++/sep/QLink/background.jpg");
    setWindowTitle(tr("QLink"));
    setFixedSize(1000,900);

    btn1 = new QPushButton(this);
    btn1->setText("Enter the Game");
    btn1->move(400,312);
    btn1->resize(200,100);

    btn2 = new QPushButton(this);
    btn2->setText("Quit");
    btn2->move(400,425);
    btn2->resize(200,50);

    connect(btn1,&QPushButton::clicked,[=](){
        this->hide();
        menu->show();
    });

    connect(btn2,SIGNAL(clicked()),this,SLOT(close()));
    connect(menu,&Menu::back,[=](){
        menu->hide();
        this->show();
    });





}



void QLink::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,width(),height(),background);
}

QLink::~QLink()
{
}

