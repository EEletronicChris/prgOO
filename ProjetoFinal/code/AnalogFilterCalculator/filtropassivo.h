#ifndef FILTROPASSIVO_H
#define FILTROPASSIVO_H

#include "filtros.h"

class FiltroPassivo : public Filtros {
    Q_OBJECT

public:
    explicit FiltroPassivo(QWidget *parent = nullptr);

    FiltroPassivo(QWidget *parent, float fInf, float fCent, float fSup, QString tipo);

    void get_component_preference();

    void get_choose_S_P();

    void filtro_plot_prepare_passivo();

private:
    bool component_preference;
    bool choose_S_P;

    float lower_cut_frequency;
    float upper_cut_frequency;
    float central_frequency;
    float gain_value;
    QString filter_type;
};

#endif
