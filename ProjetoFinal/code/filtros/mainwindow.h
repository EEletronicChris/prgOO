#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QVBoxLayout>

class MainWindow {
public:
    MainWindow();
    QVBoxLayout *getLayout();

private:
    QVBoxLayout *mainLayout;
};

#endif MAINWINDOW_H
