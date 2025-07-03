#ifndef GRAFICOFILTROPASSIVO_H
#define GRAFICOFILTROPASSIVO_H

#include "FiltroPassivo.h"
//#include <QtCharts>

class GraficoFiltroPassivo : public FiltroPassivo {
    Q_OBJECT

public:
    explicit GraficoFiltroPassivo(QWidget *parent = nullptr);

    virtual void draw_graph();

protected:

};

#endif
