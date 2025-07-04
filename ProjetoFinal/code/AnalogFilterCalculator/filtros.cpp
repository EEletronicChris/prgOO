#include "Filtros.h"



Filtros::Filtros(QWidget *parent) : QWidget(parent), botaoPassivo(nullptr), botaoAtivo(nullptr), filtersType_combo(nullptr) {}

// Trocar para seleção manual de tamanho
void Filtros::get_filter_type()
{
    // Criação de botões e comboBox
    botaoPassivo        = new QPushButton("Calcular um Filtro Passivo", this);
    botaoAtivo          = new QPushButton("Calcular um Filtro Ativo", this);
    filtersType_combo   = new QComboBox(this);

    // Posicionamento e tamanho
    botaoPassivo->move(10, 10);
    botaoPassivo->resize(200, 30);
    botaoAtivo->move(220, 10);
    botaoAtivo->resize(200, 30);
    filtersType_combo->move(115, 50);
    filtersType_combo->resize(200, 30);

    // Exibe
    botaoPassivo->show();
    botaoAtivo->show();
    filtersType_combo->show();

    // Conexões
    connect(botaoPassivo, &QPushButton::clicked, this, &Filtros::carregarFiltrosPassivos);
    connect(botaoAtivo, &QPushButton::clicked, this, &Filtros::carregarFiltrosAtivos);
    connect(filtersType_combo, &QComboBox::currentTextChanged, this, &Filtros::atualizarFiltroSelecionado);
}

void Filtros::get_lower_cut_frequency() {}

void Filtros::get_upper_cut_frequency() {}

void Filtros::get_central_frequency()
{

}


void Filtros::carregarFiltrosPassivos()
{
    filtersType_combo->clear();
    filtersType_combo->addItem("Filtro Passivo Passa-baixa");
    filtersType_combo->addItem("Filtro Passivo Passa-alta");
    filtersType_combo->addItem("Filtro Passivo Rejeita-faixa");
    filtersType_combo->addItem("Filtro Passivo Passa-faixa");
}

void Filtros::carregarFiltrosAtivos()
{
    filtersType_combo->clear();
    filtersType_combo->addItem("Filtro Ativo Passa-baixa");
    filtersType_combo->addItem("Filtro Ativo Passa-alta");
    filtersType_combo->addItem("Filtro Ativo Rejeita-faixa");
    filtersType_combo->addItem("Filtro Ativo Passa-faixa");
}

void Filtros::atualizarFiltroSelecionado()
{
    filter_type = filtersType_combo->currentText();
    qDebug() << "Filtro selecionado:" << filter_type;

}



