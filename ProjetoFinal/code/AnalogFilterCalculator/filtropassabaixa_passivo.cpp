#include "FiltroPassaBaixa_passivo.h"

FiltroPassaBaixa_passivo::FiltroPassaBaixa_passivo(QWidget *parent) : FiltroPassivo(parent) {}

FiltroPassaBaixa_passivo::FiltroPassaBaixa_passivo(QWidget *parent, float fCent) : FiltroPassivo(parent) {

    this->central_frequency = fCent;

    qDebug() << " central: " << central_frequency;
}

void FiltroPassaBaixa_passivo::draw_low_pass_passive_RC() {}

void FiltroPassaBaixa_passivo::draw_low_pass_passive_RL() {}

void FiltroPassaBaixa_passivo::components_calc() {}
