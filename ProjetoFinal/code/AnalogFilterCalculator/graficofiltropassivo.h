#ifndef GRAFICOFILTROPASSIVO_H
#define GRAFICOFILTROPASSIVO_H

#include "filtropassaalta_passivo.h"
#include "filtropassabaixa_passivo.h"
#include "filtropassafaixa_passivo.h"
#include "filtrorejeitafaixa_passivo.h"

#include <QMainWindow>
#include <QtCharts>

class GraficoFiltroPassivo : public QMainWindow {
    Q_OBJECT

public:
    explicit GraficoFiltroPassivo(QWidget *parent = nullptr);

    GraficoFiltroPassivo(QWidget *parent, double R, double C);

    GraficoFiltroPassivo(QWidget *parent, double R, double C, double L);

    void draw_graph_passa_alta();

    void draw_graph_passa_baixa();

    void draw_graph_passa_faixa();

    void draw_graph_rejeita_faixa();

private:
    QChartView *chartView;
    QChart *chart;
    QLineSeries *serieMagnitude;

    double resistor_value;
    double capacitor_value;
    double inductor_value;


};

#endif // GRAFICOFILTROPASSIVO_H
