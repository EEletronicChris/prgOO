#include "FiltroPassaAlta_ativo.h"

FiltroPassaAlta_ativo::FiltroPassaAlta_ativo(QWidget *parent) : FiltroAtivo(parent) {}

FiltroPassaAlta_ativo::FiltroPassaAlta_ativo(QWidget *parent, float ganho, float fCent) : FiltroAtivo(parent) {
    this->gain_value = ganho;
    this->central_frequency = fCent;

    qDebug() << " central: " << central_frequency << "ganho: " << gain_value;
}

void FiltroPassaAlta_ativo::draw_high_pass_active() {}

void FiltroPassaAlta_ativo::components_calc() {}
