/*Implemente uma classe para abstrair uma televisão. A televisão tem um controle de volume do som e um controle de 
seleção de canal.

A classe implementada deve atender aos seguintes requisitos mínimos:

O controle de volume permite aumentar ou diminuir a potência do volume de som em uma unidade de cada vez.

A potência do volume deve ter valores discretos no intervalo [0 , 100].

O controle de canal também permite aumentar e diminuir o número do canal em uma unidade

A interface também deve possibilitar a trocar para um canal indicado.

0s canais dever ter valores discretos no intervalo [0 , 75].

Também devem existir métodos para consultar o valor do volume de som e o canal selecionado.

Caso julgar necessário, adicione na interface desta abstração, outros comportamentos que julgar necessários

Elabore um programa para realizar o teste da sua abstração. Lembre-se de realizar um teste completo da sua interface.*/

#include <iostream>

using namespace std;

class Televisao{
    int vol, canal;
    
public:
    Televisao(int v, int ch){vol=v; canal=ch;}   // Construtor para inicialização
    /*-----Controles de volume------*/
    void vol_plus(){                            // Aumenta o volume em 1
        if (vol < 100){
            vol++;
        }
    }
    void vol_minus(){                           // Diminui o volume em 1
        if (vol > 0){
            vol--;
        }
    }
    void print_vol(){
        cout << "Volume: " << vol << endl;
    }
    /*-----Controles de canal------*/
    void ch_plus(){                            // Aumenta o canal em 1
        if (canal < 75){
            canal++;
        }
    }
    void ch_minus(){                           // Diminui o canal em 1
        if (canal > 0){
            canal--;
        }
    }
    void ch_any(int ch){                        // Altera para qualquer canal
        if (ch >= 0 && ch <= 75){
            canal = ch;
        }
    }
    void print_ch(){
        cout << "Canal: " << canal << endl;
    }

};

int main()
{
    Televisao toshiba(0,0);
    Televisao mitsubishi(100,75);
    // Teste de limites inferiores
    toshiba.vol_minus();
    toshiba.ch_minus();
    toshiba.print_ch();
    toshiba.print_vol();
    // Teste de aumento de 1 unidade
    toshiba.vol_plus();
    toshiba.ch_plus();
    toshiba.print_ch();
    toshiba.print_vol();
    //Teste de limites superiores
    mitsubishi.vol_plus();
    mitsubishi.ch_plus();
    mitsubishi.print_ch();
    mitsubishi.print_vol();
    // Teste de decremento de 1 unidade
    mitsubishi.vol_minus();
    mitsubishi.ch_minus();
    mitsubishi.print_ch();
    mitsubishi.print_vol();
    
    mitsubishi.ch_any(30);
    cout << "Mudando para o canal 30: ";
    mitsubishi.print_ch();

    return 0;
}