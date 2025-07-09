#include "filtros.h"
#include "filtroativo.h"
#include "filtropassivo.h"


Filtros::Filtros(QWidget *parent) :
    QWidget(parent), botaoPassivo(nullptr), botaoAtivo(nullptr), filtersType_combo(nullptr),
    centralFreq_edit(nullptr), centralFreq_label(nullptr), supFreq_edit(nullptr),
    supFreq_label(nullptr), infFreq_edit(nullptr), infFreq_label(nullptr), gainValue_edit(nullptr),
    gainValue_label(nullptr)    //Avaliar retirar variaveis-membro
{
    this->setFixedSize(1300,650);
    // Criação dos Widgets
    // Botões
    botaoPassivo        = new QPushButton("Calcular um Filtro Passivo", this);
    botaoAtivo          = new QPushButton("Calcular um Filtro Ativo", this);
    botaoConfirmAll     = new QPushButton("Confirmar",this);
    // comboBox
    filtersType_combo   = new QComboBox(this);
    // LineEdits
    centralFreq_edit    = new QLineEdit(this);
    supFreq_edit        = new QLineEdit(this);
    infFreq_edit        = new QLineEdit(this);
    gainValue_edit      = new QLineEdit(this);
    // Labels
    centralFreq_label   = new QLabel("Frequência de corte (Hz):", this);
    supFreq_label       = new QLabel("Frequência de corte superior (Hz):", this);
    infFreq_label       = new QLabel("Frequência de corte inferior (Hz):", this);
    gainValue_label     = new QLabel("Ganho:", this);


    // Posicionamento e tamanho do Widgets
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

    botaoPassivo->move(10, 10);
    botaoPassivo->resize(200, 30);
    botaoAtivo->move(220, 10);
    botaoAtivo->resize(200, 30);
    botaoConfirmAll->resize(94,30);

    filtersType_combo->move(115, 50);
    filtersType_combo->resize(200, 30);

    gainValue_edit->resize(100, 30);
    gainValue_label->resize(180, 30);

    // Cor dos Widgets
    botaoPassivo->setStyleSheet("background-color: #1C1C1C");
    botaoAtivo->setStyleSheet("background-color: #1C1C1C");
    botaoConfirmAll->setStyleSheet("background-color: #1C1C1C");
    filtersType_combo->setStyleSheet("background-color: #1C1C1C");

    // Esconde inicialmente
    hide_all_edit();
    botaoConfirmAll->hide();

    // Exibe
    botaoPassivo->show();
    botaoAtivo->show();
    filtersType_combo->show();

    // Signal & Slots conexões
    connect(botaoPassivo, &QPushButton::clicked, this, &Filtros::carregarFiltrosPassivos);
    connect(botaoAtivo, &QPushButton::clicked, this, &Filtros::carregarFiltrosAtivos);
    connect(filtersType_combo, &QComboBox::currentTextChanged, this, &Filtros::get_filter_type);
    connect(botaoConfirmAll, &QPushButton::clicked,this,&Filtros::confirmarFiltroSelecionado);
}

void Filtros::get_filter_type()
{
    filter_type = filtersType_combo->currentText();
    if (filter_type == "Filtro Passivo Passa-baixa" || filter_type == "Filtro Ativo Passa-baixa" || filter_type == "Filtro Passivo Passa-alta"  || filter_type == "Filtro Ativo Passa-alta") {
        show_one_freq_edit();
    }
    if (filter_type == "Filtro Passivo Rejeita-faixa" || filter_type == "Filtro Ativo Rejeita-faixa" || filter_type == "Filtro Passivo Passa-faixa"  || filter_type == "Filtro Ativo Passa-faixa"){
        show_both_freq_edit();
    }
}

void Filtros::get_lower_cut_frequency()
{
    lower_cut_frequency = infFreq_edit->text().toFloat();

    qDebug() << "Frequência inferior: " << lower_cut_frequency;

}

void Filtros::get_upper_cut_frequency()
{
    upper_cut_frequency = supFreq_edit->text().toFloat();

    qDebug() << "Frequência superior: " << upper_cut_frequency;
}

void Filtros::get_central_frequency()
{
    central_frequency = centralFreq_edit->text().toFloat();

    qDebug() << "Frequência central: " << central_frequency;
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

void Filtros::confirmarFiltroSelecionado()
{
    get_central_frequency();
    get_upper_cut_frequency();
    get_lower_cut_frequency();
    gain_value = gainValue_edit->text().toFloat();

    // Verifica se Input é float
    if (central_frequency == 0 && (upper_cut_frequency == 0 || lower_cut_frequency == 0)){
        QMessageBox::about(this,"", "Insira um valor de frequência e/ou ganho válido.");
    } else if ((filter_type.contains("faixa")) && (upper_cut_frequency < lower_cut_frequency)){
        QMessageBox::about(this,"", "A frequênia de corte superior deve ser maior que a frequência de corte inferior.");
    } else if ((filter_type.contains("Ativo")) && (gain_value <= 0)){
        QMessageBox::about(this,"", "O ganho deve ser maior que 0.");
    } else {
        hide_all_edit();
        botaoConfirmAll->hide();
        botaoAtivo->hide();
        botaoPassivo->hide();
        filtersType_combo->hide();

        if (filter_type.contains("Ativo")) {
            FiltroAtivo *filtroConfig_ativo = new FiltroAtivo(this, gain_value, lower_cut_frequency, central_frequency, upper_cut_frequency, filter_type);
            filtroConfig_ativo->filtro_plot_prepare_ativo();
            filtroConfig_ativo->show();
        } else{
            FiltroPassivo *filtroConfig_passivo = new FiltroPassivo(this, lower_cut_frequency, central_frequency, upper_cut_frequency, filter_type);
            filtroConfig_passivo->filtro_plot_prepare_passivo();
            filtroConfig_passivo->show();
        }
    }
}


void Filtros::show_both_freq_edit()
{
    hide_all_edit();

    supFreq_edit->show();
    supFreq_label->show();
    infFreq_edit->show();
    infFreq_label->show();

    if (filter_type.contains("Ativo")) {
        gainValue_label->move(10, 170);
        gainValue_edit->move(216, 170);
        botaoConfirmAll->move(326, 170);

        gainValue_edit->show();
        gainValue_label->show();
    } else{
        botaoConfirmAll->move(326, 130);
    }
}
void Filtros::show_one_freq_edit()
{
    hide_all_edit();

    centralFreq_edit->show();
    centralFreq_label->show();
    botaoConfirmAll->show();

    if (filter_type.contains("Ativo")){
        gainValue_label->move(10, 130);
        gainValue_edit->move(216, 130);
        botaoConfirmAll->move(326, 130);

        gainValue_edit->show();
        gainValue_label->show();
    } else {
        botaoConfirmAll->move(326, 90);
    }

}

void Filtros::resetarInterface()
{
    // Fecha e deleta todos os filhos que não são os widgets principais
    const auto childrenList = this->findChildren<QWidget *>(QString(), Qt::FindDirectChildrenOnly);
    for (QWidget *child : childrenList) {
        if (child != botaoPassivo && child != botaoAtivo &&
            child != filtersType_combo && child != botaoConfirmAll &&
            child != centralFreq_edit && child != centralFreq_label &&
            child != supFreq_edit && child != supFreq_label &&
            child != infFreq_edit && child != infFreq_label &&
            child != gainValue_edit && child != gainValue_label) { child->deleteLater(); }
    }

    // Esconde todos os campos
    hide_all_edit();

    // Restaura os botões e comboBox
    botaoPassivo->show();
    botaoAtivo->show();
    filtersType_combo->show();
    botaoConfirmAll->hide();

    // Limpa os campos
    centralFreq_edit->clear();
    supFreq_edit->clear();
    infFreq_edit->clear();
    gainValue_edit->clear();
    filtersType_combo->setCurrentIndex(-1);

    lower_cut_frequency = 0;
    upper_cut_frequency = 0;
    central_frequency = 0;
    gain_value = 0;
}
