#ifndef FILTROPASSAFAIXA_ATIVO_H
#define FILTROPASSAFAIXA_ATIVO_H

#include "filtroativo.h"

class FiltroPassaFaixa_ativo : public FiltroAtivo
{
    Q_OBJECT
public:
    explicit FiltroPassaFaixa_ativo(QWidget *parent = nullptr);

    void draw_pass_band_active();

    virtual void components_calc();

protected:
    float resistor_R_value;

    float resistor_i_value;

    float resistor_f_value;

    float capacitor_1_value;

    float capacitor_2_value;
};

#endif


