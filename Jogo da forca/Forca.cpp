#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

string SECRET_WORD;

map <char, bool> ja_chutou;
vector<char>chutes_errados;

/*Leitor do arquivo: Palavras.txt*/
vector<string> read_file(){
    ifstream archive;
    archive.open("palavras.txt");

    if(archive.is_open()){
        int quantidade_palavras;    
        archive >> quantidade_palavras;

        vector<string> palavras_dentro_do_arquivo;
        
        for (int i=0; i<quantidade_palavras; i++){
            string palavra;
            archive >> palavra;
            palavras_dentro_do_arquivo.push_back(palavra);
        }
        return palavras_dentro_do_arquivo;

        archive.close();
    }else{
        cout << "Não foi possivel abrir as palavras.txt";
        exit(0);
    }
}


/*Funcao que verifica se o chute foi correto*/
bool letra_existe(char chute){
    for (char letra : SECRET_WORD ){
        if(chute == letra){
            return true;
        }
    }
    return false;
}

/*funcao que verifica se o jogador errou ou nao, para continuar o laço do jogo*/
bool nao_acertou(){
    for(char letra : SECRET_WORD){
        if (!ja_chutou[letra]) {
            return true;
        }
    }
    return false;
}

/* Funcao que decreta o final do jogo se o jogador nao conseguir acertar em 5 tentativas*/
bool nao_enforcou(){
   return chutes_errados.size() < 5;
}

/*Funcao que salva o arquivo novo*/
void save_file(vector<string> new_file){
    ofstream file;
    file.open("palavras.txt");

    if(file.is_open()){
        file << new_file.size() << endl;

        for(string word : new_file){
            file << word << endl;
        }
        file.close();
    }else{
        cout << "Falha ao abrir o arquivo.";
        exit(0);
    }

}

/*Funcao que atualiza o arquivo palavras.txt*/
void update_archive(){

    cout << "Utilizando letras maiusculas, digite a palavra que deseja acrescentar" << endl;
    string nova_palavra;
    cin >> nova_palavra;
    
    vector<string> lista_palavras = read_file();
    lista_palavras.push_back(nova_palavra);

  save_file(lista_palavras);  
}


/* Funcao que cria o cabeçalho do jogo*/
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

/* Funcao que imprime as mensagens de final de jogo*/
void fim_de_jogo(){

        cout << endl << endl;
    cout << "Fim de jogo!!" << endl;
    cout << "a palavra secreta eh > " << SECRET_WORD << endl << endl;

    if(nao_acertou()){
        cout << "Perdeu amigo, tente outra vez kkkkk" << endl;
    }else{
        cout << "Parabens, voce acertou! Obrigado por jogar." << endl;
    }
    cout << "Gostaria de adicionar uma nova palavra ao banco de dados?  S || N" << endl;
    char opcao;
    cin >> opcao;

    if(opcao == 'S'){
        update_archive();
    }
}

/* Funcao que imprime os erros do jogador*/
void mostra_erro(){

 cout << "chutes errados: ";
    for(char letra : chutes_errados){
        cout << letra << " ";

    }
    cout << endl;
}

/*Funcao que escolhe uma palavra aleatoria do banco de palavras*/
void escolhe_palavra(){
    vector<string> palavras = read_file();

    srand(time(NULL));
    int sorteado = rand() % palavras.size();

    SECRET_WORD = palavras[sorteado];
}

int main (){
    cria_cabecalho();
    read_file();
    escolhe_palavra();

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


