#ifndef FILTROREJEITAFAIXA_PASSIVO_H
#define FILTROREJEITAFAIXA_PASSIVO_H

#include "filtropassivo.h"

class FiltroRejeitaFaixa_passivo : public FiltroPassivo
{
    Q_OBJECT
public:
    explicit FiltroRejeitaFaixa_passivo(QWidget *parent = nullptr);

    FiltroRejeitaFaixa_passivo(QWidget *parent, float fInf, float fSup);

    void draw_reject_band_passive_S();

    void draw_reject_band_passive_P();

    void components_calc();

private:
    float resistor_value;
    float capacitor_value;
    float inductor_value;

    float lower_cut_frequency;
    float upper_cut_frequency;
};

#endif
