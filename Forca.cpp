#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>

using namespace std;

const string SECRET_WORD = "MELANCIA";
map <char, bool> ja_chutou;
vector<char>chutes_errados;

/*Funcao que verifica se o chute foi correto*/
bool letra_existe(char chute){
    for (char letra : SECRET_WORD ){
        if(chute == letra){
            return true;
        }
    }
    return false;
}

bool nao_acertou(){
    for(char letra : SECRET_WORD){
        if (!ja_chutou[letra]) {
            return true;
        }
    }
    return false;
}

bool nao_enforcou(){
   return chutes_errados.size() < 5;
}


void cria_cabecalho(){
    cout <<"     _______________,,.            " << endl;
    cout <<"    /_____________.;;'/|           " << endl;  
    cout <<"    |____  _______;;;]/            " << endl;
    cout <<"    | || //'         ;             "  << endl;
    cout <<"    | ||//'          ;             "  << endl;
    cout <<"    | |//'           ;             "  << endl;
    cout <<"    |  /'            $             "  << endl;
    cout <<"    | ||             $             "  << endl;
    cout <<"    | ||             $             "  << endl;
    cout <<"    | ||            ,^.            "  << endl;
   cout <<"    | ||            | |             "  << endl;
   cout <<"    | ||            `.'             "  << endl;
   cout <<"    | ||                            "  << endl;
   cout <<"    | ||                            "  << endl;
   cout <<"    | ||                            "  << endl;
   cout <<"    | ||                            "  << endl; 
   cout <<"    | ||"  << endl;
   cout <<"    | || "  << endl;
   cout <<"    | ||"  << endl;
   cout <<"    | ||"  << endl;
   cout <<"    | ||"  << endl;
   cout <<"    | ||"  << endl;
   cout <<"    |_|/"  << endl << endl << endl << endl;

   cout << "*****************************"  << endl;
   cout << "*bem vindo ao jogo da forca!*"  << endl;
   cout << "*****************************"  << endl << endl; 
}

void fim_de_jogo(){

        cout << endl << endl;
    cout << "Fim de jogo!!" << endl;
    cout << "a palavra secreta eh > " << SECRET_WORD << endl << endl;

    if(nao_acertou()){
        cout << "Perdeu amigo, tente outra vez kkkkk" << endl;
    }else{
        cout << "Parabens, voce acertou! Obrigado por jogar." << endl;
    }
}

void mostra_erro(){

 cout << "chutes errados: ";
    for(char letra : chutes_errados){
        cout << letra << " ";

    }
    cout << endl;
}

void read_file(){
    ifstream archive;
    archive.open("palavras.txt");

    int quantidade_palavras;
    archive >> quantidade_palavras;
    
    for (int i=0; i<quantidade_palavras; i++){
        string palavra;
        archive >> palavra;

    }
    
}

int main (){
    cria_cabecalho();
    
    read_file();

    while (nao_acertou() && nao_enforcou()){

        mostra_erro();

        for (char letra : SECRET_WORD){
            if (ja_chutou[letra]){
                cout << letra << " ";
            }else{
                cout << "_ " ;
            }
        }
        cout << endl << endl;

        cout << "Digite o seu chute > " << endl;
        char chute; 
        cin >> chute;
        ja_chutou[chute] = true;

        cout << "o seu chute foi: " << chute << endl;

        if(letra_existe(chute)){
            cout << "Voce acertou!! A palavra possui a letra informada" << endl;
        }else{
            cout << "Voce errou... A palavra nao possui a letra informada..." << endl;
            chutes_errados.push_back(chute);
        }
 

    }
 fim_de_jogo();
}

