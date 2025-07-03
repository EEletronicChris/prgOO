#include "filtropassabaixa_ativo.h"
#include <QPixmap>

FiltroPassaBaixa_ativo::FiltroPassaBaixa_ativo() : imagemLabel(nullptr) {}

void FiltroPassaBaixa_ativo::exibirImagem(QWidget *parent, const QString &tipoFiltro) {
    if (!imagemLabel) {
        imagemLabel = new QLabel(parent);
        imagemLabel->setScaledContents(true);
        imagemLabel->resize(200, 120);
        imagemLabel->move(320, 10);
    }

    if (tipoFiltro == "Ativo passa-baixa") {
        imagemLabel->setPixmap(QPixmap("Filtro_passa_baixa_exemple.png"));
    } else {
        imagemLabel->hide();
    }
}
