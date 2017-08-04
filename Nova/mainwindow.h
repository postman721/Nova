#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <string>
#include <QKeyEvent>
using namespace std;
extern int i;

namespace Ui {
class MainWindow;
}

class volumeLevels{

    public:
        void buttonPress();
};


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_horizontalSlider_valueChanged(int i);

    void on_volume50_clicked();

    void on_volume100_clicked();

    void on_volumeMuted_clicked();

    void keyPressEvent(QKeyEvent *events);

    void mouseDoubleClickEvent(QMouseEvent *events);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
