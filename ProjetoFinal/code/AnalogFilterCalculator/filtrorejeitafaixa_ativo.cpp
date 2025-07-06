#include "filtrorejeitafaixa_ativo.h"

FiltroRejeitaFaixa_ativo::FiltroRejeitaFaixa_ativo(QWidget *parent) : FiltroAtivo(parent) {}

FiltroRejeitaFaixa_ativo::FiltroRejeitaFaixa_ativo(QWidget *parent, float ganho, float fInf, float fSup) : FiltroAtivo(parent) {
    this->gain_value = ganho;
    this->lower_cut_frequency = fInf;
    this->upper_cut_frequency = fSup;

    qDebug() << " fInf: " << lower_cut_frequency << " fSup:" << upper_cut_frequency <<  "ganho: " << gain_value;
}

void FiltroRejeitaFaixa_ativo::draw_reject_band_active() {}

void FiltroRejeitaFaixa_ativo::components_calc() {}

