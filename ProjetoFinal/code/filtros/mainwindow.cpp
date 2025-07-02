#include "mainwindow.h"
#include "filtros.h"
#include "filtroativo.h"

#include <QPushButton>
#include <QComboBox>
#include <QHBoxLayout>

MainWindow::MainWindow() {
    mainLayout = new QVBoxLayout();

    // Layouts auxiliares
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    QVBoxLayout *inputLayout = new QVBoxLayout();

    // Widgets
    QPushButton *btnPassivo = new QPushButton("Filtros Passivos");
    QPushButton *btnAtivo = new QPushButton("Filtros Ativos");
    QComboBox *comboBox = new QComboBox();

    // Instâncias das classes
    Filtros *filtros = new Filtros();
    FiltroAtivo *filtroAtivo = new FiltroAtivo();

    // Conexões
    QObject::connect(btnPassivo, &QPushButton::clicked, [=]() {
        filtros->carregarPassivos(comboBox);
    });

    QObject::connect(btnAtivo, &QPushButton::clicked, [=]() {
        filtros->carregarAtivos(comboBox);
    });

    QObject::connect(comboBox, &QComboBox::currentTextChanged, [=](const QString &text) {
        filtroAtivo->atualizarCampos(inputLayout, text);
    });

    // Montagem da interface
    buttonLayout->addWidget(btnPassivo);
    buttonLayout->addWidget(btnAtivo);

    mainLayout->addLayout(buttonLayout);
    mainLayout->addWidget(comboBox);
    mainLayout->addLayout(inputLayout);
}

QVBoxLayout *MainWindow::getLayout() {
    return mainLayout;
}
