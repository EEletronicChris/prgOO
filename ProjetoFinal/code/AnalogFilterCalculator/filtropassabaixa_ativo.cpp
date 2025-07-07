#include "FiltroPassaBaixa_ativo.h"

FiltroPassaBaixa_ativo::FiltroPassaBaixa_ativo(QWidget *parent) : FiltroAtivo(parent) {}

FiltroPassaBaixa_ativo::FiltroPassaBaixa_ativo(QWidget *parent, float ganho, float fCent) : FiltroAtivo(parent) {
    this->gain_value = ganho;
    this->central_frequency = fCent;

    qDebug() << " central: " << central_frequency << "ganho: " << gain_value;
    imageLabel = new QLabel(this);
    imageLabel->setScaledContents(true);
    imageLabel->resize(400, 300);
    imageLabel->move(100, 50);

    QPixmap imagem("images/FiltroPassaBaixa_ativo.png");
    imageLabel->setPixmap(imagem);
    imageLabel->show();

}

void FiltroPassaBaixa_ativo::draw_low_pass_active() {

}

void FiltroPassaBaixa_ativo::components_calc() {
    draw_low_pass_active();
}
