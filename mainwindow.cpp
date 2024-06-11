#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>

/*
 game_status:
 0 => init
 1 => playing
 2 => pause
 3 => timeout
 4 => die
*/


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    game_status = 0;

    //移動物體
    bgm_pos = 0;
    object_timer = new QTimer(this); //建立計時器
    connect(object_timer, SIGNAL(timeout()), this, SLOT(update_object())); //連接訊號
    object_timer->start(10);   //每隔10秒更新一次

    //更新時間
    time = 30;
    clock_timer = new QTimer(this); //建立計時器
    connect(clock_timer, SIGNAL(timeout()), this, SLOT(update_time())); //連接訊號
    //clock
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_time()
{
    time -= 1; //時間每次減少 1

    ui->lcd_clock->display(time);

    if(time == 0)
    {
        game_status = 3; //設為 timout 的狀態
        game_stop();
    }
}

void MainWindow::update_stop()
{
    clock_timer->stop();
    object_timer->stop();
}


void MainWindow::update_object()
{
    bgm_pos -= 1;   //背景位置每次往左移動 1

    ui->background->setGeometry(QRect(bgm_pos, 0, 4800, 512));  //設定背景位置
    if(bgm_pos == -32)
    {
        //當移動一圈，背景從頭顯示
        bgm_pos = 0;
    }
}
