#include "filtropassabaixa_passivo.h"
#include <QPixmap>


FiltroPassaBaixa_passivo::FiltroPassaBaixa_passivo() : imagemLabel(nullptr) {}

void FiltroPassaBaixa_passivo::exibirImagem(QWidget *parent, const QString &tipoFiltro) {
    if (!imagemLabel) {
        imagemLabel = new QLabel(parent);
        imagemLabel->setScaledContents(true);
        imagemLabel->resize(200, 200);
        imagemLabel->move(320, 140);
    }

    if (tipoFiltro == "Passivo passa-baixa") {
        QPixmap imagem("img/Filtro_rejeita_faixa_exemple.png");

        } else {
            imagemLabel->setPixmap(imagem);
            imagemLabel->show();
        }
    } else {
        imagemLabel->hide();
    }
}
