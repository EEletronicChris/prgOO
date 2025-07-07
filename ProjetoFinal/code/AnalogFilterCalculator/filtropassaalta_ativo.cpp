#include "FiltroPassaAlta_ativo.h"

FiltroPassaAlta_ativo::FiltroPassaAlta_ativo(QWidget *parent) : FiltroAtivo(parent) {}

FiltroPassaAlta_ativo::FiltroPassaAlta_ativo(QWidget *parent, float ganho, float fCent) : FiltroAtivo(parent) {
    this->gain_value = ganho;
    this->central_frequency = fCent;

    qDebug() << " central: " << central_frequency << "ganho: " << gain_value;

    imageLabel = new QLabel(this);
    imageLabel->setScaledContents(true);
    imageLabel->resize(400, 300);
    imageLabel->move(100, 50);

    QPixmap imagem("images/FiltroPassaAlta_ativo.png");
    imageLabel->setPixmap(imagem);


}

void FiltroPassaAlta_ativo::draw_high_pass_active() {

    imageLabel->show();
}

void FiltroPassaAlta_ativo::components_calc() {
    draw_high_pass_active();
}
