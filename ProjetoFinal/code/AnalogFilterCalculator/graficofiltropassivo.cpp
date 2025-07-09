#include "graficofiltropassivo.h"
#include <QtMath>

#include <QtCharts/QLogValueAxis>
#include <complex>

using namespace std;

GraficoFiltroPassivo::GraficoFiltroPassivo(QWidget *parent) : QMainWindow(parent) {}

// Para passa altas e passa baixas
GraficoFiltroPassivo::GraficoFiltroPassivo(QWidget *parent , double R, double C): QMainWindow(parent)
{
    resistor_value = R;
    capacitor_value = C;
    this->resize(1000, 650);

    chart = new QChart();

    serieMagnitude = new QLineSeries();

    chartView = new QChartView(chart);
}

// Para passa faixa e rejeita faixa.
GraficoFiltroPassivo::GraficoFiltroPassivo(QWidget *parent, double R, double C, double L) : QMainWindow(parent)
{

}


void GraficoFiltroPassivo::draw_graph_passa_alta()
{
    for (int i = 0; i <= 5000; ++i) {
        double freq = 0.1 * qPow(100000000 / 0.1, double(i) / 5000);  // escala log
        double omega = 2 * PI * freq;
        complex<double> jw_omega(0, omega);
        complex<double> H = (jw_omega * resistor_value * capacitor_value) / (1.0 + jw_omega * resistor_value * capacitor_value);
        double mag_dB = 20 * log10(abs(H));

        if (mag_dB < -35) mag_dB = -35;
        if (mag_dB > 5) mag_dB = 5;

        serieMagnitude->append(freq, mag_dB);
    }

    chart->addSeries(serieMagnitude);

    // Eixo x - Frequência em escala log
    QLogValueAxis *eixoX = new QLogValueAxis;
    eixoX->setTitleText("Frequência (Hz)");
    eixoX->setLabelFormat("%.0e");
    eixoX->setBase(10);
    eixoX->setRange(0.1, 100000000);

    // Eixo y - ganho em dB | gráfico linear
    QValueAxis *eixoY = new QValueAxis;
    eixoY->setTitleText("Ganho (dB)");
    eixoY->setRange(-35, 5);
    eixoY->setTickCount(9);

    chart->addAxis(eixoX, Qt::AlignBottom);
    chart->addAxis(eixoY, Qt::AlignLeft);
    serieMagnitude->attachAxis(eixoX);
    serieMagnitude->attachAxis(eixoY);

    setCentralWidget(chartView);
}

void GraficoFiltroPassivo::draw_graph_passa_baixa()
{
    for (int i = 0; i <= 5000; ++i) {
        double freq = 0.1 * qPow(100000000 / 0.1, double(i) / 5000);  // escala log
        double omega = 2 * PI * freq;
        complex<double> jw_omega(0, omega);
        complex<double> H = 1.0/(1.0 + (jw_omega * resistor_value * capacitor_value));
        double mag_dB = 20 * log10(abs(H));

        if (mag_dB < -35) mag_dB = -35;
        if (mag_dB > 5) mag_dB = 5;

        serieMagnitude->append(freq, mag_dB);
    }

    chart->addSeries(serieMagnitude);

    // Eixo x - Frequência em escala log
    QLogValueAxis *eixoX = new QLogValueAxis;
    eixoX->setTitleText("Frequência (Hz)");
    eixoX->setLabelFormat("%.0e");
    eixoX->setBase(10);
    eixoX->setRange(0.1, 100000000);

    // Eixo y - ganho em dB | gráfico linear
    QValueAxis *eixoY = new QValueAxis;
    eixoY->setTitleText("Ganho (dB)");
    eixoY->setRange(-35, 5);
    eixoY->setTickCount(9);

    chart->addAxis(eixoX, Qt::AlignBottom);
    chart->addAxis(eixoY, Qt::AlignLeft);
    serieMagnitude->attachAxis(eixoX);
    serieMagnitude->attachAxis(eixoY);

    setCentralWidget(chartView);
}

void GraficoFiltroPassivo::draw_graph_passa_faixa()
{

}

void GraficoFiltroPassivo::draw_graph_rejeita_faixa()
{

}

