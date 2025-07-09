#ifndef FILTROPASSIVO_H
#define FILTROPASSIVO_H

#include "filtros.h"

class FiltroPassivo : public Filtros {
    Q_OBJECT

public:
    explicit FiltroPassivo(QWidget *parent = nullptr);

    FiltroPassivo(QWidget *parent, double fInf, double fCent, double fSup, QString tipo);

    void get_component_preference();

    void get_choose_S_P();

    void filtro_plot_prepare_passivo();

private:
    bool component_preference;
    bool choose_S_P;

    double lower_cut_frequency;
    double upper_cut_frequency;
    double central_frequency;
    double gain_value;
    QString filter_type;
};

#endif
