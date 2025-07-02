#include <QApplication>
#include "filtroativo.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    filtroAtivo janela;
    janela.resize(600, 400);
    janela.setWindowTitle("Filtros Ativos");
    janela.show();

    return app.exec();
}
