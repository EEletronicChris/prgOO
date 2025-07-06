#include "filtrorejeitafaixa_passivo.h"

FiltroRejeitaFaixa_passivo::FiltroRejeitaFaixa_passivo(QWidget *parent) : FiltroPassivo(parent) {}

FiltroRejeitaFaixa_passivo::FiltroRejeitaFaixa_passivo(QWidget *parent, float fInf, float fSup) : FiltroPassivo(parent) {

    this->lower_cut_frequency = fInf;
    this->upper_cut_frequency = fSup;

    qDebug() << " fInf: " << lower_cut_frequency << " fSup:" << upper_cut_frequency;
}

void FiltroRejeitaFaixa_passivo::draw_reject_band_passive_P() {}

void FiltroRejeitaFaixa_passivo::draw_reject_band_passive_S() {}

void FiltroRejeitaFaixa_passivo::components_calc() {}
