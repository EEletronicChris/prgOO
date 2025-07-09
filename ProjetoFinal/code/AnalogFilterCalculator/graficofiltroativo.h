#ifndef GRAFICOFILTROATIVO_H
#define GRAFICOFILTROATIVO_H

#include "filtroativo.h"


//#include <QtCharts> //avaliar o uso

    class GraficoFiltroAtivo : public FiltroAtivo {
    Q_OBJECT

public:
    explicit GraficoFiltroAtivo(QWidget *parent = nullptr);

    void draw_graph();

private:


};

#endif
