#include "graficofiltropassivo.h"
#include <QtMath>

#include <QtCharts/QLogValueAxis>
#include <complex>

using namespace std;

GraficoFiltroPassivo::GraficoFiltroPassivo(QWidget *parent) : QMainWindow(parent) {}

// Para passa faixa e rejeita faixa.
GraficoFiltroPassivo::GraficoFiltroPassivo(QWidget *parent, double R, double C, double L) : QMainWindow(parent)
{
    resistor_value = R;
    capacitor_value = C;
    inductor_value = L;
    this->resize(1000, 650);

    chart = new QChart();

    serieMagnitude = new QLineSeries();

    chartView = new QChartView(chart);

    // Eixo x - Frequência em escala log
    eixoX = new QLogValueAxis;
    eixoX->setTitleText("Frequência (Hz)");
    eixoX->setLabelFormat("%.0e");
    eixoX->setBase(10);
    eixoX->setRange(0.1, 100000000);

    // Eixo y - ganho em dB | gráfico linear
    eixoY = new QValueAxis;
    eixoY->setTitleText("Ganho (dB)");
    eixoY->setRange(-35, 5);
    eixoY->setTickCount(9);
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

    chart->addAxis(eixoX, Qt::AlignBottom);
    chart->addAxis(eixoY, Qt::AlignLeft);

    serieMagnitude->attachAxis(eixoX);
    serieMagnitude->attachAxis(eixoY);

    setCentralWidget(chartView);
}

void GraficoFiltroPassivo::draw_graph_passa_faixa()
{
    for (int i = 0; i <= 5000; ++i) {
        double freq = 0.1 * qPow(100000000.0 / 0.1, double(i) / 5000);
        double omega = 2 * PI * freq;
        double reactance = omega * inductor_value - 1.0 / (omega * capacitor_value);
        complex<double> denom(resistor_value, reactance);
        complex<double> H = resistor_value / denom;
        double mag_dB = 20.0 * log10(abs(H));

        if (mag_dB < -35.0) mag_dB = -35.0;
        if (mag_dB > 5.0) mag_dB = 5.0;

        serieMagnitude->append(freq, mag_dB);
    }


    chart->addSeries(serieMagnitude);

    chart->addAxis(eixoX, Qt::AlignBottom);
    chart->addAxis(eixoY, Qt::AlignLeft);

    serieMagnitude->attachAxis(eixoX);
    serieMagnitude->attachAxis(eixoY);

    setCentralWidget(chartView);
}

void GraficoFiltroPassivo::draw_graph_rejeita_faixa()
{
    for (int i = 0; i <= 5000; ++i) {
        double freq = 0.1 * qPow(100000000 / 0.1, double(i) / 5000);  // escala log
        double omega = 2 * PI * freq;
        complex<double> numerador(0, omega * inductor_value - 1.0 / (omega * capacitor_value));
        complex<double> denominador = resistor_value + numerador;
        complex<double> H = numerador / denominador;
        double mag_dB = 20 * log10(abs(H));


        if (mag_dB < -35) mag_dB = -35;
        if (mag_dB > 5) mag_dB = 5;

        serieMagnitude->append(freq, mag_dB);
    }

    chart->addSeries(serieMagnitude);

    chart->addAxis(eixoX, Qt::AlignBottom);
    chart->addAxis(eixoY, Qt::AlignLeft);

    serieMagnitude->attachAxis(eixoX);
    serieMagnitude->attachAxis(eixoY);

    setCentralWidget(chartView);
}

