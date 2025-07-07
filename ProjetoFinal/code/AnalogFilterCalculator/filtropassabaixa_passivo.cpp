#include "FiltroPassaBaixa_passivo.h"

FiltroPassaBaixa_passivo::FiltroPassaBaixa_passivo(QWidget *parent) : FiltroPassivo(parent) {}

FiltroPassaBaixa_passivo::FiltroPassaBaixa_passivo(QWidget *parent, float fCent) : FiltroPassivo(parent) {

    this->central_frequency = fCent;

    qDebug() << " central: " << central_frequency;

    imageLabel = new QLabel(this);
    imageLabel->setScaledContents(true);
    imageLabel->resize(700, 440);
    imageLabel->move(10, 10);

    QPixmap imagem("images/FiltroPassaBaixa_passivo.png");
    imageLabel->setPixmap(imagem);
}

void FiltroPassaBaixa_passivo::draw_low_pass_passive_RC()
{
    imageLabel->show();
}

void FiltroPassaBaixa_passivo::draw_low_pass_passive_RL() {}

void FiltroPassaBaixa_passivo::components_calc()
{
   draw_low_pass_passive_RC();
}
