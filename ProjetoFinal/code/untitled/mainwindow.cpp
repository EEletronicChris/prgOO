#include "mainwindow.h"



using namespace QtCharts;

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
    this->resize(600, 400);
    plotarResposta();
}

void MainWindow::plotarResposta() {
    serie = new QLineSeries(this);

    for (double f = 1; f <= 10000; f *= 1.05) {
        double w = 2 * M_PI * f;
        double H = 1.0 / sqrt(1 + w*w);
        double dB = 20 * log10(H);
        serie->append(f, dB);
    }

    QChart *chart = new QChart();
    chart->addSeries(serie);
    chart->setTitle("Resposta em Frequência |H(jω)|");
    chart->createDefaultAxes();

    // Configurar os eixos
    QValueAxis *eixoX = new QValueAxis;
    eixoX->setTitleText("Frequência (Hz)");
    eixoX->setLabelFormat("%.0f");
    eixoX->setRange(0, 10000);

    QValueAxis *eixoY = new QValueAxis;
    eixoY->setTitleText("Magnitude (dB)");
    eixoY->setRange(-60, 5);

    chart->setAxisX(eixoX, serie);
    chart->setAxisY(eixoY, serie);

    chartView = new QChartView(chart, this);
    chartView->setGeometry(10, 10, 580, 380);
}
