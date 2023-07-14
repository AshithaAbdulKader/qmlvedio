#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QtMultimedia>
#include<QtMultimediaWidgets>
#include<QtCore>
#include<QtGui>
#include<QtWidgets>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_play_clicked();

    void on_pause_clicked();

    void on_actionopen_triggered();

    void on_seek_bw_clicked();

    void on_seek_fw_clicked();

    void on_Duration_bar_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    QMediaPlayer *Player;
    QVideoWidget *Video;
    qint64 mDuration;
    bool IS_pause= true;
    bool IS_Muted=false;
};
#endif // MAINWINDOW_H
