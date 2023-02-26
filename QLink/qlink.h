#ifndef QLINK_H
#define QLINK_H

#include <QWidget>
#include<QPainter>
#include<QPushButton>


class QLink : public QWidget
{
    Q_OBJECT

public:
    QLink(QWidget *parent = nullptr);
    ~QLink();
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    QPixmap background;
    QPushButton *btn1;
    QPushButton *btn2;


};
#endif // QLINK_H
