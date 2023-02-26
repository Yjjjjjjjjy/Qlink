#ifndef MAP2_H
#define MAP2_H

#include <QWidget>
#include<QPainter>
#include <stdio.h>
#include <time.h>
#include <QKeyEvent>
#include<QPushButton>
#include<QTimer>



#define WIDTH 10
#define HEIGHT 8
#define PICNUM 8


class Map2:public QWidget
{
     Q_OBJECT
public:
    friend class Menu;
    Map2();
    int data[WIDTH][HEIGHT];
    void Mapclear();
    void Mapcreat();
    bool Connect( int x1, int y1, int x2, int y2, int data[10][8] ) ;
    bool NoInfletion( int x1, int y1, int x2, int y2, int data[10][8] );
    bool OneInfletion( int x1, int y1, int x2, int y2, int data[10][8] );
    bool TwoInfletion( int x1, int y1, int x2, int y2, int data[10][8] );
    void wire( int x1, int y1, int x2, int y2 );
    void box1( int x, int y );
    void box2( int x, int y );
    void Shuffle();
    void timeRun();


private slots:
      void Stop();

protected:
     void paintEvent(QPaintEvent *event) override;
     void keyPressEvent(QKeyEvent *event) override;

private:


      bool clicked = false;    
      QPushButton *StopBtn;

      QPixmap p1,p2,p3,p4,p5,p6,p7,p8,p9;
      QPixmap pink;
      QPixmap p12;

      int second;
      int x = 0;
      int y = 0;    
      int temp = 0;
      int num = 0;
      int tempX = 0;
      int tempY = 0;
      int tempX1 = 0;
      int tempY1 = 0;
      int tempX2 = 0;
      int tempY2 = 0;
      int tempX3 = 0;
      int tempY3 = 0;
      int tempX4 = 0;
      int tempY4 = 0;

      int x2 = WIDTH - 1;
      int y2 = HEIGHT -1;
      int temp2 = 0;
      int num2 = 0;
      int tempXX = 0;
      int tempYY = 0;

      int score1 = 0;
      int score2 = 0;
      QTimer *timer;


};

#endif // MAP2_H
