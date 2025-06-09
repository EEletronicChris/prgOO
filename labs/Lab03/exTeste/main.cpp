// 1- Solicita para o usuário um conjunto de 
//números inteiros (qtd arbitrária)
// 2- Imprime este conjunto na ordem em que 
//usuário digitou
// 3- Apresenta qual é o menor número digitado
// 4- Apresenta qual é o maior número digitado
// 5- Imprime os números em ordem crescente
#include <vector>
#include <iostream>
using namespace std;

int main()
{

    int number, qtd, i;
    vector<int> num_list;

    cout << "Qual a quantidade de numeros desejada? ";
    cin >> qtd;
    cout << endl;

    for (i = 1; i <= qtd; i++){                     // Guarda os números no vetor
        cout << "Insira o " << i << " numero -> ";
        cin >> number;
        if (cin.fail()){                            // Checa ouve incoerencia nos tipos de dados de entrada
            string temp;
            cin >> temp;
            
            cin.clear();                            // *****Para resolver problemas de entrada *****
            cout << "entrada invalida e (" << tmp << ")" << endl;
            cout << "Entrada invalida. Por favor, insira um inteiro" << endl;

        }
        else{
            num_list.push_back(number); 

        }
    }

    cout << endl << "Os numeros na ordem digitada sao:" << endl;

    for (i = 0; i < qtd - 1; i++){                     // Imprime na ordem digitada
        int numAux = num_list.front();
        if ()
    }

    // Encontra e printa o menor número
    // min_element()
    // max_element()

    //sort


    return 0;
}