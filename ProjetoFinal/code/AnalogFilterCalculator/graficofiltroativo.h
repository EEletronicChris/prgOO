#ifndef GRAFICOFILTROATIVO_H
#define GRAFICOFILTROATIVO_H

#include "filtropassaalta_ativo.h"
#include "filtropassabaixa_ativo.h"
#include "filtropassafaixa_ativo.h"
#include "filtrorejeitafaixa_ativo.h"

#include <QMainWindow>
#include <QtCharts>

class GraficoFiltroAtivo : public QMainWindow {
    Q_OBJECT

public:
    explicit GraficoFiltroAtivo(QWidget *parent = nullptr);

    GraficoFiltroAtivo(QWidget *parent, double resistor_R_value, double resistor_i_value,
                       double resistor_f_value, double capacitor_value, double capacitor_1_value,
                       double capacitor_2_value);

    void draw_graph_passa_alta();

    void draw_graph_passa_baixa();

    void draw_graph_passa_faixa();

    void draw_graph_rejeita_faixa();

private:
    QChartView *chartView;
    QChart *chart;
    QLineSeries *serieMagnitude;
    QLogValueAxis *eixoX;
    QValueAxis *eixoY;

    double resistor_R_value;
    double resistor_i_value;
    double resistor_f_value;
    double capacitor_value;
    double capacitor_1_value;
    double capacitor_2_value;
};

#endif
