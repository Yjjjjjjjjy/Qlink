#ifndef MAP_H
#define MAP_H
#include <QWidget>
#include<QPainter>
#include <stdio.h>
#include <time.h>
#include <QKeyEvent>
#include<QPushButton>
#include<QTimer>
#include<QMouseEvent>
#include<fstream>
#include<iostream>




#define WIDTH 10
#define HEIGHT 8
#define PICNUM 8

class Map: public QWidget
{
     Q_OBJECT
public:
    friend class Menu;
    friend class Document;
    Map();
    int data[WIDTH][HEIGHT];
    void Mapclear();
    void Mapcreat();
    bool Connect( int x1, int y1, int x2, int y2, int data[10][8] ) ;
    bool NoInfletion( int x1, int y1, int x2, int y2, int data[10][8] );
    bool OneInfletion( int x1, int y1, int x2, int y2, int data[10][8] );
    bool TwoInfletion( int x1, int y1, int x2, int y2, int data[10][8] );
    void wire( int x1, int y1, int x2, int y2 );
    void box( int x, int y );
    void Shuffle();
    void TimeRun();
    void Write();

protected:
     void paintEvent(QPaintEvent *event) override;
     void keyPressEvent(QKeyEvent *event) override;
     void mousePressEvent(QMouseEvent *event) override;

private:

      QTimer *timer;
      bool clicked = false;
      bool clicked2 = false;
      QPushButton *StopBtn;

      QPixmap p1,p2,p3,p4,p5,p6,p7,p8,p9;
      QPixmap pink;
      QPixmap p11;// shuffle
      QPixmap p10;//+30s
      QPixmap p13;//flash




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
      int second;
      int score = 0;



private slots:
      void Stop();




         /*void noinflection();
         void oneinflection();
         void twoinflection();*/




};

#endif // MAP_H
