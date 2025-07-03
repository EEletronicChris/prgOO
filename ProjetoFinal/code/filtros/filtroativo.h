#ifndef FILTROATIVO_H
#define FILTROATIVO_H

#include <QLineEdit>
#include <QLabel>
#include <QString>
#include <QWidget>

class FiltroAtivo {
public:
    FiltroAtivo();
    void atualizarCampos(QWidget *parent, const QString &tipoFiltro);

private:
    QLineEdit *ganhoEdit;
    QLabel *ganhoLabel;
    QLineEdit *frequenciaEdit;
    QLabel *frequenciaLabel;

    void esconderCampos();
};

#endif // FILTROATIVO_H
