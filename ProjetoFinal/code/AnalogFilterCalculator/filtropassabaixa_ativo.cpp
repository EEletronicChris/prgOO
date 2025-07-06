#include "FiltroPassaBaixa_ativo.h"

FiltroPassaBaixa_ativo::FiltroPassaBaixa_ativo(QWidget *parent) : FiltroAtivo(parent) {}

FiltroPassaBaixa_ativo::FiltroPassaBaixa_ativo(QWidget *parent, float ganho, float fCent) : FiltroAtivo(parent) {
    this->gain_value = ganho;
    this->central_frequency = fCent;

    qDebug() << " central: " << central_frequency << "ganho: " << gain_value;
}

void FiltroPassaBaixa_ativo::draw_low_pass_active() {}

void FiltroPassaBaixa_ativo::components_calc() {}
