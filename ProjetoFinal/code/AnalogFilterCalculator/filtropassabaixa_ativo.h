#ifndef FILTROPASSABAIXA_ATIVO_H
#define FILTROPASSABAIXA_ATIVO_H

#include "filtroativo.h"

class FiltroPassaBaixa_ativo : public FiltroAtivo {
    Q_OBJECT

public:
    explicit FiltroPassaBaixa_ativo(QWidget *parent = nullptr);

    FiltroPassaBaixa_ativo(QWidget *parent, double ganho, double fCent);

    void draw_low_pass_active();

    void components_calc();

private:
    double resistor_i_value;
    double resistor_f_value;
    double capacitor_value;

    double central_frequency;
    double gain_value;
    QLabel *imageLabel;
    QLabel *resistor_i_label;
    QLabel *resistor_f_label;
    QLabel *capacitor_label;

    QString doubleToText;

    QPushButton *botaoReiniciar;
    QPushButton *botaoGrafico;

private slots:
    void prepare_graph();

};

#endif
