#ifndef FILTROPASSAFAIXA_PASSIVO_H
#define FILTROPASSAFAIXA_PASSIVO_H

#include "filtropassivo.h"

class FiltroPassaFaixa_passivo : public FiltroPassivo
{
    Q_OBJECT
public:
    explicit FiltroPassaFaixa_passivo(QWidget *parent = nullptr);

    void draw_pass_band_passive_S();

    void draw_pass_band_passive_P();

    virtual void components_calc();

protected:
    float resistor_value;

    float capacitor_value;

    float inductor_value;

};
#endif
