#ifndef FILTROPASSAALTA_ATIVO_H
#define FILTROPASSAALTA_ATIVO_H

#include "filtroativo.h"

class FiltroPassaAlta_ativo : public FiltroAtivo {
    Q_OBJECT

public:
    explicit FiltroPassaAlta_ativo(QWidget *parent = nullptr);

    FiltroPassaAlta_ativo(QWidget *parent, float ganho, float fCent);

    void draw_high_pass_active();

    void components_calc();

private:
    float resistor_i_value;
    float resistor_f_value;
    float capacitor_value;

    float central_frequency;
    float gain_value;
    QLabel *imageLabel;
    QLabel *resistor_i_label;

    QString floatToText;
};

#endif
