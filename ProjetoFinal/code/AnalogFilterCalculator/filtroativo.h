#ifndef FILTROATIVO_H
#define FILTROATIVO_H

#include "filtros.h"

class FiltroAtivo : public Filtros
{
    Q_OBJECT
public:
    explicit FiltroAtivo(QWidget *parent = nullptr);

    FiltroAtivo(QWidget *parent, float ganho, float fInf, float fCent, float fSup);

    virtual void get_gain_value();

    virtual void filtro_plot_prepare_ativo();

private:
    float lower_cut_frequency;
    float upper_cut_frequency;
    float central_frequency;
    float gain_value;


};

#endif
