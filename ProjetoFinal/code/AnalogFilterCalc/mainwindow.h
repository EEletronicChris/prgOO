#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "analogfilters.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QPushButton *fechar_button;
    void resizeEvent(QResizeEvent *event) override;

    analogFilters *filtros_models;
};

#endif // MAINWINDOW_H
