#include "FiltroPassaBaixa_ativo.h"

FiltroPassaBaixa_ativo::FiltroPassaBaixa_ativo(QWidget *parent) : FiltroAtivo(parent) {}

FiltroPassaBaixa_ativo::FiltroPassaBaixa_ativo(QWidget *parent, float ganho, float fCent) : FiltroAtivo(parent) {
    this->gain_value = ganho;
    this->central_frequency = fCent;

    qDebug() << " central: " << central_frequency << "ganho: " << gain_value;

    botaoReiniciar = new QPushButton("Reiniciar", this);
    botaoReiniciar->resize(100, 30);
    botaoReiniciar->move(924, 10);
    botaoReiniciar->show();
    connect(botaoReiniciar, &QPushButton::clicked,this,&Filtros::resetarInterface);

    imageLabel = new QLabel(this);
    imageLabel->setScaledContents(true);
    imageLabel->resize(904, 580);
    imageLabel->move(10, 10);

    QPixmap imagem("images/FiltroPassaBaixa_ativo.png");
    imageLabel->setPixmap(imagem);


}

void FiltroPassaBaixa_ativo::draw_low_pass_active() {
    imageLabel->show();
}

void FiltroPassaBaixa_ativo::components_calc() {
    draw_low_pass_active();
}
