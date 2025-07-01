#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Cria o botão
    fechar_button = new QPushButton("Fechar", this);
    fechar_button->resize(80, 30); // Tamanho do botão

    // Conecta o clique ao fechamento da janela
    connect(fechar_button, &QPushButton::clicked, this, &QMainWindow::close);

    // Posiciona o botão inicialmente
    fechar_button->move(width() - fechar_button->width() - 10, 10);

    filtros_models = new analogFilters(this);
    filtros_models ->resize(width(), height()); // Ocupa toda a janela
    filtros_models ->repositionButtons(width(), 60); // 60px abaixo do topo
}

// Reposicionamento dos elementos conforme tamanho da janela
void MainWindow::resizeEvent(QResizeEvent *event) {
    QMainWindow::resizeEvent(event);

    fechar_button -> move(width() - fechar_button->width() - 10, 10);

    filtros_models -> resize(width(), height());
    filtros_models -> repositionButtons(width(), 60);
}




MainWindow::~MainWindow() {}
