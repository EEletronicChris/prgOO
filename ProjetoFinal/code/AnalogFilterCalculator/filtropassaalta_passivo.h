#ifndef FILTROPASSAALTA_PASSIVO_H
#define FILTROPASSAALTA_PASSIVO_H

#include "filtropassivo.h"

class FiltroPassaAlta_passivo : public FiltroPassivo {
    Q_OBJECT

public:
    explicit FiltroPassaAlta_passivo(QWidget *parent = nullptr);

    void draw_high_pass_passive_RC();

    void draw_high_pass_passive_RL();

    virtual void components_calc();

protected:
    float resistor_value;

    float capacitor_value;

    float inductor_value;

    bool inductor_presence;
};

#endif
