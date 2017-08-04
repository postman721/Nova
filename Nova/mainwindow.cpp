#include "mainwindow.h"
#include "ui_mainwindow.h"
int i;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){

    ui->setupUi(this);

    ui->statusBar->showMessage("Welcome. Double-Click to open Pavucontrol.");

};



MainWindow::~MainWindow(){

    delete ui;

};



void MainWindow::on_volume50_clicked(){

    volumeLevels obj;
    obj.buttonPress();

    i=50;

    if(i == 50 ){

        ui->horizontalSlider->setValue(ui->horizontalSlider->value()-100);

        ui->horizontalSlider->setValue(ui->horizontalSlider->value()+50);

        ui->statusBar->showMessage("Volume 50%");
    }
};



void MainWindow::on_volume100_clicked(){

    volumeLevels obj;
    obj.buttonPress();

    i=100;

    if(i == 100 ){

        ui->horizontalSlider->setValue(ui->horizontalSlider->value()-100);

        ui->horizontalSlider->setValue(ui->horizontalSlider->value()+100);

        ui->statusBar->showMessage("Volume 100%");
      }
};


void MainWindow::on_volumeMuted_clicked(){

    volumeLevels obj;
    obj.buttonPress();

    i=0;

    if(i == 0 ){

        ui->horizontalSlider->setValue(ui->horizontalSlider -> value()-100);

        ui->statusBar->showMessage("Volume 0%");
    }
};



void MainWindow::keyPressEvent(QKeyEvent *events){
    //Volume keys

    if(events->key()==Qt::Key_VolumeDown){


        ui->horizontalSlider->setValue(ui->horizontalSlider->value()-5);
    }

    else if(events->key()==Qt::Key_VolumeUp){


        ui->horizontalSlider->setValue(ui->horizontalSlider->value()+5);
    }


    else if(events->key()==Qt::Key_VolumeMute){


        ui->horizontalSlider->setValue(ui->horizontalSlider->value()-100);
    }

    //Esc event == Quit the program
    else if(events->key()==Qt::Key_Escape){

        this->close();
    }
};



void MainWindow::mouseDoubleClickEvent(QMouseEvent *events){
    //Mouse clicks

    if(events->button()==Qt::LeftButton){
        this->close();

        system("pavucontrol");

    }

    else if(events->button()==Qt::RightButton){

        this->close();

        system("pavucontrol");
    }

};



void MainWindow::on_horizontalSlider_valueChanged(int i){
    if(i == 0 ){


        system("pactl -- set-sink-volume 0  0%");

        system("pactl -- set-sink-volume 1  0%");

        system("pactl -- set-sink-volume 2  0%");

        system("pactl -- set-sink-volume 3  0%");

        system("pactl -- set-sink-volume 4  0%");

        MainWindow::ui->statusBar->showMessage("Volume 0%.");


    }



    else if(i == 5 ){

        system("pactl -- set-sink-volume 0  5%");

        system("pactl -- set-sink-volume 1  5%");

        system("pactl -- set-sink-volume 2  5%");

        system("pactl -- set-sink-volume 3  5%");

        system("pactl -- set-sink-volume 4  5%");

        MainWindow::ui->statusBar->showMessage("Volume 5%.");

    }



    else if(i == 10 ){

        system("pactl -- set-sink-volume 0  10%");

        system("pactl -- set-sink-volume 1  10%");

        system("pactl -- set-sink-volume 2  10%");

        system("pactl -- set-sink-volume 3  10%");

        system("pactl -- set-sink-volume 4  10%");

        MainWindow::ui->statusBar->showMessage("Volume 10%.");

    }



    else if(i == 15 ){

        system("pactl -- set-sink-volume 0  15%");

        system("pactl -- set-sink-volume 1  15%");

        system("pactl -- set-sink-volume 2  15%");

        system("pactl -- set-sink-volume 3  15%");

        system("pactl -- set-sink-volume 4  15%");

        MainWindow::ui->statusBar->showMessage("Volume 15%.");


    }



    else if(i == 20 ){

        system("pactl -- set-sink-volume 0  20%");

        system("pactl -- set-sink-volume 1  20%");

        system("pactl -- set-sink-volume 2  20%");

        system("pactl -- set-sink-volume 3  20%");

        system("pactl -- set-sink-volume 4  20%");

        MainWindow::ui->statusBar->showMessage("Volume 20%.");

    }



    else if(i == 25 ){

        system("pactl -- set-sink-volume 0  25%");

        system("pactl -- set-sink-volume 1  25%");

        system("pactl -- set-sink-volume 2  25%");

        system("pactl -- set-sink-volume 3  25%");

        system("pactl -- set-sink-volume 4  25%");

        MainWindow::ui->statusBar->showMessage("Volume 25%.");


    }



    else if(i == 30 ){

        system("pactl -- set-sink-volume 0  39%");

        system("pactl -- set-sink-volume 1  30%");

        system("pactl -- set-sink-volume 2  30%");

        system("pactl -- set-sink-volume 3  30%");

        system("pactl -- set-sink-volume 4  30%");

        MainWindow::ui->statusBar->showMessage("Volume 30%.");

    }



    else if(i == 35 ){

        system("pactl -- set-sink-volume 0  35%");

        system("pactl -- set-sink-volume 1  35%");

        system("pactl -- set-sink-volume 2  35%");

        system("pactl -- set-sink-volume 3  35%");

        system("pactl -- set-sink-volume 4  35%");

        MainWindow::ui->statusBar->showMessage("Volume 35%.");


    }



    else if(i == 40 ){

        system("pactl -- set-sink-volume 0  40%");

        system("pactl -- set-sink-volume 1  40%");

        system("pactl -- set-sink-volume 2  40%");

        system("pactl -- set-sink-volume 3  40%");

        system("pactl -- set-sink-volume 4  40%");

        MainWindow::ui->statusBar->showMessage("Volume 40%.");

    }



    else if(i == 45 ){

        system("pactl -- set-sink-volume 0  45%");

        system("pactl -- set-sink-volume 1  45%");

        system("pactl -- set-sink-volume 2  45%");

        system("pactl -- set-sink-volume 3  45%");

        system("pactl -- set-sink-volume 4  45%");

        MainWindow::ui->statusBar->showMessage("Volume 45%.");


    }



    else if(i == 50 ){

        system("pactl -- set-sink-volume 0  50%");

        system("pactl -- set-sink-volume 1  50%");

        system("pactl -- set-sink-volume 2  50%");

        system("pactl -- set-sink-volume 3  50%");

        system("pactl -- set-sink-volume 4  50%");

        MainWindow::ui->statusBar->showMessage("Volume 50%.");

    }



    else if(i == 55 ){

        system("pactl -- set-sink-volume 0  55%");

        system("pactl -- set-sink-volume 1  55%");

        system("pactl -- set-sink-volume 2  55%");

        system("pactl -- set-sink-volume 3  55%");

        system("pactl -- set-sink-volume 4  55%");

        MainWindow::ui->statusBar->showMessage("Volume 55%.");

    }



    else if(i == 60 ){

        system("pactl -- set-sink-volume 0  60%");

        system("pactl -- set-sink-volume 1  60%");

        system("pactl -- set-sink-volume 2  60%");

        system("pactl -- set-sink-volume 3  60%");

        system("pactl -- set-sink-volume 4  60%");

        MainWindow::ui->statusBar->showMessage("Volume 60%.");

    }



    else if(i == 65 ){

        system("pactl -- set-sink-volume 0  65%");

        system("pactl -- set-sink-volume 1  65%");

        system("pactl -- set-sink-volume 2  65%");

        system("pactl -- set-sink-volume 3  65%");

        system("pactl -- set-sink-volume 4  65%");

        MainWindow::ui->statusBar->showMessage("Volume 65%.");

    }



    else if(i == 70 ){


        system("pactl -- set-sink-volume 0  70%");

        system("pactl -- set-sink-volume 1  70%");

        system("pactl -- set-sink-volume 2  70%");

        system("pactl -- set-sink-volume 3  70%");

        system("pactl -- set-sink-volume 4  70%");

        MainWindow::ui->statusBar->showMessage("Volume 70%.");

    }



    else if(i == 75 ){


        system("pactl -- set-sink-volume 0  75%");

        system("pactl -- set-sink-volume 1  75%");

        system("pactl -- set-sink-volume 2  75%");

        system("pactl -- set-sink-volume 3  75%");

        system("pactl -- set-sink-volume 4  75%");

        MainWindow::ui->statusBar->showMessage("Volume 75%.");

    }



    else if(i == 80 ){

        system("pactl -- set-sink-volume 0  80%");

        system("pactl -- set-sink-volume 1  80%");

        system("pactl -- set-sink-volume 2  80%");

        system("pactl -- set-sink-volume 3  80%");

        system("pactl -- set-sink-volume 4  80%");

        MainWindow::ui->statusBar->showMessage("Volume 80%.");

    }



    else if(i == 85 ){

        system("pactl -- set-sink-volume 0  85%");

        system("pactl -- set-sink-volume 1  85%");

        system("pactl -- set-sink-volume 2  85%");

        system("pactl -- set-sink-volume 3  85%");

        system("pactl -- set-sink-volume 4  85%");

        MainWindow::ui->statusBar->showMessage("Volume 85%.");


    }



    else if(i == 90 ){

        system("pactl -- set-sink-volume 0  90%");

        system("pactl -- set-sink-volume 1  90%");

        system("pactl -- set-sink-volume 2  90%");

        system("pactl -- set-sink-volume 3  90%");

        system("pactl -- set-sink-volume 4  90%");

        MainWindow::ui->statusBar->showMessage("Volume 90%.");

    }



    else if(i == 95 ){

        system("pactl -- set-sink-volume 0  95%");

        system("pactl -- set-sink-volume 1  95%");

        system("pactl -- set-sink-volume 2  95%");

        system("pactl -- set-sink-volume 3  95%");

        system("pactl -- set-sink-volume 4  95%");

        MainWindow::ui->statusBar->showMessage("Volume 95%.");

    }



    else if(i == 100 ){

        system("pactl -- set-sink-volume 0  100%");

        system("pactl -- set-sink-volume 1  100%");

        system("pactl -- set-sink-volume 2  100%");

        system("pactl -- set-sink-volume 3  100%");

        system("pactl -- set-sink-volume 4  100%");

        MainWindow::ui->statusBar->showMessage("Volume 100%.");

    }
};

