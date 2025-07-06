#include "filtropassafaixa_passivo.h"

FiltroPassaFaixa_passivo::FiltroPassaFaixa_passivo(QWidget *parent) : FiltroPassivo(parent) {}

FiltroPassaFaixa_passivo::FiltroPassaFaixa_passivo(QWidget *parent, float fInf, float fSup) : FiltroPassivo(parent) {

    this->lower_cut_frequency = fInf;
    this->upper_cut_frequency = fSup;

    qDebug() << " fInf: " << lower_cut_frequency << " fSup:" << upper_cut_frequency;
}

void FiltroPassaFaixa_passivo::draw_pass_band_passive_S() {}

void FiltroPassaFaixa_passivo::draw_pass_band_passive_P() {}

void FiltroPassaFaixa_passivo::components_calc() {}
