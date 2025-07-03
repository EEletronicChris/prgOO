#ifndef FILTROPASSABAIXA_ATIVO_H
#define FILTROPASSABAIXA_ATIVO_H

#include "filtroativo.h"

class FiltroPassaBaixa_ativo : public FiltroAtivo {
    Q_OBJECT

public:
    explicit FiltroPassaBaixa_ativo(QWidget *parent = nullptr);

    void draw_low_pass_active();

   virtual void components_calc();

protected:
    float resistor_i_value;

    float resistor_f_value;

    float capacitor_value;

};

#endif
