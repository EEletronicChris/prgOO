#ifndef FILTROPASSABAIXA_PASSIVO_H
#define FILTROPASSABAIXA_PASSIVO_H

#include "filtropassivo.h"

class FiltroPassaBaixa_passivo : public FiltroPassivo {
    Q_OBJECT

public:
    explicit FiltroPassaBaixa_passivo(QWidget *parent = nullptr);

    FiltroPassaBaixa_passivo(QWidget *parent,float fCent);

    void draw_low_pass_passive_RC();

    void draw_low_pass_passive_RL();

    void components_calc();

private:
    float resistor_value;
    float capacitor_value;
    float inductor_value;
    bool inductor_presence;

    float central_frequency;

    QLabel *imageLabel;
    QLabel *resistor_i_label;

    QString floatToText;

};

#endif
