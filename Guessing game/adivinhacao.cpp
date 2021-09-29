#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    
   cout << "**************************************" << endl;
   cout << "*BEM-VINDOS AO JOGO DE ADIVINHACAO!! *" << endl;
   cout << "**************************************" << endl;
    
    const int NUMERO_SECRETO = 74;

    cout << "o numero secreto eh: " << NUMERO_SECRETO << endl; 
    cout << "capisce?" << endl;

    bool nao_acertou = true;
    int tentativas = 0;

    while (nao_acertou){
    tentativas++;
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
    }
    if(maior){
        cout << "Seu chute foi maior do que o numero secreto..." << endl << endl;
    }
    if(menor){
        cout << "Seu chute foi menor do que o numero secreto..." << endl << endl;
    }
}

   cout << "Voce acertou o numero secreto em " << tentativas << " tentativas!!" << endl << endl; 

   cout << "**************************************" << endl;
   cout << "******     Fim de jogo!!        ******" << endl;
   cout << "**************************************" << endl << endl;

}