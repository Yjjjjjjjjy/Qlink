#include "map2.h"

Map2::Map2()
{

    setWindowTitle(tr("Enjoy the Game"));
    setFixedSize(1000,900);



    timer = new QTimer(this);
    connect(timer,&QTimer::timeout, this,&Map2::timeRun);
    connect(timer, &QTimer::timeout, this, QOverload<>::of(&Map2::update));
    timer->start(1000);



    StopBtn = new QPushButton(this);
    StopBtn->move(150,825);
    StopBtn->resize(200,50);
    StopBtn->setText("Stop");

    connect(StopBtn,SIGNAL(clicked()),this,SLOT(Stop()));

    p1.load("D:/C++/QLink/1.jpg");
    p2.load("D:/C++/QLink/2.jpg");
    p3.load("D:/C++/QLink/3.jpg");
    p4.load("D:/C++/QLink/4.jpg");
    p5.load("D:/C++/QLink/5.jpg");
    p6.load("D:/C++/QLink/6.jpg");
    p7.load("D:/C++/QLink/7.jpg");
    p8.load("D:/C++/QLink/8.jpg");
    p9.load("D:/C++/QLink/9.jpg");
    pink.load("D:/C++/QLink/pink.jpg");
    p12.load("D:/C++/QLink/12.jpg");




    Mapclear();
    Mapcreat();
    data[0][0] = 9;
    data[WIDTH-1][HEIGHT-1] = 12;



}

void Map2::Stop()
{
    if( clicked == false )
    {
        StopBtn->setText("Continue");
        timer->stop();
        clicked = true;    
    }
    else if( clicked == true )
    {
        StopBtn->setText("Stop");
        timer->start();
        clicked = false;
    }
}

void Map2::timeRun()
{
    --second;
}


void Map2::keyPressEvent(QKeyEvent *event)
{



    if( clicked ) return;
    if( second == 0) return;
    int flag = false;
    for(int i = 1; i < WIDTH - 1 ; ++i )
    {
        for(int j = 1; j < HEIGHT - 1; ++j)
        {
            if( data[i][j] != 0 && data[i][j] != 9 && data[i][j] != 12 )
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
            if( data[WIDTH-1][y] == 12 ) return;
            data[x][y] = 0;
            x = WIDTH - 1;
            data[x][y] = 9;
        }
        else if( data[x-1][y] == 12 ) return;
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
                                    ++score1;
                                    break;
                                }
                                if( temp == data[x-1][y] && OneInfletion(x-1,y,tempX,tempY,data) )
                                {
                                    data[x-1][y] = 0;
                                    data[tempX][tempY] = 0;
                                    --num;
                                    ++score1;
                                    break;
                                }
                                if( temp == data[x-1][y] && TwoInfletion(x-1,y,tempX,tempY,data) )
                                {
                                    data[x-1][y] = 0;
                                    data[tempX][tempY] = 0;
                                    --num;
                                    ++score1;
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

    if(event->key() == Qt::Key_1)
    {
        if( x2 == 0 )
        {
            if( data[WIDTH-1][y2] == 9 ) return;
            data[x2][y2] = 0;
            x2 = WIDTH - 1;
            data[x2][y2] = 12;
        }
        else if( data[x2-1][y2] == 9 ) return;
        else if( data[x2-1][y2] == 0 )
        {
            data[x2][y2] = 0;
            --x2;
            data[x2][y2] = 12;
        }
        else if( data[x2-1][y2] != 0 )
        {
            switch( num2 )
            {
            case 0:
                         temp2 = data[x2-1][y2];
                         tempXX = x2-1;
                         tempYY = y2;
                         ++num2;
                         break;
            case 1:
                         if( x2-1 != tempXX || y2 != tempYY )
                            {
                                if( temp2 == data[x2-1][y2] && NoInfletion(x2-1,y2,tempXX,tempYY,data) )
                                {
                                    data[x2-1][y2] = 0;
                                    data[tempXX][tempYY] = 0;
                                    --num2;
                                    ++score2;
                                    //  noinflection();
                                    break;
                                }
                                if( temp2 == data[x2-1][y2] && OneInfletion(x2-1,y2,tempXX,tempYY,data) )
                                {
                                    data[x2-1][y2] = 0;
                                    data[tempXX][tempYY] = 0;
                                    --num2;
                                    ++score2;
                                    //  oneinflection();
                                    break;
                                }
                                if( temp2 == data[x2-1][y2] && TwoInfletion(x2-1,y2,tempXX,tempYY,data) )
                                {
                                    data[x2-1][y2] = 0;
                                    data[tempXX][tempYY] = 0;
                                    --num2;
                                    ++score2;
                                    //  twoinflection();
                                    break;
                                }
                                tempXX = 0;
                                tempYY = 0;
                                --num2;
                            }

                            break;
            }

        }

    }

    if(event->key() == Qt::Key_D)
    {
        if( x == WIDTH - 1 )
        {
            if( data[0][y] == 12 ) return;
            data[x][y] = 0;
            x = 0;
            data[x][y] = 9;
        }
        else if( data[x+1][y] == 12 ) return;
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
                                    ++score1;
                                    //  noinflection();
                                    break;
                                }
                                if( temp == data[x+1][y] && OneInfletion(x+1,y,tempX,tempY,data) )
                                {
                                    data[x+1][y] = 0;
                                    data[tempX][tempY] = 0;
                                    --num;
                                    ++score1;
                                    //  oneinflection();
                                    break;
                                }
                                if( temp == data[x+1][y] && TwoInfletion(x+1,y,tempX,tempY,data) )
                                {
                                    data[x+1][y] = 0;
                                    data[tempX][tempY] = 0;
                                    --num;
                                    ++score1;
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

    if(event->key() == Qt::Key_3)
    {
        if( x2 == WIDTH - 1 )
        {
            if(data[0][y2] == 9) return;
            data[x2][y2] = 0;
            x2 = 0;
            data[x2][y2] = 12;
        }
        else if( data[x2+1][y2] == 9 ) return;
        else if( data[x2+1][y2] == 0 )
        {
            data[x2][y2] = 0;
            ++x2;
            data[x2][y2] = 12;
        }
        else if( data[x2+1][y2] != 0 )
        {
            switch( num2 )
            {
            case 0:
                         temp2 = data[x2+1][y2];
                         tempXX = x2+1;
                         tempYY = y2;
                         ++num2;
                         break;
            case 1:
                         if( x2+1 != tempXX || y2 != tempYY )
                            {
                                if( temp2 == data[x2+1][y2] && NoInfletion(x2+1,y2,tempXX,tempYY,data) )
                                {
                                    data[x2+1][y2] = 0;
                                    data[tempXX][tempYY] = 0;
                                    --num2;
                                    ++score2;
                                    //  noinflection();
                                    break;
                                }
                                if( temp2 == data[x2+1][y2] && OneInfletion(x2+1,y2,tempXX,tempYY,data) )
                                {
                                    data[x2+1][y2] = 0;
                                    data[tempXX][tempYY] = 0;
                                    --num2;
                                    ++score2;
                                    //  oneinflection();
                                    break;
                                }
                                if( temp2 == data[x2+1][y2] && TwoInfletion(x2+1,y2,tempXX,tempYY,data) )
                                {
                                    data[x2+1][y2] = 0;
                                    data[tempXX][tempYY] = 0;
                                    --num2;
                                    ++score2;
                                    //  twoinflection();
                                    break;
                                }
                                tempXX = 0;
                                tempYY = 0;
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
            if( data[x][HEIGHT-1] == 12 ) return;
            data[x][y] = 0;
            y = HEIGHT - 1;
            data[x][y] = 9;
        }
        else if( data[x][y-1] == 12 ) return;
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
                                    ++score1;
                                    //  noinflection();
                                    break;
                                }
                                if( temp == data[x][y-1] && OneInfletion(x,y-1,tempX,tempY,data) )
                                {
                                    data[x][y-1] = 0;
                                    data[tempX][tempY] = 0;
                                    --num;
                                    ++score1;
                                    //  oneinflection();
                                    break;
                                }
                                if( temp == data[x][y-1] && TwoInfletion(x,y-1,tempX,tempY,data) )
                                {
                                    data[x][y-1] = 0;
                                    data[tempX][tempY] = 0;
                                    --num;
                                    ++score1;
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

    if(event->key() == Qt::Key_5)
    {
        if( y2 == 0 )
        {
            if( data[x2][HEIGHT-1] == 9 ) return;
            data[x2][y2] = 0;
            y2 = HEIGHT - 1;
            data[x2][y2] = 12;
        }
        else if( data[x2][y2-1] == 9 ) return;
        else if( data[x2][y2-1] == 0 )
        {
            data[x2][y2] = 0;
            --y2;
            data[x2][y2] = 12;
        }
        else if( data[x2][y2-1] != 0 )
        {
            switch( num2 )
            {
            case 0:
                         temp2 = data[x2][y2-1];
                         tempXX= x2;
                         tempYY = y2 - 1;
                         ++num2;
                         break;
            case 1:
                         if( x2 != tempXX || y2-1 != tempYY )
                            {
                                if( temp2 == data[x2][y2-1] && NoInfletion(x2,y2-1,tempXX,tempYY,data) )
                                {
                                    data[x2][y2-1] = 0;
                                    data[tempXX][tempYY] = 0;
                                    --num2;
                                    ++score2;
                                    //  noinflection();
                                    break;
                                }
                                if( temp2 == data[x2][y2-1] && OneInfletion(x2,y2-1,tempXX,tempYY,data) )
                                {
                                    data[x2][y2-1] = 0;
                                    data[tempXX][tempYY] = 0;
                                    --num2;
                                    ++score2;
                                    //  oneinflection();
                                    break;
                                }
                                if( temp2 == data[x2][y2-1] && TwoInfletion(x2,y2-1,tempXX,tempYY,data) )
                                {
                                    data[x2][y2-1] = 0;
                                    data[tempXX][tempYY] = 0;
                                    --num2;
                                    ++score2;
                                    //  twoinflection();
                                    break;
                                }
                                tempXX = 0;
                                tempYY = 0;
                                --num2;
                            }

                            break;
            }

        }

    }

    if(event->key() == Qt::Key_S)
    {
        if( y == HEIGHT - 1 )
        {
            if( data[x][0] == 12 ) return;
            data[x][y] = 0;
            y = 0;
            data[x][y] = 9;
        }
        else if( data[x][y+1] == 12 ) return;
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
                                    ++score1;
                                    //  noinflection();
                                    break;
                                }
                                if( temp == data[x][y+1] && OneInfletion(x,y+1,tempX,tempY,data) )
                                {
                                    data[x][y+1] = 0;
                                    data[tempX][tempY] = 0;
                                    --num;
                                    ++score1;
                                    //  oneinflection();
                                    break;
                                }
                                if( temp == data[x][y+1] && TwoInfletion(x,y+1,tempX,tempY,data) )
                                {
                                    data[x][y+1] = 0;
                                    data[tempX][tempY] = 0;
                                    --num;
                                    ++score1;
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

    if(event->key() == Qt::Key_2)
    {
        if( y2 == HEIGHT - 1 )
        {
            if( data[x2][0] == 9 ) return;
            data[x2][y2] = 0;
            y2 = 0;
            data[x2][y2] = 12;
        }
        else if( data[x2][y2+1] == 9 ) return;
        else if( data[x2][y2+1] == 0 )
        {
            data[x2][y2] = 0;
            ++y2;
            data[x2][y2] = 12;
        }
        else if( data[x2][y2+1] != 0 )
        {
            switch( num2 )
            {
            case 0:
                         temp2 = data[x2][y2+1];
                         tempXX = x2;
                         tempYY = y2 + 1;
                         ++num2;
                         break;
            case 1:
                         if( x2 != tempXX || y2+1 != tempYY )
                            {
                                if( temp2 == data[x2][y2+1] && NoInfletion(x2,y2+1,tempXX,tempYY,data) )
                                {
                                    data[x2][y2+1] = 0;
                                    data[tempXX][tempYY] = 0;
                                    --num2;
                                    ++score2;
                                    break;
                                }
                                if( temp2 == data[x2][y2+1] && OneInfletion(x2,y2+1,tempXX,tempYY,data) )
                                {
                                    data[x2][y2+1] = 0;
                                    data[tempXX][tempYY] = 0;
                                    --num2;
                                    ++score2;
                                    break;
                                }
                                if( temp2 == data[x2][y2+1] && TwoInfletion(x2,y2+1,tempXX,tempYY,data) )
                                {
                                    data[x2][y2+1] = 0;
                                    data[tempXX][tempYY] = 0;
                                    --num2;
                                    ++score2;
                                    break;
                                }
                                tempXX = 0;
                                tempYY = 0;
                                --num2;
                            }
                            break;
            }

        }

    }
    update();
}

void Map2::paintEvent(QPaintEvent *)
{

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);


    QFont font("Helvetica");
    font.setPixelSize(20);


    QPainter Second(this);
    Second.setFont(font);
    Second.drawText(800,840,QString::number(second));


    QPainter TextTime(this);
    TextTime.setFont(font);
    TextTime.drawText(700,840,"time:");


    QPainter Score1(this);
    Score1.setFont(font);
    Score1.drawText(500,880,"score:");

    QPainter TextScore1(this);
    TextScore1.setFont(font);
    TextScore1.drawText(600,880,QString::number(score1));

    QPainter Score2(this);
    Score2.setFont(font);
    Score2.drawText(700,880,"score:");

    QPainter TextScore2(this);
    TextScore2.setFont(font);
    TextScore2.drawText(800,880,QString::number(score2));




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
            if( data[i][j] != 0 && data[i][j] != 9 && data[i][j] != 12 )
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
                case 12:painter.drawPixmap(100*i,100*j,width()/10,height()/8,p12);break;

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


    if( tempX != 0 && tempY != 0 )   box1(tempX,tempY);
    if( tempXX != 0 && tempYY != 0 ) box2(tempXX,tempYY);





}

void Map2::Mapclear()
{
    for( int i = 0 ; i < WIDTH ; ++i )
    {
        for( int j = 0 ; j < HEIGHT ; ++j )
        {
            data[i][j] = 0;
        }
    }
}

void Map2::Mapcreat()
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
    Shuffle();

}

bool Map2::Connect( int x1, int y1, int x2, int y2 , int data[10][8] )
{
    if( NoInfletion( x1, y1, x2, y2, data ) || OneInfletion( x1, y1, x2, y2, data) || TwoInfletion( x1, y1, x2, y2, data) )  return true;
    else return false;
}

bool Map2::NoInfletion( int x1, int y1, int x2, int y2, int data[10][8] )
{
    bool flag = true;
    if( x1 == x2 )
    {
        for( int i = ( y1 > y2 ? y2 : y1 ) + 1; i < ( y1 > y2 ? y1 : y2 ); ++i )
            if( data[x1][i] != 0 && data[x1][i] != 9 && data[x1][i] != 12 )
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

bool Map2::OneInfletion( int x1, int y1, int x2, int y2, int data[10][8] )
{
    if( ( data[x1][y2] == 0 || data[x1][y2] == 9 || data[x1][y2] == 12 ) && NoInfletion( x1, y1, x1, y2, data ) && NoInfletion( x2, y2, x1, y2, data ) )
        {
           tempX1 = x1;
           tempY1 = y1;
           tempX2 = x1;
           tempY2 = y2;
           tempX3 = x2;
           tempY3 = y2;
           return true;
         }
    if( ( data[x2][y1] == 0 || data[x2][y1] == 9 || data[x1][y2] == 12 ) && NoInfletion( x1, y1, x2, y1, data ) && NoInfletion( x2, y2, x2, y1, data ) )
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

bool Map2::TwoInfletion( int x1, int y1, int x2, int y2, int data[10][8] )
{
    if( x1 == x2 || y1 == y2 )
    {
        if( x1 == x2 )
        {
            int x = x1, y = y1;
            while( x > 0 && x < WIDTH-1 && y > 0 && y < HEIGHT-1 )
            {
                --x;
                if( data[x][y] != 0 && data[x][y] != 9 && data[x][y] != 12 ) break;
                if( NoInfletion(x,y,x,y2,data) && ( data[x][y2] == 0 || data[x][y2] == 9 || data[x][y2] == 12 ) && NoInfletion(x,y2,x2,y2,data) )
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
                if( data[x][y] != 0 && data[x][y] != 9 && data[x][y] != 12) break;
                if( NoInfletion(x,y,x,y2,data) && ( data[x][y2] == 0 || data[x][y2] == 9 || data[x][y2] == 12 ) && NoInfletion(x,y2,x2,y2,data) )
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
                 if( data[x][y] != 0 && data[x][y] != 9 && data[x][y] != 12) break;
                 if( NoInfletion(x,y,x2,y,data) && ( data[x2][y] == 0 || data[x2][y] == 9 || data[x2][y] == 12 ) && NoInfletion(x2,y,x2,y2,data) )
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
                 if( data[x][y] != 0 && data[x][y] != 9 && data[x][y] != 12) break;
                 if( NoInfletion(x,y,x2,y,data) && ( data[x2][y] == 0 || data[x2][y] == 9 || data[x2][y] ==12 ) && NoInfletion(x2,y,x2,y2,data) )
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
        if( data[x][y] != 0 && data[x][y] != 9 && data[x][y] != 12 ) break;
        if( NoInfletion(x,y,x,y2,data) && ( data[x][y2] == 0 || data[x][y2] == 9 || data[x][y2] == 12 ) && NoInfletion(x,y2,x2,y2,data) )
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
        if( data[x][y] != 0 && data[x][y] != 9 && data[x][y] != 12 ) break;
        if( NoInfletion(x,y,x,y2,data) && ( data[x][y2] == 0 || data[x][y2] == 9 || data[x][y2] == 12 ) && NoInfletion(x,y2,x2,y2,data) )
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
         if( data[x][y] != 0 && data[x][y] != 9 && data[x][y] != 12 ) break;
         if( NoInfletion(x,y,x2,y,data) && ( data[x2][y] == 0 || data[x2][y] == 9 || data[x2][y] == 12 ) && NoInfletion(x2,y,x2,y2,data) )
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
         if( data[x][y] != 0 && data[x][y] != 9 && data[x][y] != 12 ) break;
         if( NoInfletion(x,y,x2,y,data) && ( data[x2][y] == 0 || data[x2][y] == 9 || data[x2][y] == 12 ) && NoInfletion(x2,y,x2,y2,data) )
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

void Map2::box1(int x, int y)
{
    QPainter paint(this);
    QPen pen;
    pen.setColor(Qt::green);
    paint.setPen(pen);
    paint.drawRect(x*100,y*100,100,100);
}

void Map2::box2(int x, int y)
{
    QPainter paint(this);
    QPen pen;
    pen.setColor(Qt::yellow);
    paint.setPen(pen);
    paint.drawRect(x*100,y*100,100,100);
}

void Map2::wire(int x1, int y1, int x2, int y2)
{
    x1 = x1 * 100 + 50;
    x2 = x2 * 100 + 50;
    y1 = y1 * 100 + 50;
    y2 = y2 * 100 + 50;
    QPainter paint(this);
    paint.setPen(Qt::red);
    paint.drawLine(x1,y1,x2,y2);

}

void Map2::Shuffle()
{
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
