#include <QApplication>
#include "analogfilters.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    analogFilters janela;
    janela.resize(600, 400);
    janela.setWindowTitle("Calculadora de Filtros Analógicos");
    janela.show();

    return app.exec();
}
