#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <ctime>


using namespace std;

int main()
{
    
   cout << "**************************************" << endl;
   cout << "*BEM-VINDOS AO JOGO DE ADIVINHACAO!! *" << endl;
   cout << "**************************************" << endl;

   bool opcao_final = true;

while (opcao_final){

   cout << "Qual o nivel de dificuldade?" << endl;
   cout << "Facil (F) || Medio (M) || Dificil (D) " << endl;

   char dif;

   cin >> dif;
   int numero_tentativa;
    if(dif == 'F')
        numero_tentativa = 15;
    
    else if(dif == 'M')
        numero_tentativa = 10;
    
    else if(dif == 'D')
        numero_tentativa = 5;
        
    srand(time(NULL)); 
    const int NUMERO_SECRETO = rand() % 100;

/*Booleana criada para fazer com que o laço de repetição não fique infinito*/

    bool nao_acertou = true;
    int tentativas = 0;
    double score = 1000;

    for(tentativas = 0; tentativas < numero_tentativa; tentativas++){
        
        cout << "Esta eh sua " << tentativas << " tentativa" << endl << endl;
        cout << "agora, informe-me seu chute! ";
        int chute =0;
        cin >> chute;

        cout <<"Seu chute foi: " << chute << endl;
        
        /*Declaração de variáveis booleanas, para melhorar o entendimento do código, 
        tais variáveis só aceitam valores verdadeiros ou falsos, tomando como parâmetros
        as condições ao lado*/
        
        bool acertou = chute == NUMERO_SECRETO;
        bool maior = chute > NUMERO_SECRETO;
        bool menor = chute < NUMERO_SECRETO;

        if(acertou){
            cout << "Seu chute foi correto!! o numero secreto eh: " << NUMERO_SECRETO <<endl << endl;
            nao_acertou = false;
            break;
        }
        if(maior){
            cout << "Seu chute foi maior do que o numero secreto..." << endl << endl;
        }
        if(menor){
            cout << "Seu chute foi menor do que o numero secreto..." << endl << endl;
        }
    
    score = score - abs(NUMERO_SECRETO - chute) / 2.0;
    }

   cout << "Voce acertou o numero secreto em " << tentativas << " tentativas!!" << endl << endl;

   cout.precision(2);
   cout << fixed;
   cout << "Sua pontuacao foi: " << score << endl << endl;

   cout << "**************************************" << endl;
   cout << "******     Fim de jogo!!        ******" << endl;
   cout << "**************************************" << endl << endl;

    cout << "deseja jogar novamente?" << endl;
    cout <<" Sim (S) || Nao (N)" << endl;

    char repetir_jogo;
    cin >> repetir_jogo;

    if(repetir_jogo == 'S'){
        opcao_final = true;
    }else{
        opcao_final = false;
    }

    }
}
