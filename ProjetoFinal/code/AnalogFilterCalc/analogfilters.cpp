#include "analogfilters.h"
#include "filtroativo.h"

analogFilters::analogFilters(QWidget *parent) : QWidget(parent), filterType_combo(nullptr)
{
    passiveFilter_button     = new QPushButton("Filtros Passivos", this);
    activeFilter_button      = new QPushButton("Filtros Ativos", this);
    filterTypeConfirm_button = new QPushButton("Confirmar",this);
    reInit_button            = new QPushButton("Reiniciar",this);

    passiveFilter_button -> resize(100, 30);
    activeFilter_button  -> resize(100, 30);
    filterTypeConfirm_button -> resize(68,30);
    reInit_button -> resize(80,30);

    filterTypeConfirm_button -> hide();


    connect(passiveFilter_button, &QPushButton::clicked, this, &analogFilters::showComboPassives);
    connect(activeFilter_button, &QPushButton::clicked, this, &analogFilters::showComboActives);
    connect(filterTypeConfirm_button, &QPushButton::clicked, this, &analogFilters::saveFilterType);

    reposicionarElementos();
}

void analogFilters::showComboPassives()
{
    if (! filterType_combo){
        filterType_combo = new QComboBox(this);
        filterType_combo -> resize(125, 30);
    } else{
        filterType_combo -> clear();
    }

    filterType_combo -> addItem("Passa-baixa Passivo");
    filterType_combo -> addItem("Passa-alta Passivo");
    filterType_combo -> addItem("Passa-faixa Passivo");
    filterType_combo -> addItem("Rejeita-faixa Passivo");
    filterType_combo -> show();
    filterTypeConfirm_button -> show();     // Botão de confirmação
    reposicionarElementos();
}

void analogFilters::showComboActives()
{
    if (! filterType_combo){
        filterType_combo = new QComboBox(this);
        filterType_combo -> resize(150, 30);
    }else{
        filterType_combo -> clear();
    }

    filterType_combo -> addItem("Passa-baixa Ativo");
    filterType_combo -> addItem("Passa-alta Ativo");
    filterType_combo -> addItem("Passa-faixa Ativo");
    filterType_combo -> addItem("Rejeita-faixa Ativo");
    filterType_combo -> show();
    filterTypeConfirm_button -> show();     // Botão de confirmação
    reposicionarElementos();
}

void analogFilters::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    reposicionarElementos();
}

void analogFilters::saveFilterType()
{
    if (filterType_combo) {
        filterType_savings = filterType_combo->currentText();
    }

}


void analogFilters::reInitAplication()
{
    // Deve ser a última função a ser implementada. Deve conter a opção de reiniciar tendo em vista todos os casos de uso.
}

void analogFilters::reposicionarElementos()
{
    int spacing = 20;

    passiveFilter_button -> move(20 , 20);
    activeFilter_button -> move(20 + passiveFilter_button -> width() + spacing, 20);
    reInit_button -> move(width() - reInit_button -> width() - 20, 20);

    if (filterType_combo && filterType_combo->isVisible()) {
        int comboY = passiveFilter_button -> y() + passiveFilter_button -> height() + 40;
        filterType_combo -> move(20, comboY);
        filterTypeConfirm_button -> move(20 + filterType_combo -> width() + spacing, comboY);
    }
}
