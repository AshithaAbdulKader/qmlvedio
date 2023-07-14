#include "mainwindow.h"
#include "ui_mainwindow.h"
#include  <QMediaPlayer>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    Player = new QMediaPlayer();
    ui->setupUi(this);
    ui->play->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    ui->pause->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
    ui->seek_bw->setIcon(style()->standardIcon(QStyle::SP_MediaSeekBackward));
    ui->seek_fw->setIcon(style()->standardIcon(QStyle::SP_MediaSeekForward));

}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_play_clicked()
{
    Player->play();
     ui->play->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));

}


void MainWindow::on_pause_clicked()
{
    Player->pause();
      ui->play->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
}


void MainWindow::on_actionopen_triggered()
{
    QString FileName = QFileDialog::getOpenFileName(this,tr("select video file"),"",tr("mp4 files(.mp4)"));
    Video = new QVideoWidget();
    Video->setGeometry(5,5,ui->display->width()- 10,ui->display->height() - 10);
    Video->setParent(ui->display);
    Player->setVideoOutput(Video);
    Player->setSource(QUrl(FileName));
    Video->setVisible(true);
    Video->show();
}


void MainWindow::on_seek_bw_clicked()
{
    ui->Duration_bar->setValue(ui->Duration_bar->value() -20);
    Player->setPosition(ui->Duration_bar->value() *1000);
}


void MainWindow::on_seek_fw_clicked()
{
    ui->Duration_bar->setValue(ui->Duration_bar->value() +20);
    Player->setPosition(ui->Duration_bar->value() *1000);
}


void MainWindow::on_Duration_bar_valueChanged(int value)
{
    Player->setPosition(value *1000);
}

