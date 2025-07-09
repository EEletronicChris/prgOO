#ifndef FILTROPASSAFAIXA_PASSIVO_H
#define FILTROPASSAFAIXA_PASSIVO_H

#include "filtropassivo.h"

class FiltroPassaFaixa_passivo : public FiltroPassivo
{
    Q_OBJECT
public:
    explicit FiltroPassaFaixa_passivo(QWidget *parent = nullptr);

    FiltroPassaFaixa_passivo(QWidget *parent, double fInf, double fSup);

    void draw_pass_band_passive_S();

    void draw_pass_band_passive_P();

    void components_calc();

private:
    double resistor_value;
    double capacitor_value;
    double inductor_value;

    double lower_cut_frequency;
    double upper_cut_frequency;

    QLabel *imageLabel;
    QLabel *resistor_label;
    QLabel *capacitor_label;
    QLabel *inductor_label;

    QString doubleToText;

    QPushButton *botaoReiniciar;

};
#endif
