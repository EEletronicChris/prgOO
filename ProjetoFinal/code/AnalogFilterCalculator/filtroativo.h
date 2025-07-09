#ifndef FILTROATIVO_H
#define FILTROATIVO_H

#include "filtros.h"

class FiltroAtivo : public Filtros
{
    Q_OBJECT
public:
    explicit FiltroAtivo(QWidget *parent = nullptr);

    FiltroAtivo(QWidget *parent, double ganho, double fInf, double fCent, double fSup, QString tipo);

    void get_gain_value();

    void filtro_plot_prepare_ativo();

private:
    double lower_cut_frequency;
    double upper_cut_frequency;
    double central_frequency;
    double gain_value;
    QString filter_type;


};

#endif
