#include "FiltroPassaAlta_passivo.h"

FiltroPassaAlta_passivo::FiltroPassaAlta_passivo(QWidget *parent) : FiltroPassivo(parent) {}

FiltroPassaAlta_passivo::FiltroPassaAlta_passivo(QWidget *parent, float fCent) : FiltroPassivo(parent) {

    this->central_frequency = fCent;

    qDebug() <<" central: " << central_frequency;

    imageLabel = new QLabel(this);
    imageLabel->setScaledContents(true);
    imageLabel->resize(700, 440);
    imageLabel->move(10, 10);

    QPixmap imagem("images/FiltroPassaAlta_passivo.png");
    imageLabel->setPixmap(imagem);
}


void FiltroPassaAlta_passivo::draw_high_pass_passive_RC() {
    imageLabel->show();
}

void FiltroPassaAlta_passivo::draw_high_pass_passive_RL() {}

void FiltroPassaAlta_passivo::components_calc() {



    draw_high_pass_passive_RC();
}

