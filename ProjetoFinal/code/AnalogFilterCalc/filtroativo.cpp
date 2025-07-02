#include "filtroativo.h"
#include <QDebug>

filtroAtivo::filtroAtivo(QWidget *parent)
    : analogFilters(parent), gainInput(nullptr)
{
    // Conecta o botão de confirmação ao método get_gain_value
    connect(&filterTypeConfirm_button, &QPushButton::clicked, this, &filtroAtivo::get_gain_value);
}

void filtroAtivo::get_gain_value()
{
    if (!gainInput) {
        gainInput = new QLineEdit(this);
        gainInput->setPlaceholderText("Digite o ganho (float)");
        gainInput->resize(150, 30);
    }

    // Verifica se o filtro selecionado é um filtro ativo
    QString tipo = findChild<QComboBox*>()->currentText();
    if (tipo.contains("Ativo", Qt::CaseInsensitive)) {
        int yOffset = findChild<QComboBox*>()->y() + findChild<QComboBox*>()->height() + 20;
        int xOffset = (width() - gainInput->width()) / 2;
        gainInput->move(xOffset, yOffset);
        gainInput->show();
    } else {
        if (gainInput) gainInput->hide();
    }
}
