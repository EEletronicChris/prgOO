#ifndef FILTROPASSAFAIXA_ATIVO_H
#define FILTROPASSAFAIXA_ATIVO_H

#include "filtroativo.h"

class FiltroPassaFaixa_ativo : public FiltroAtivo
{
    Q_OBJECT
public:
    explicit FiltroPassaFaixa_ativo(QWidget *parent = nullptr);

    FiltroPassaFaixa_ativo(QWidget *parent, float ganho, float fInf, float fSup);

    void draw_pass_band_active();

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

    QLabel *imageLabel;
    QLabel *resistor_R_label;

    QString floatToText;

    QPushButton *botaoReiniciar;
};

#endif


