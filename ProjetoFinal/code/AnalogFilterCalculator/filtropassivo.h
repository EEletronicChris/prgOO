#ifndef FILTROPASSIVO_H
#define FILTROPASSIVO_H

#include "filtros.h"

class FiltroPassivo : public Filtros {
    Q_OBJECT

public:
    explicit FiltroPassivo(QWidget *parent = nullptr);

    void get_component_preference();

    void get_choose_S_P();

    void filtro_plot_prepare_passivo();

protected:
    bool component_preference;
    bool choose_S_P;
};

#endif
