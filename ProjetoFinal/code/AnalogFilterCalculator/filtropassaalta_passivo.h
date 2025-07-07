#ifndef FILTROPASSAALTA_PASSIVO_H
#define FILTROPASSAALTA_PASSIVO_H

#include "filtropassivo.h"

class FiltroPassaAlta_passivo : public FiltroPassivo {
    Q_OBJECT

public:
    explicit FiltroPassaAlta_passivo(QWidget *parent = nullptr);

    FiltroPassaAlta_passivo(QWidget *parent, float fCent);

    void draw_high_pass_passive_RC();

    void draw_high_pass_passive_RL();

    void components_calc();

private:
    double resistor_value;
    double capacitor_value;
    float inductor_value;
    bool inductor_presence;

    double central_frequency;

    QLabel *imageLabel;
    QLabel *resistor_label;
    QLabel *capacitor_label;

    QString floatToText;

    QPushButton *botaoReiniciar;
};

#endif
