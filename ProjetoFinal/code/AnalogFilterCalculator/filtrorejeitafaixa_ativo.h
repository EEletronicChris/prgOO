#ifndef FILTROREJEITAFAIXA_ATIVO_H
#define FILTROREJEITAFAIXA_ATIVO_H

#include "FiltroAtivo.h"

class FiltroRejeitaFaixa_ativo : public FiltroAtivo
{
    Q_OBJECT
public:
    explicit FiltroRejeitaFaixa_ativo(QWidget *parent = nullptr);

    FiltroRejeitaFaixa_ativo(QWidget *parent, float ganho, float fInf, float fSup);

    void draw_reject_band_active();

    void components_calc();

private:
    float resistor_R_value;
    float resistor_i_value;
    float resistor_f_value;
    float capacitor_1_value;
    float capacitor_2_value;

    float lower_cut_frequency;
    float upper_cut_frequency;
    float gain_value;
};


#endif
