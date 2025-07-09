#ifndef FILTROPASSABAIXA_PASSIVO_H
#define FILTROPASSABAIXA_PASSIVO_H

#include "filtropassivo.h"
#include "graficofiltropassivo.h"

class FiltroPassaBaixa_passivo : public FiltroPassivo {
    Q_OBJECT

public:
    explicit FiltroPassaBaixa_passivo(QWidget *parent = nullptr);

    FiltroPassaBaixa_passivo(QWidget *parent,double fCent);

    void draw_low_pass_passive_RC();

    void draw_low_pass_passive_RL();

    void components_calc();

private:
    double resistor_value;
    double capacitor_value;
    double inductor_value;
    bool inductor_presence;

    double central_frequency;

    QLabel *imageLabel;
    QLabel *resistor_label;
    QLabel *capacitor_label;

    QString doubleToText;

    QPushButton *botaoReiniciar;

};

#endif
