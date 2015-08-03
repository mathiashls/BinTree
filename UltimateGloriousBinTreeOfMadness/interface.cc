#include "utils.h"
#include "filme.h"
#include "catalogo.h"
#include <string>

using namespace std;

int main(int argc, char * argv[]) {
  
  bool exit = true;
  string entrada, palavra, linha;
  int resposta;
  float cont = 0;
  filme movie;
  lista<filme> lf1;

  if(argc < 2) {
    cout << "Arquivo não especificado!" << endl;
    return -1;
  }

  catalogo c1(argv[1]);


  while(exit){

  cout << "╔══════════════════════╗" << endl;
  cout << "║╔════════════════════╗║" << endl;
  cout << "║║╔══════════════════╗║║" << endl;
  cout << "║║║CATÁLOGO DE FILMES║║║" << endl;
  cout << "║║╚══════════════════╝║║" << endl;
  cout << "║╚════════════════════╝║" << endl;
  cout << "╚══════════════════════╝" << endl;


  cout << "Menu:" << endl << endl;
  cout << "1. Pesquisar filme." << endl;
  cout << "2. Inserir filme." << endl;
  cout << "3. Remover filme." <<  endl;
  cout << "4. Pesquisar filme (busca parcial)." << endl;
  cout << "5. Exportar catálogo (.txt). " << endl;
  cout << "6. Sair." << endl << endl;
  cout << ">> ";
  cin >> resposta;
  cout << endl << endl;
  cin.ignore(100,'\n');
  
  if(resposta > 6 or resposta < 1) {

    cout << "Insira um número válido!" << endl << endl;
    
  }

  switch (resposta) {

    case 1:
      cout << "Digite o nome do filme e seu ano de lançamento."; 
      cout << " (Pesquisa apenas poderá ser efetuada com sucesso caso os dados sejam passados corretamente)." << endl;
      cout << ">> ";
      getline(cin, palavra);
      try{
        movie = c1.pesquisa(palavra);
      }catch(int e){
        if(e == 3) {
          cout << endl <<"Filme não encontrado!" << endl;
          cout << endl <<"Aperte ENTER para voltar ao menu principal." << endl;
          getchar();
          break;
        }
      }
      cout << endl << endl;
      cout << movie << endl;
      cout << endl << endl;
      cout << "ENTER para voltar ao menu principal." << endl << endl << endl;
      getchar();
      break;
      
    case 2:

      cout << "Qual o titulo do filme?" << endl;
      cout << ">> ";
      getline(cin, palavra);
      linha += palavra + ";";

      cout << "Qual o ano em que o filme foi feito?" << endl;
      cout << ">> ";
      getline(cin, palavra);
      linha += palavra + ";";

      cout << "Qual a avaliação do filme?" << endl;
      cout << ">> ";
      getline(cin, palavra);
      linha += palavra + ";";

      linha += ";";

      cout << "Qual a duração do filme? (Em minutos)" << endl;
      cout << ">> ";
      getline(cin, palavra);
      linha += palavra + ";";

      cout << "Qual foi o orçamento do filme?" << endl;
      cout << ">> ";
      getline(cin, palavra);
      linha += palavra + ";";

      cout << "Quais os generos do filme? (Escreva todos separados por vírgula)" << endl;
      cout << ">> ";
      getline(cin, palavra);
      linha += palavra + ";";

      cout << "Quais são os diretores do filme? (Escreva todos separados por vírgula)" << endl;
      cout << ">> ";
      getline(cin, palavra);
      linha += palavra + ";";

      cout << "Quais os atores que trabalharam no filme? (Ator/Personagem - Escreva todos separados por vírgula)" << endl;
      cout << ">> ";
      getline(cin, palavra);
      linha += palavra + ";";

      cout << "Quais os países em que o filme foi produzido? (Escreva todos separados por vírgula)" << endl;
      cout << ">> ";
      getline(cin, palavra);
      linha += palavra + ";";

      cout << "Escreva um link para mais informações sobre o filme:" << endl;
      cout << ">> ";
      getline(cin, palavra);
      linha += palavra + ";";

      cout << "Escreva ou copie a sinopse do filme abaixo:" << endl;
      cout << ">> ";
      getline(cin, palavra);
      linha += palavra;

      cout << endl << "ATENÇÃO: o filme adicionado esta armazenado em memória volátil, para gravar definitivamente o filme você deve utilizar a opção 5 (exportar)." << endl << endl;
        
      c1.insere_filme(linha);
      break;

    case 3:
      cout << "Qual filme você deseja excluir?" << endl;
      cout << ">> ";
      getline(cin, palavra);

      try {
        c1.remove_filme(palavra);
        break;
      } catch (int e) {
        cout << endl << "Filme não existe mais na lista!" << endl << endl;
        break;
      }

    case 4: 
      cout << "Digite alguma palavra que exista no nome do filme:" << endl;
      cout << ">> ";
      getline(cin, palavra);
      try{
       lf1 = c1.pesquisa_parcial(palavra);
      }catch(int e){
        if (e == 24){            
          cout <<"=================================================================";
          cout << endl << endl << "Nenhum filme encontrado!" << endl << endl << endl << endl;
          cout << "Aperte ENTER para voltar ao menu principal" << endl;
          getchar();
          break; 
        }
      }
      cout << endl << endl << endl << endl;
      while(cont < lf1.comprimento()){
        movie =lf1[cont];
        cout << endl << endl << endl << movie << endl;
        cout <<"=================================================================";
        cout << endl << endl;
        cont++;
      }
      cout << "Aperte ENTER para voltar ao menu principal." << endl;
      getchar();
      cont = 0;
      break; 
     case 5:
       c1.exporta(argv[1]);
       break;
     case 6:
       exit = false;
  }
}
}
