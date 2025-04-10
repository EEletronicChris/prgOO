/*
Crie uma classe em C++ chamada Relogio para armazenar um horário, composto por hora, minuto e segundo.
 A classe deve representar esses componentes de horário e deve apresentar os métodos descritos a seguir:

um método chamado setHorario, que deve receber o horário desejado por parâmetro (hora, minuto e segundo);

um método chamado getHorario para retornar o horário atual, através de 3 variáveis passadas por referência;

um método chamado tick para avançar o horário para o próximo segundo (lembre-se de atualizar o minuto e a hora, 
quando for o caso).
*/

#include <iostream>

using namespace std;

class Relogio{
    //inicializando variáveis em 0;
    int hora = 0, minuto = 0, segundo = 0;

public:
    // Método para receber o horário com condiçoes;
    void setHorario (int h, int m, int s)
    {
        if (h >= 0 && h < 24){
            hora = h;
        } 
        else{
            cout << "valor de hora nao compativel" << endl;
        }
        if (m >= 0 && m < 60){
            minuto = m;
        }
        else{
            cout << "valor de minuto nao compativel" << endl;
        }
        if (s >= 0 && s < 60){
            segundo = s;
        }
        else{
            cout << "valor de segundo nao compativel" << endl;
        }
    }
    //  Método para imprimir horário
    void getHorario (Relogio &w)  
    {
        cout << "horario: " << w.hora << ":" << w.minuto << ":" << w.segundo << endl;
    }
    // Método para aumentar em 1 segundo o horário
    void tick ()
    {
        if (segundo == 59){
            segundo = 0;
            if (minuto == 59){
                minuto = 0;
                if (hora == 23){
                    hora = 0;
                }
                else{
                    hora ++;
                }
            }
            else{
                minuto ++;
            }
        }
        else{
            segundo ++;
        }
    }
};

int main() 
{
    Relogio rolex, *watch;
    rolex.setHorario(23,59,59);
    rolex.tick();
    watch = &rolex;
    rolex.getHorario(*watch);

    return 0;
}

