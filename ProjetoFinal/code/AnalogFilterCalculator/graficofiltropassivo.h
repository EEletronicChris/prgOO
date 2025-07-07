#ifndef GRAFICOFILTROPASSIVO_H
#define GRAFICOFILTROPASSIVO_H

#include "filtropassivo.h"
//#include <QtCharts>

class GraficoFiltroPassivo : public FiltroPassivo {
    Q_OBJECT

public:
    explicit GraficoFiltroPassivo(QWidget *parent = nullptr);

    void draw_graph();


};

#endif
