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
    double resistor_value;
    double capacitor_value;
    double inductor_value;

    double lower_cut_frequency;
    double upper_cut_frequency;

    QLabel *imageLabel;
    QLabel *resistor_label;
    QLabel *capacitor_label;
    QLabel *inductor_label;

    QString floatToText;

    QPushButton *botaoReiniciar;
};

#endif
