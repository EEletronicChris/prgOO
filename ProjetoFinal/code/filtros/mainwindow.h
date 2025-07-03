#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QComboBox>

#include "filtros.h"
#include "filtroativo.h"
#include "filtropassivo.h"
#include "filtropassabaixa_ativo.h"
#include "filtropassabaixa_passivo.h"

class MainWindow : public QWidget {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void carregarPassivos();
    void carregarAtivos();
    void filtroSelecionado(const QString &text);

private:
    QPushButton *btnPassivo;
    QPushButton *btnAtivo;
    QComboBox *comboBox;

    Filtros *filtros;
    FiltroAtivo *filtroAtivo;
    FiltroPassivo *filtroPassivo;
    FiltroPassaBaixa_ativo *filtroImagemAtivo;
    FiltroPassaBaixa_passivo *filtroImagemPassivo;
};

#endif // MAINWINDOW_H
