#ifndef FILTROPASSAFAIXA_PASSIVO_H
#define FILTROPASSAFAIXA_PASSIVO_H

#include "filtropassivo.h"

class FiltroPassaFaixa_passivo : public FiltroPassivo
{
    Q_OBJECT
public:
    explicit FiltroPassaFaixa_passivo(QWidget *parent = nullptr);

    FiltroPassaFaixa_passivo(QWidget *parent, float fInf, float fSup);

    void draw_pass_band_passive_S();

    void draw_pass_band_passive_P();

    void components_calc();

private:
    float resistor_value;
    float capacitor_value;
    float inductor_value;

    float lower_cut_frequency;
    float upper_cut_frequency;

    QLabel *imageLabel;
    QLabel *resistor_label;

    QString floatToText;

};
#endif
