#include "analogfilters.h"

analogFilters::analogFilters(QWidget *parent)
    : QWidget(parent), filterType_combo(nullptr)
{
    passiveFilter_button = new QPushButton("Filtros Passivos", this);
    activeFilter_button = new QPushButton("Filtros Ativos", this);

    passiveFilter_button -> resize(100, 30);
    activeFilter_button -> resize(100, 30);

    connect(passiveFilter_button, &QPushButton::clicked, this, &analogFilters::showComboPassives);
    connect(activeFilter_button, &QPushButton::clicked, this, &analogFilters::showComboActives);

    reposicionarElementos();
}

void analogFilters::showComboPassives() {
    if (! filterType_combo) {
        filterType_combo = new QComboBox(this);
        filterType_combo -> resize(150, 30);
    } else {
        filterType_combo -> clear();
    }

    filterType_combo->addItem("Passa-baixa Passivo");
    filterType_combo->addItem("Passa-alta Passivo");
    filterType_combo->addItem("Passa-faixa Passivo");
    filterType_combo->addItem("Rejeita-faixa Passivo");
    filterType_combo -> show();
    reposicionarElementos();
}

void analogFilters::showComboActives() {
    if (! filterType_combo) {
        filterType_combo = new QComboBox(this);
        filterType_combo -> resize(150, 30);
    } else {
        filterType_combo->clear();
    }

    filterType_combo->addItem("Passa-baixa Ativo");
    filterType_combo->addItem("Passa-alta Ativo");
    filterType_combo->addItem("Passa-faixa Ativo");
    filterType_combo->addItem("Rejeita-faixa Ativo");
    filterType_combo->show();
    reposicionarElementos();
}

void analogFilters::resizeEvent(QResizeEvent *event) {
    QWidget::resizeEvent(event);
    reposicionarElementos();
}

void analogFilters::reposicionarElementos() {
    int spacing = 20;
    int totalWidth = passiveFilter_button->width() + spacing + activeFilter_button->width();
    int startX = (width() - totalWidth) / 2;

    passiveFilter_button->move(startX, 20);
    activeFilter_button->move(startX + passiveFilter_button->width() + spacing, 20);

    if (filterType_combo) {
        int comboX = (width() - filterType_combo->width()) / 2;
        filterType_combo->move(comboX, passiveFilter_button->y() + passiveFilter_button->height() + 20);
    }
}
