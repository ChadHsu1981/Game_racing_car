#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void update_time();       //遊戲時間更新
    void update_object();     //遊戲物體移動更新
    void update_stop();       //遊戲停止

private:
    Ui::MainWindow *ui;
    int time;               //遊戲時間
    int game_status;        //遊戲狀態
    int bgm_pos;            //背景的位置(水平)

    QTimer *clock_timer;     //遊戲時間計數器
    QTimer *object_timer;    //物體移動計數器

    void game_start();
    void game_pause();
    void game_stop();
};

#endif // MAINWINDOW_H
