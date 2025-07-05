#include "filtros.h"


Filtros::Filtros(QWidget *parent) :
    QWidget(parent), botaoPassivo(nullptr), botaoAtivo(nullptr), filtersType_combo(nullptr),
    centralFreq_edit(nullptr), centralFreq_label(nullptr), supFreq_edit(nullptr),
    supFreq_label(nullptr), infFreq_edit(nullptr), infFreq_label(nullptr), gainValue_edit(nullptr),
    gainValue_label(nullptr)    //Avaliar retirar variaveis-membro
{
    // Criação dos Widgets
    centralFreq_edit    = new QLineEdit(this);
    centralFreq_label   = new QLabel("Frequência de corte (Hz):", this);
    supFreq_edit        = new QLineEdit(this);
    supFreq_label       = new QLabel("Frequência de corte superior (Hz):", this);
    infFreq_edit        = new QLineEdit(this);
    infFreq_label       = new QLabel("Frequência de corte inferior (Hz):", this);
    gainValue_edit      = new QLineEdit(this);
    gainValue_label     = new QLabel("Ganho:", this);


    // Posicionamento e tamanho do W idget
    centralFreq_label->move(10, 90);
    centralFreq_label->resize(180, 30);
    centralFreq_edit->move(216, 90);
    centralFreq_edit->resize(100, 30);

    supFreq_label->move(10, 130);
    supFreq_label->resize(180, 30);
    supFreq_edit->move(216, 130);
    supFreq_edit->resize(100, 30);

    infFreq_label->move(10, 90);
    infFreq_label->resize(180, 30);
    infFreq_edit->move(216, 90);
    infFreq_edit->resize(100, 30);

    gainValue_edit->resize(100, 30);
    gainValue_label->resize(180, 30);

    // Esconde inicialmente
    centralFreq_edit->hide();
    centralFreq_label->hide();
    supFreq_edit->hide();
    supFreq_label->hide();
    infFreq_edit->hide();
    infFreq_label->hide();
    gainValue_edit->hide();
    gainValue_label->hide();
}

void Filtros::get_filter_type()
{
    // Criação de botões e comboBox
    botaoPassivo        = new QPushButton("Calcular um Filtro Passivo", this);
    botaoAtivo          = new QPushButton("Calcular um Filtro Ativo", this);
    botaoConfirmAll     = new QPushButton("Confirmar",this);
    filtersType_combo   = new QComboBox(this);

    // Posicionamento e tamanho
    botaoPassivo->move(10, 10);
    botaoPassivo->resize(200, 30);
    botaoAtivo->move(220, 10);
    botaoAtivo->resize(200, 30);
    filtersType_combo->move(115, 50);
    filtersType_combo->resize(200, 30);
    botaoConfirmAll->resize(94,30);

    // Exibe
    botaoPassivo->show();
    botaoAtivo->show();
    filtersType_combo->show();

    // Esconde
    botaoConfirmAll->hide();

    // Signal & Slots conexões
    connect(botaoPassivo, &QPushButton::clicked, this, &Filtros::carregarFiltrosPassivos);
    connect(botaoAtivo, &QPushButton::clicked, this, &Filtros::carregarFiltrosAtivos);
    connect(filtersType_combo, &QComboBox::currentTextChanged, this, &Filtros::atualizarFiltroSelecionado);
}

void Filtros::get_lower_cut_frequency()
{
    infFreq_edit->show();
    infFreq_label->show();

    if (filtersType_combo->currentText().contains("Ativo")) {
        gainValue_label->move(10, 170);
        gainValue_edit->move(216, 170);
        botaoConfirmAll->move(326, 170);

        gainValue_edit->show();
        gainValue_label->show();
    } else{
        botaoConfirmAll->move(326, 130);
    }
}

void Filtros::get_upper_cut_frequency()
{
    hide_all_edit();

    supFreq_edit->show();
    supFreq_label->show();
}

void Filtros::get_central_frequency()
{
    hide_all_edit();

    centralFreq_edit->show();
    centralFreq_label->show();
    botaoConfirmAll->show();

    if (filtersType_combo->currentText().contains("Ativo")){
        gainValue_label->move(10, 130);
        gainValue_edit->move(216, 130);
        botaoConfirmAll->move(326, 130);

        gainValue_edit->show();
        gainValue_label->show();
    } else {
        botaoConfirmAll->move(326, 90);
    }
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
    if (filter_type == "Filtro Passivo Passa-baixa" || filter_type == "Filtro Ativo Passa-baixa" || filter_type == "Filtro Passivo Passa-alta"  || filter_type == "Filtro Ativo Passa-alta") {
        get_central_frequency();
    }
    if (filter_type == "Filtro Passivo Rejeita-faixa" || filter_type == "Filtro Ativo Rejeita-faixa" || filter_type == "Filtro Passivo Passa-faixa"  || filter_type == "Filtro Ativo Passa-faixa"){
        get_upper_cut_frequency();
        get_lower_cut_frequency();
    }
}

void Filtros::hide_all_edit()
{
    centralFreq_edit->hide();
    centralFreq_label->hide();
    supFreq_edit->hide();
    supFreq_label->hide();
    infFreq_edit->hide();
    infFreq_label->hide();
    gainValue_edit->hide();
    gainValue_label->hide();
}
