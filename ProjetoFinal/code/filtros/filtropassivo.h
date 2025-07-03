#ifndef FILTROPASSIVO_H
#define FILTROPASSIVO_H

#include <QLineEdit>
#include <QLabel>
#include <QString>
#include <QWidget>
#include "filtros.h"

class FiltroPassivo : public Filtros {
public:
    FiltroPassivo();
    void atualizarCampos(QWidget *parent, const QString &tipoFiltro);

private:

};

#endif // FILTROPASSIVO_H
