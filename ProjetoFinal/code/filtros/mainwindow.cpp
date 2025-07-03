#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
    this->resize(550, 350);
    this->setWindowTitle("Projeto de Filtros");

    // Botões
    btnPassivo = new QPushButton("Filtros Passivos", this);
    btnAtivo = new QPushButton("Filtros Ativos", this);
    btnPassivo->move(10, 10);
    btnPassivo->resize(120, 30);
    btnAtivo->move(140, 10);
    btnAtivo->resize(120, 30);

    // ComboBox
    comboBox = new QComboBox(this);
    comboBox->move(10, 50);
    comboBox->resize(250, 25);

    // Instâncias das classes auxiliares
    filtros = new Filtros(this);
    filtroAtivo = new FiltroAtivo();
    filtroPassivo = new FiltroPassivo();
    filtroImagemAtivo = new FiltroPassaBaixa_ativo();
    filtroImagemPassivo = new FiltroPassaBaixa_passivo();

    // Conexões
    connect(btnPassivo, SIGNAL(clicked()), this, SLOT(carregarPassivos()));
    connect(btnAtivo, SIGNAL(clicked()), this, SLOT(carregarAtivos()));
    connect(comboBox, SIGNAL(currentTextChanged(QString)), this, SLOT(filtroSelecionado(QString)));
}

void MainWindow::carregarPassivos() {
    filtros->carregarPassivos(comboBox);
}

void MainWindow::carregarAtivos() {
    filtros->carregarAtivos(comboBox);
}

void MainWindow::filtroSelecionado(const QString &text) {
    filtroAtivo->atualizarCampos(this, text);
    filtroPassivo->atualizarCampos(this, text);
    filtroImagemAtivo->exibirImagem(this, text);
    filtroImagemPassivo->exibirImagem(this, text);
}
