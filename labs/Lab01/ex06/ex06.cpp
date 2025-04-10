/*Implemente a abstração de um equipamento de ar condicionado, com os seguintes requisitos:

O condicionador possui 10 potências diferentes.
Cada unidade da potência do condicionador diminui a temperatura do ambiente em 1.8° C.
A variação que o condicionador consegue causar está no intervalo [0° C - 18° C], ou seja, zero graus de variação 
quando desligado e dezoito graus de variação quando ligado na potência máxima.
Através de um sensor, o condicionador é informado da temperatura externa. Dada essa temperatura e a potência
 selecionada, o condicionador calcula e retorna a temperatura do ambiente.
No programa principal, crie dois condicionadores. Informe duas temperaturas externas diferentes para cada um 
(ex: 25° C e 31° C), ajuste o segundo em potência máxima (10) e o primeiro em potência média (5). 
Finalmente, exiba a temperatura resultante de cada ambiente.*/

#include <iostream>

using namespace std;

class Condicionador{
    int potencia;
    float t_in, t_out;

public: 
    // Este construtor calcula a temperatura interna com base na potência e tempereatura do sensor
    Condicionador(float sensor, int p){
        t_out = sensor;
        potencia = p;
        t_in = sensor - (p*1.8);
    }
    void print_t(){
        cout << "A temperatura interna e: " << t_in << endl;
    }
};

int main()
{
    Condicionador Komeco(25.0,5);
    Condicionador Elgin(31.0,10);

    cout << "Temperatura interna usando komeco e:" << endl;
    Komeco.print_t();
    cout << "Temperatura interna usando Elgin e:" << endl;
    Elgin.print_t();

    return 0;
}