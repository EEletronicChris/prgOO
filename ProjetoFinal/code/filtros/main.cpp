#include <QApplication>
#include <QWidget>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Projeto de Filtros");

    MainWindow interface;
    window.setLayout(interface.getLayout());

    window.show();
    return app.exec();
}
