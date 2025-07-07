#include "filtropassafaixa_ativo.h"

FiltroPassaFaixa_ativo::FiltroPassaFaixa_ativo(QWidget *parent) : FiltroAtivo(parent) {}

FiltroPassaFaixa_ativo::FiltroPassaFaixa_ativo(QWidget *parent, float ganho, float fInf, float fSup) : FiltroAtivo(parent) {
    this->gain_value = ganho;
    this->lower_cut_frequency = fInf;
    this->upper_cut_frequency = fSup;

    qDebug() << " fInf: " << lower_cut_frequency << " fSup:" << upper_cut_frequency << "ganho: " << gain_value;

    botaoReiniciar = new QPushButton("Reiniciar", this);
    botaoReiniciar->resize(100, 30);
    botaoReiniciar->move(1140, 10);
    botaoReiniciar->show();
    connect(botaoReiniciar, &QPushButton::clicked,this,&Filtros::resetarInterface);

    imageLabel = new QLabel(this);
    imageLabel->setScaledContents(true);
    imageLabel->resize(1120, 337);
    imageLabel->move(10, 10);

    QPixmap imagem("images/FiltroPassaFaixa_ativo.png");
    imageLabel->setPixmap(imagem);
}

void FiltroPassaFaixa_ativo::draw_pass_band_active()
{
    imageLabel->show();
}

void FiltroPassaFaixa_ativo::components_calc()
{
    draw_pass_band_active();
}
