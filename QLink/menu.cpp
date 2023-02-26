#include "menu.h"
#include "map.h"
#include "map2.h"


Menu::Menu()
{

    Map *map = new Map;
    Map2 *map2 = new Map2;
    background.load("D:/C++/sep/QLink/background.jpg");
    setWindowTitle(tr("Menu"));
    setFixedSize(1000,900);
    button1 = new QPushButton(this);
    button2 = new QPushButton(this);
    button3 = new QPushButton(this);
    button4 = new QPushButton(this);

    button1->setText("Double Game");
    button2->setText("Solitaire Game");
    button3->setText("Continue");
    button4->setText("Return");

    button1->move(200,275);
    button2->move(200,200);
    button3->move(200,350);
    button4->move(200,425);

    button1->resize(200,50);
    button2->resize(200,50);
    button3->resize(200,50);
    button4->resize(200,50);


    connect(button2,&QPushButton::clicked,[=]()
    {
       this->hide();
       map->second = 10;
       map->show();
       });
    connect(button1,&QPushButton::clicked,[=]()
    {
        this->hide();
        map2->second = 60;
        map2->show();
    });

    connect(button4,&QPushButton::clicked,[=](){
        emit this->back();




    });
}

void Menu::paintEvent(QPaintEvent *)
{

    QPainter painter(this);
    painter.drawPixmap(0,0,width(),height(),background);

}
