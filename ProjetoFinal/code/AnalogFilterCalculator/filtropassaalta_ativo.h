#ifndef FILTROPASSAALTA_ATIVO_H
#define FILTROPASSAALTA_ATIVO_H

#include "filtroativo.h"
#include "graficofiltroativo.h"

class FiltroPassaAlta_ativo : public FiltroAtivo {
    Q_OBJECT

public:
    explicit FiltroPassaAlta_ativo(QWidget *parent = nullptr);

    FiltroPassaAlta_ativo(QWidget *parent, double ganho, double fCent);

    void draw_high_pass_active();

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
