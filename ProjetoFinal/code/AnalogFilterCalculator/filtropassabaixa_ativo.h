#ifndef FILTROPASSABAIXA_ATIVO_H
#define FILTROPASSABAIXA_ATIVO_H

#include "filtroativo.h"

class FiltroPassaBaixa_ativo : public FiltroAtivo {
    Q_OBJECT

public:
    explicit FiltroPassaBaixa_ativo(QWidget *parent = nullptr);

    FiltroPassaBaixa_ativo(QWidget *parent, float ganho, float fCent);

    void draw_low_pass_active();

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

    QPushButton *botaoReiniciar;

};

#endif
