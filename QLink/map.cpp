#include "map.h"


Map::Map()
{

    setWindowTitle(tr("Enjoy the Game"));
    setFixedSize(1000,900);


    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    connect(timer,&QTimer::timeout,this,&Map::TimeRun);
    timer->start(1000);

    StopBtn = new QPushButton(this);    
    StopBtn->move(150,825);
    StopBtn->resize(200,50);
    StopBtn->setText("Stop");
    connect(StopBtn,SIGNAL(clicked()),this,SLOT(Stop()));


    p1.load("D:/C++/sep/QLink/1.jpg");
    p2.load("D:/C++/sep/QLink/2.jpg");
    p3.load("D:/C++/sep/QLink/3.jpg");
    p4.load("D:/C++/sep/QLink/4.jpg");
    p5.load("D:/C++/sep/QLink/5.jpg");
    p6.load("D:/C++/sep/QLink/6.jpg");
    p7.load("D:/C++/sep/QLink/7.jpg");
    p8.load("D:/C++/sep/QLink/8.jpg");
    p9.load("D:/C++/sep/QLink/9.jpg");
    pink.load("D:/C++/sep/QLink/pink.jpg");
    p10.load("D:/C++/sep/QLink/+1s.jpg");
    p11.load("D:/C++/sep/QLink/shuffle.jpg");
    p13.load("D:/C++/sep/QLink/flash.jpg");



    Mapclear();
    Mapcreat();
    data[0][0] = 9;


}

void Map::Stop()
{
    if( clicked == false )
    {
        StopBtn->setText("Continue");
        timer->stop();
        Write();
        clicked = true;
    }
    else if( clicked == true )
    {
        StopBtn->setText("Stop");
        timer->start();
        clicked = false;
    }
}

void Map::TimeRun()
{
    --second;
}

void Map::keyPressEvent(QKeyEvent *event)
{


    if(clicked)  return;
    if( second == 0) return;
    int flag = false;
    for(int i = 1; i < WIDTH - 1 ; ++i )
    {
        for(int j = 1; j < HEIGHT - 1; ++j)
        {
            if( data[i][j] != 0 && data[i][j] != 9 && data[i][j] != 10 && data[i][j] != 11 && data[i][j] != 13 )
            {
                flag = true;
                break;
            }
        }
    }
    if( !flag ) return;
    if(event->key() == Qt::Key_A)
    {
        if( x == 0 )
        {
            data[x][y] = 0;
            x = WIDTH - 1;
            data[x][y] = 9;
        }
        else if( data[x-1][y] == 0 )
        {
            data[x][y] = 0;
            --x;
            data[x][y] = 9;
        }
        else if( data[x-1][y] != 0 )
        {
            switch( num )
            {
            case 0:
                         if( data[x-1][y] == 10 )
                         {
                             second += 30;
                             data[x-1][y] = 0;
                             break;
                         }
                         if( data[x-1][y] == 11 )
                         {
                             data[x][y] = 0;
                             data[x-1][y] = 0;
                             Shuffle();
                             break;
                         }
                         if( data[x-1][y] == 13 )
                         {
                             data[x-1][y] = 0;
                             clicked2 = true;
                             break;
                         }
                         temp = data[x-1][y];
                         tempX = x-1;
                         tempY = y;
                         ++num;
                         break;
            case 1:
                         if( x-1 != tempX || y != tempY )
                            {
                                if( temp == data[x-1][y] && NoInfletion(x-1,y,tempX,tempY,data) )
                                {
                                    data[x-1][y] = 0;
                                    data[tempX][tempY] = 0;
                                    --num;
                                    ++score;
                                    //  noinflection();
                                    break;
                                }
                                if( temp == data[x-1][y] && OneInfletion(x-1,y,tempX,tempY,data) )
                                {
                                    data[x-1][y] = 0;
                                    data[tempX][tempY] = 0;
                                    --num;
                                    ++score;
                                    //  oneinflection();
                                    break;
                                }
                                if( temp == data[x-1][y] && TwoInfletion(x-1,y,tempX,tempY,data) )
                                {
                                    data[x-1][y] = 0;
                                    data[tempX][tempY] = 0;
                                    --num;
                                    ++score;
                                    //  twoinflection();
                                    break;
                                }
                                tempX = 0;
                                tempY = 0;
                                --num;
                            }

                            break;
            }

        }

    }



    if(event->key() == Qt::Key_D)
    {
        if( x == WIDTH - 1 )
        {
            data[x][y] = 0;
            x = 0;
            data[x][y] = 9;
        }
        else if( data[x+1][y] == 0 )
        {
            data[x][y] = 0;
            ++x;
            data[x][y] = 9;
        }
        else if( data[x+1][y] != 0 )
        {
            switch( num )
            {
            case 0:
                if( data[x+1][y] == 10 )
                {
                    second += 30;
                    data[x+1][y] = 0;
                    break;
                }
                if( data[x+1][y] == 11 )
                {
                    data[x][y] = 0;
                    data[x+1][y] = 0;
                    Shuffle();
                    break;
                }
                if( data[x+1][y] == 13 )
                {
                    data[x+1][y] = 0;
                    clicked2 = true;
                    break;
                }
                         temp = data[x+1][y];
                         tempX = x+1;
                         tempY = y;
                         ++num;
                         break;
            case 1:
                         if( x+1 != tempX || y != tempY )
                            {
                                if( temp == data[x+1][y] && NoInfletion(x+1,y,tempX,tempY,data) )
                                {
                                    data[x+1][y] = 0;
                                    data[tempX][tempY] = 0;
                                    --num;
                                    ++score;
                                    //  noinflection();
                                    break;
                                }
                                if( temp == data[x+1][y] && OneInfletion(x+1,y,tempX,tempY,data) )
                                {
                                    data[x+1][y] = 0;
                                    data[tempX][tempY] = 0;
                                    --num;
                                    ++score;
                                    //  oneinflection();
                                    break;
                                }
                                if( temp == data[x+1][y] && TwoInfletion(x+1,y,tempX,tempY,data) )
                                {
                                    data[x+1][y] = 0;
                                    data[tempX][tempY] = 0;
                                    --num;
                                    ++score;
                                    //  twoinflection();
                                    break;
                                }
                                tempX = 0;
                                tempY = 0;
                                --num;
                            }

                            break;
            }

        }

    }



    if(event->key() == Qt::Key_W)
    {
        if( y == 0 )
        {
            data[x][y] = 0;
            y = HEIGHT - 1;
            data[x][y] = 9;
        }
        else if( data[x][y-1] == 0 )
        {
            data[x][y] = 0;
            --y;
            data[x][y] = 9;
        }
        else if( data[x][y-1] != 0 )
        {
            switch( num )
            {
            case 0:
                if( data[x][y-1] == 10 )
                {
                    second += 30;
                    data[x][y-1] = 0;
                    break;
                }
                if( data[x][y-1] == 11 )
                {
                    data[x][y] = 0;
                    data[x][y-1] = 0;
                    Shuffle();
                    break;
                }
                if( data[x][y-1] == 13 )
                {
                    data[x][y-1] = 0;
                    clicked2 = true;
                    break;
                }
                         temp = data[x][y-1];
                         tempX = x;
                         tempY = y - 1;
                         ++num;
                         break;
            case 1:
                         if( x != tempX || y-1 != tempY )
                            {
                                if( temp == data[x][y-1] && NoInfletion(x,y-1,tempX,tempY,data) )
                                {
                                    data[x][y-1] = 0;
                                    data[tempX][tempY] = 0;
                                    --num;
                                    ++score;
                                    //  noinflection();
                                    break;
                                }
                                if( temp == data[x][y-1] && OneInfletion(x,y-1,tempX,tempY,data) )
                                {
                                    data[x][y-1] = 0;
                                    data[tempX][tempY] = 0;
                                    --num;
                                    ++score;
                                    //  oneinflection();
                                    break;
                                }
                                if( temp == data[x][y-1] && TwoInfletion(x,y-1,tempX,tempY,data) )
                                {
                                    data[x][y-1] = 0;
                                    data[tempX][tempY] = 0;
                                    --num;
                                    ++score;
                                    //  twoinflection();
                                    break;
                                }
                                tempX = 0;
                                tempY = 0;
                                --num;
                            }

                            break;
            }

        }

    }
    if(event->key() == Qt::Key_S)
    {
        if( y == HEIGHT - 1 )
        {
            data[x][y] = 0;
            y = 0;
            data[x][y] = 9;
        }
        else if( data[x][y+1] == 0 )
        {
            data[x][y] = 0;
            ++y;
            data[x][y] = 9;
        }
        else if( data[x][y+1] != 0 )
        {
            switch( num )
            {
            case 0:
                if( data[x][y+1] == 10 )
                {
                    second += 30;
                    data[x][y+1] = 0;
                    break;
                }
                if( data[x][y+1] == 11 )
                {
                    data[x][y] = 0;
                    data[x][y+1] = 0;
                    Shuffle();
                    break;
                }
                if( data[x][y+1] == 13 )
                {
                    data[x][y+1] = 0;
                    clicked2 = true;
                    break;
                }
                         temp = data[x][y+1];
                         tempX = x;
                         tempY = y + 1;
                         ++num;
                         break;
            case 1:
                         if( x != tempX || y+1 != tempY )
                            {
                                if( temp == data[x][y+1] && NoInfletion(x,y+1,tempX,tempY,data) )
                                {
                                    data[x][y+1] = 0;
                                    data[tempX][tempY] = 0;
                                    --num;
                                    ++score;
                                    //  noinflection();
                                    break;
                                }
                                if( temp == data[x][y+1] && OneInfletion(x,y+1,tempX,tempY,data) )
                                {
                                    data[x][y+1] = 0;
                                    data[tempX][tempY] = 0;
                                    --num;
                                    ++score;
                                    //  oneinflection();
                                    break;
                                }
                                if( temp == data[x][y+1] && TwoInfletion(x,y+1,tempX,tempY,data) )
                                {
                                    data[x][y+1] = 0;
                                    data[tempX][tempY] = 0;
                                    --num;
                                    ++score;
                                    //  twoinflection();
                                    break;
                                }
                                tempX = 0;
                                tempY = 0;
                                --num;
                            }
                            break;
            }

        }

    }
    update();
}

void Map::paintEvent(QPaintEvent *)
{

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);


    QFont font("Helvetica");
    font.setPixelSize(20);

    QPainter clock(this);
    clock.setFont(font);
    clock.drawText(800,840,QString::number(second));

    QPainter TextTime(this);
    TextTime.setFont(font);
    TextTime.drawText(700,840,"time:");

    QPainter Score(this);
    Score.setFont(font);
    Score.drawText(700,880,"score:");

    QPainter TextScore(this);
    TextScore.setFont(font);
    TextScore.drawText(800,880,QString::number(score));

    QPainter over(this);
    over.setFont(font);
    if( second == 0 )
    {
        timer->stop();
        over.drawText(400,860,"Game Over");
    }

    int flag = false;
    for(int i = 1; i < WIDTH - 1 ; ++i )
    {
        for(int j = 1; j < HEIGHT - 1; ++j)
        {
            if( data[i][j] != 0 && data[i][j] != 9 && data[i][j] != 10 && data[i][j] != 11 )
            {
                flag = true;
                break;
            }
        }
    }
    if( !flag )
    {
        timer->stop();
        over.drawText(400,860,"Game Over");
    }




    for(int i = 0 ; i < WIDTH ; ++i )
    {
        for( int j = 0 ; j < HEIGHT ; ++j )
        {
            switch ( data[i][j] )
            {
                case 0:painter.drawPixmap(100*i,100*j,width()/10,height()/8,pink);break;
                case 1:painter.drawPixmap(100*i,100*j,width()/10,height()/8,p1);break;
                case 2:painter.drawPixmap(100*i,100*j,width()/10,height()/8,p2);break;
                case 3:painter.drawPixmap(100*i,100*j,width()/10,height()/8,p3);break;
                case 4:painter.drawPixmap(100*i,100*j,width()/10,height()/8,p4);break;
                case 5:painter.drawPixmap(100*i,100*j,width()/10,height()/8,p5);break;
                case 6:painter.drawPixmap(100*i,100*j,width()/10,height()/8,p6);break;
                case 7:painter.drawPixmap(100*i,100*j,width()/10,height()/8,p7);break;
                case 8:painter.drawPixmap(100*i,100*j,width()/10,height()/8,p8);break;
                case 9:painter.drawPixmap(100*i,100*j,width()/10,height()/8,p9);break;
                case 10:painter.drawPixmap(100*i,100*j,width()/10,height()/8,p10);break;
                case 11:painter.drawPixmap(100*i,100*j,width()/10,height()/8,p11);break;
                case 13:painter.drawPixmap(100*i,100*j,width()/10,height()/8,p13);break;

            }
        }
    }
    if( tempX2 != 0 || tempY2 != 0 )
    {
        wire(tempX1,tempY1,tempX2,tempY2);
        if( tempX3 != 0 || tempY3 != 0 )
        {
            wire(tempX2,tempY2,tempX3,tempY3);
            if( tempX4 != 0 || tempY4 != 0 )
            {
                wire(tempX3,tempY3,tempX4,tempY4);
            }
        }
        tempX1 = tempX2 = tempX3 = tempY1 = tempY2 = tempY3 =  tempX4 = tempY4 = 0;
    }


    if( tempX != 0 && tempY != 0 )   box(tempX,tempY);

}

void Map::Mapclear()
{
    for( int i = 0 ; i < WIDTH ; ++i )
    {
        for( int j = 0 ; j < HEIGHT ; ++j )
        {
            data[i][j] = 0;
        }
    }
}

void Map::Mapcreat()
{
    srand( (unsigned)time( NULL ) );

    for( int i = 1 ; i < WIDTH - 1; ++i )
    {
        for( int j = 1 ; j < HEIGHT/2 ; ++j ) //0.0
        {
            data[i][j] = ( rand() % PICNUM ) + 1 ;
        }
    }
    for(int i = 1; i < WIDTH - 1; ++i )
    {
        for(int j = HEIGHT/2 ; j < HEIGHT - 1 ; ++j )
        {
            data[i][j] = data[i][j-3];
        }
    }

    data[2][2] = 10;
    data[2][5] = 11;
    data[3][2] = 13;
    data[3][5] = 13;
    Shuffle();

}

bool Map::Connect( int x1, int y1, int x2, int y2 , int data[10][8] )
{
    if( NoInfletion( x1, y1, x2, y2, data ) || OneInfletion( x1, y1, x2, y2, data) || TwoInfletion( x1, y1, x2, y2, data) )  return true;
    else return false;
}

bool Map::NoInfletion( int x1, int y1, int x2, int y2, int data[10][8] )
{
    bool flag = true;
    if( x1 == x2 )
    {
        for( int i = ( y1 > y2 ? y2 : y1 ) + 1; i < ( y1 > y2 ? y1 : y2 ); ++i )
            if( data[x1][i] != 0 && data[x1][i] != 9 )
            {
                flag = false;
                break;
            }
        if( flag == true )
        {
            tempX1 = x1;
            tempY1 = y1;
            tempX2 = x2;
            tempY2 = y2;
        }
        return flag;

    }

    if( y1 == y2 )
    {
        for( int i = ( x1 > x2 ? x2 : x1 ) + 1; i < ( x1 > x2 ? x1 : x2 ); ++i )
            if( data[i][y1] != 0 && data[i][y1] != 9 )
            {
                flag = false;
                break;
            }
        if( flag == true )
        {
            tempX1 = x1;
            tempY1 = y1;
            tempX2 = x2;
            tempY2 = y2;
        }
        return flag;
    }

    return false;
}

bool Map::OneInfletion( int x1, int y1, int x2, int y2, int data[10][8] )
{
    if( ( data[x1][y2] == 0 || data[x1][y2] == 9 ) && NoInfletion( x1, y1, x1, y2, data ) && NoInfletion( x2, y2, x1, y2, data ) )
        {
           tempX1 = x1;
           tempY1 = y1;
           tempX2 = x1;
           tempY2 = y2;
           tempX3 = x2;
           tempY3 = y2;
           return true;
         }
    if( ( data[x2][y1] == 0 || data[x2][y1] == 9 ) && NoInfletion( x1, y1, x2, y1, data ) && NoInfletion( x2, y2, x2, y1, data ) )
    {
        tempX1 = x1;
        tempY1 = y1;
        tempX2 = x2;
        tempY2 = y1;
        tempX3 = x2;
        tempY3 = y2;
        return true;
    }
    return false;
}

bool Map::TwoInfletion( int x1, int y1, int x2, int y2, int data[10][8] )
{
    if( x1 == x2 || y1 == y2 )
    {
        if( x1 == x2 )
        {
            int x = x1, y = y1;
            while( x > 0 && x < WIDTH-1 && y > 0 && y < HEIGHT-1 )
            {
                --x;
                if( data[x][y] != 0 && data[x][y] != 9 ) break;
                if( NoInfletion(x,y,x,y2,data) && ( data[x][y2] == 0 || data[x][y2] == 9 ) && NoInfletion(x,y2,x2,y2,data) )
                {
                    tempX1 = x1;
                    tempY1 = y1;
                    tempX2 = x;
                    tempY2 = y;
                    tempX3 = x;
                    tempY3 = y2;
                    tempX4 = x2;
                    tempY4 = y2;
                    return true;
                }
            }
            x = x1, y = y1;
            while( x > 0 && x < WIDTH-1 && y > 0 && y < HEIGHT-1 )
            {
                ++x;
                if( data[x][y] != 0 && data[x][y] != 9 ) break;
                if( NoInfletion(x,y,x,y2,data) && ( data[x][y2] == 0 || data[x][y2] == 9 ) && NoInfletion(x,y2,x2,y2,data) )
                {
                    tempX1 = x1;
                    tempY1 = y1;
                    tempX2 = x;
                    tempY2 = y;
                    tempX3 = x;
                    tempY3 = y2;
                    tempX4 = x2;
                    tempY4 = y2;
                    return true;
                }
            }
        }
        if( y1 == y2 )
        {
            int x = x1, y = y1;
             while( x > 0 && x < WIDTH-1 && y > 0 && y < HEIGHT-1 )
             {
                 --y;
                 if( data[x][y] != 0 && data[x][y] != 9 ) break;
                 if( NoInfletion(x,y,x2,y,data) && ( data[x2][y] == 0 || data[x2][y] == 9 ) && NoInfletion(x2,y,x2,y2,data) )
                 {
                     tempX1 = x1;
                     tempY1 = y1;
                     tempX2 = x;
                     tempY2 = y;
                     tempX3 = x2;
                     tempY3 = y;
                     tempX4 = x2;
                     tempY4 = y2;
                     return true;
                 }
             }
             x = x1, y = y1;
             while( x > 0 && x < WIDTH-1 && y > 0 && y < HEIGHT-1 )
             {
                 ++y;
                 if( data[x][y] != 0 && data[x][y] != 9 ) break;
                 if( NoInfletion(x,y,x2,y,data) && ( data[x2][y] == 0 || data[x2][y] == 9 ) && NoInfletion(x2,y,x2,y2,data) )
                 {
                     tempX1 = x1;
                     tempY1 = y1;
                     tempX2 = x;
                     tempY2 = y;
                     tempX3 = x2;
                     tempY3 = y;
                     tempX4 = x2;
                     tempY4 = y2;
                     return true;
                 }
             }
        }
    }

    else
    {
    int x = x1, y = y1;
    while( x > 0 && x < WIDTH-1 && y > 0 && y < HEIGHT-1 )
    {
        --x;
        if( data[x][y] != 0 && data[x][y] != 9) break;
        if( NoInfletion(x,y,x,y2,data) && ( data[x][y2] == 0 || data[x][y2] == 9 ) && NoInfletion(x,y2,x2,y2,data) )
        {
            tempX1 = x1;
            tempY1 = y1;
            tempX2 = x;
            tempY2 = y;
            tempX3 = x;
            tempY3 = y2;
            tempX4 = x2;
            tempY4 = y2;
            return true;
        }
    }
    x = x1, y = y1;
    while( x > 0 && x < WIDTH-1 && y > 0 && y < HEIGHT-1 )
    {
        ++x;
        if( data[x][y] != 0 && data[x][y] != 9 ) break;
        if( NoInfletion(x,y,x,y2,data) && ( data[x][y2] == 0 || data[x][y2] == 9 ) && NoInfletion(x,y2,x2,y2,data) )
        {
            tempX1 = x1;
            tempY1 = y1;
            tempX2 = x;
            tempY2 = y;
            tempX3 = x;
            tempY3 = y2;
            tempX4 = x2;
            tempY4 = y2;
            return true;
        }
    }
     x = x1, y = y1;
     while( x > 0 && x < WIDTH-1 && y > 0 && y < HEIGHT-1 )
     {
         --y;
         if( data[x][y] != 0 && data[x][y] != 9 ) break;
         if( NoInfletion(x,y,x2,y,data) && ( data[x2][y] == 0 || data[x2][y] == 9 ) && NoInfletion(x2,y,x2,y2,data) )
         {
             tempX1 = x1;
             tempY1 = y1;
             tempX2 = x;
             tempY2 = y;
             tempX3 = x2;
             tempY3 = y;
             tempX4 = x2;
             tempY4 = y2;
             return true;
         }
     }
     x = x1, y = y1;
     while( x > 0 && x < WIDTH-1 && y > 0 && y < HEIGHT-1 )
     {
         ++y;
         if( data[x][y] != 0 && data[x][y] != 9) break;
         if( NoInfletion(x,y,x2,y,data) && ( data[x2][y] == 0 || data[x2][y] == 9 ) && NoInfletion(x2,y,x2,y2,data) )
         {
             tempX1 = x1;
             tempY1 = y1;
             tempX2 = x;
             tempY2 = y;
             tempX3 = x2;
             tempY3 = y;
             tempX4 = x2;
             tempY4 = y2;
             return true;
         }
     }

    }


    return false;
}

void Map::box(int x, int y)
{
    QPainter paint(this);
    QPen pen;
    pen.setColor(Qt::green);
    paint.setPen(pen);
    paint.drawRect(x*100,y*100,100,100);
}

void Map::wire(int x1, int y1, int x2, int y2)
{
    x1 = x1 * 100 + 50;
    x2 = x2 * 100 + 50;
    y1 = y1 * 100 + 50;
    y2 = y2 * 100 + 50;
    QPainter paint(this);
    paint.setPen(Qt::red);
    paint.drawLine(x1,y1,x2,y2);

}

void Map::Shuffle()
{
    x = y = 0;
    data[0][0] = 9;
    srand((unsigned)time(NULL));
    for(int i = 1; i < WIDTH - 1; ++i )
    {
        for(int j = 1; j < HEIGHT - 1; ++j )
        {            
            int x0 = rand() % 8 + 1;
            int y0 = rand() % 6 + 1;
            std::swap(data[i][j],data[x0][y0]);
        }
    }

}

void Map::mousePressEvent(QMouseEvent *event)
{
    if( second == 0) return;
    if(!clicked2)  return;
    int flag = false;
    for(int i = 1; i < WIDTH - 1 ; ++i )
    {
        for(int j = 1; j < HEIGHT - 1; ++j)
        {
            if( data[i][j] != 0 && data[i][j] != 9 && data[i][j] != 10 && data[i][j] != 11 && data[i][j] != 13 )
            {
                flag = true;
                break;
            }
        }
    }
    if( !flag ) return;

    if(event->button()==Qt::LeftButton)
    {
        x=(event->x())/100;
        y=(event->y())/100;
    }
    if( data[x][y] == 0 )
    {
        for( int i = 0; i < WIDTH; ++i )
        {
            for( int j = 0; j < HEIGHT; ++j )
            {
                if( data[i][j] == 9 ) data[i][j] = 0;
            }
        }
        data[x][y] = 9;
    }
    clicked2 = false;
    update();

}

void Map::Write()
{
    std::ofstream outfile("Game.txt",std::ios::trunc);
    if(outfile.is_open())
    {
        for( int i = 0; i < WIDTH ; ++i )
        {
            for( int j = 0; j < HEIGHT ; ++ j )
            {
                outfile << data[i][j] << " ";
            }
        }
        outfile << std::endl;
        outfile << x << " " << y << " " << second <<" "<< score;
    }

}
