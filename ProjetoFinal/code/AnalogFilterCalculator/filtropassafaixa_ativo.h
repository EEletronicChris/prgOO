#ifndef FILTROPASSAFAIXA_ATIVO_H
#define FILTROPASSAFAIXA_ATIVO_H

#include "filtroativo.h"

class FiltroPassaFaixa_ativo : public FiltroAtivo
{
    Q_OBJECT
public:
    explicit FiltroPassaFaixa_ativo(QWidget *parent = nullptr);

    FiltroPassaFaixa_ativo(QWidget *parent, double ganho, double fInf, double fSup);

    void draw_pass_band_active();

    void components_calc();

private:
    double resistor_R_value;
    double resistor_i_value;
    double resistor_f_value;
    double capacitor_1_value;
    double capacitor_2_value;

    double lower_cut_frequency;
    double upper_cut_frequency;
    double gain_value;

    QLabel *imageLabel;
    QLabel *resistor_R_label;
    QLabel *resistor_i_label;
    QLabel *resistor_f_label;
    QLabel *capacitor_1_label;
    QLabel *capacitor_2_label;
    QLabel *resistor_R1_label;
    QLabel *resistor_R2_label;
    QLabel *resistor_R3_label;
    QLabel *resistor_R4_label;

    QString doubleToText;

    QPushButton *botaoReiniciar;
    QPushButton *botaoGrafico;

private slots:
    void prepare_graph();
};

#endif


