#include "filtropassafaixa_ativo.h"

FiltroPassaFaixa_ativo::FiltroPassaFaixa_ativo(QWidget *parent) : FiltroAtivo(parent) {}

FiltroPassaFaixa_ativo::FiltroPassaFaixa_ativo(QWidget *parent, float ganho, float fInf, float fSup) : FiltroAtivo(parent) {
    this->gain_value = ganho;
    this->lower_cut_frequency = fInf;
    this->upper_cut_frequency = fSup;

    qDebug() << " fInf: " << lower_cut_frequency << " fSup:" << upper_cut_frequency << "ganho: " << gain_value;
}

void FiltroPassaFaixa_ativo::draw_pass_band_active(){}

void FiltroPassaFaixa_ativo::components_calc() {}
