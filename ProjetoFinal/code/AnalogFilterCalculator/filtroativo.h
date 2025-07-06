#ifndef FILTROATIVO_H
#define FILTROATIVO_H

#include "filtros.h"

class FiltroAtivo : public Filtros
{
    Q_OBJECT
public:
    explicit FiltroAtivo(QWidget *parent = nullptr);

    void get_gain_value();

    virtual void filtro_plot_prepare_ativo();

protected:
    float gain_value;
};

#endif
