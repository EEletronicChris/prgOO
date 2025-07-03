#ifndef FILTROREJEITAFAIXA_ATIVO_H
#define FILTROREJEITAFAIXA_ATIVO_H

#include "FiltroAtivo.h"

class FiltroRejeitaFaixa_ativo : public FiltroAtivo
{
    Q_OBJECT
public:
    explicit FiltroRejeitaFaixa_ativo(QWidget *parent = nullptr);

    void draw_reject_band_active();

    virtual void components_calc();

protected:
    float resistor_R_value;

    float resistor_i_value;

    float resistor_f_value;

    float capacitor_1_value;

    float capacitor_2_value;

};


#endif
