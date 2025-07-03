#ifndef FILTROPASSIVO_H
#define FILTROPASSIVO_H

#include <QLineEdit>
#include <QLabel>
#include <QString>
#include <QWidget>

class FiltroPassivo {
public:
    FiltroPassivo();
    void atualizarCampos(QWidget *parent, const QString &tipoFiltro);

private:
    QLineEdit *freqInfEdit;
    QLineEdit *freqSupEdit;
    QLabel *freqInfLabel;
    QLabel *freqSupLabel;

    void esconderCampos();
};

#endif // FILTROPASSIVO_H
