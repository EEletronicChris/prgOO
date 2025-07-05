#include "filtros.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Filtros *w = new Filtros();
    w->setWindowTitle("Calculadora de Filtros Analógicos");
    w->setStyleSheet("background-color: #494949;");
    w->show();
    w->get_filter_type();
    return a.exec();
}
