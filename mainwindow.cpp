#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "QEvent"
#include <QKeyEvent>
#include <QTime>
#include <QCoreApplication>
#include <random>
#include "time.h"
#include <list>
#include <QRect>
#include <QPainter>

const int screenSize=600;
const int step=30;
enum direction{
    stay=0,
    left=1,
    up=2,
    right=3,
    down=4,
};
direction dir=stay;

std::list<QRect> snake;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget::setFixedSize(this->size());
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(slotTimerAlarm()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    bool flag=false;
    int key=event->key();
    if(dir==stay){
        flag=true;
    }
    switch(key){
    case 16777234: {dir=left; break;}
    case 65: {dir=left; break;}
    case 1060: {dir=left; break;}
    case 16777235: {dir=up; break;}
    case 87: {dir=up; break;}
    case 1062: {dir=up; break;}
    case 16777236: {dir=right; break;}
    case 68: {dir=right; break;}
    case 1042: {dir=right; break;}
    case 16777237: {dir=down; break;}
    case 83: {dir=down; break;}
    case 1067: {dir=down; break;}
    }
    if(flag==true){
        timer->start(250);
        //upd();
        flag=false;
    }
}

void MainWindow::upd(){
    const int gap=250;
    QRect newRect(ui->Snake->geometry());
    ui->log->setText("move");
    switch(dir){
    case stay: break;
    case left: {ui->Snake->move(ui->Snake->x()-step, ui->Snake->y()); break;}
    case up: {ui->Snake->move(ui->Snake->x(), ui->Snake->y()-step); break;}
    case right: {ui->Snake->move(ui->Snake->x()+step, ui->Snake->y()); break;}
    case down: {ui->Snake->move(ui->Snake->x(), ui->Snake->y()+step); break;}
    }
    snake.push_back(newRect);
    ui->log->setText("checkFood");
    checkFood();
    ui->log->setText("repaint");
    repaint();
    if((ui->Snake->x()>=30)&&(ui->Snake->x()<=540)){
        if((ui->Snake->y()>=30)&&(ui->Snake->y()<=540)){
            ui->log->setText("checkSelf");
            if(checkSelf()){
                ui->log->setText("new cycle");
            }
        }else{
            auto reply=QMessageBox::question(this, "You ran into the wall!", "Start again?", QMessageBox::Yes|QMessageBox::No);
            if(reply==QMessageBox::Yes){
                newGame();
            }else{
                close();
            }
        }
    }else{
        auto reply=QMessageBox::question(this, "You ran into the wall!", "Start again?", QMessageBox::Yes|QMessageBox::No);
        if(reply==QMessageBox::Yes){
            newGame();
        }else{
            close();
        }
    }
}

void MainWindow::checkFood(){
    if( (ui->Snake->x()==ui->food->x())&&(ui->Snake->y()==ui->food->y()) ){
        ui->counter->setText(QString::number((ui->counter->text().toInt())+1));
        placeFood();
    }else{
        snake.pop_front();
    }
}

void MainWindow::placeFood(){
    srand(time(nullptr));
    int newX;
    newX=(rand()%(screenSize/step-2)+1)*step;
    int newY;
    newY=(rand()%(screenSize/step-2)+1)*step;    
    ui->food->setGeometry(newX, newY, step, step);
    QRect curr;
    for(auto element = snake.cbegin(); element!=snake.end(); ++element){
        curr=*element;
        while(((ui->food->x()==curr.x())&&(ui->food->y()==curr.y()))||((ui->food->x()==ui->Snake->x())&&(ui->food->y()==ui->Snake->y()))){
            srand(time(nullptr));
            int newX;
            newX=(rand()%(screenSize/step-2)+1)*step;
            int newY;
            newY=(rand()%(screenSize/step-2)+1)*step;
            ui->food->setGeometry(newX, newY, step, step);
            QRect curr;
        }
    }
    if((ui->food->x()==ui->Snake->x())&&(ui->food->y()==ui->Snake->y())){
    }
}

void MainWindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
    painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));

    for(auto element = snake.cbegin(); element!=snake.cend(); ++element){
        painter.drawRect(*element);
    }
}

bool MainWindow::checkSelf(){
    QRect curr;
    for(auto element = snake.cbegin(); element!=snake.end(); ++element){
        curr=*element;
        if((curr.x()==ui->Snake->x())&&(curr.y()==ui->Snake->y())){
            auto reply=QMessageBox::question(this, "You ran into yourself!", "Start again?", QMessageBox::Yes|QMessageBox::No);
            if(reply==QMessageBox::Yes){
                newGame();
            }else{
                close();
            }

            return false;
        }
    }
    return true;
}

void MainWindow::newGame(){
    dir=stay;
    ui->Snake->setGeometry(30,540, step, step);
    ui->food->setGeometry(270,270, step, step);
    ui->counter->setText("0");
    snake.clear();
}

void MainWindow::slotTimerAlarm()
{
    upd();
}
