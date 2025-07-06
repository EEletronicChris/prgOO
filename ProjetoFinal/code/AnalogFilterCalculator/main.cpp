#include "filtros.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Filtros *w = new Filtros();
    w->setWindowTitle("Calculadora de Filtros Analógicos");
    w->setStyleSheet("background-color: #494949;");
    w->resize(500, 500);
    w->show();
    return a.exec();
}
