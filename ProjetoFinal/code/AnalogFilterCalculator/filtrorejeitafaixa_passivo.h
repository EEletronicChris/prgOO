#ifndef FILTROREJEITAFAIXA_PASSIVO_H
#define FILTROREJEITAFAIXA_PASSIVO_H

#include "filtropassivo.h"

class FiltroRejeitaFaixa_passivo : public FiltroPassivo
{
    Q_OBJECT
public:
    explicit FiltroRejeitaFaixa_passivo(QWidget *parent = nullptr);

    void draw_reject_band_passive_S();

    void draw_reject_band_passive_P();

    virtual void components_calc();

protected:
    float resistor_value;

    float capacitor_value;

    float inductor_value;
};

#endif
