#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include<QPushButton>
#include<QPainter>


class Menu: public QWidget
{
    Q_OBJECT
public:
    Menu();
protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QPushButton *button1;
    QPushButton *button2;
    QPushButton *button3;
    QPushButton *button4;
    QPixmap background;
signals:
    void back();
};

#endif // MENU_H
