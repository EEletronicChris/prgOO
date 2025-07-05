#ifndef FILTROATIVO_H
#define FILTROATIVO_H

#include "filtros.h"

class FiltroAtivo : public Filtros
{
    Q_OBJECT
public:
    explicit FiltroAtivo(QWidget *parent = nullptr);

    void get_gain_value();

protected:
    float gain_value;
};

#endif
