#include <iostream>
#include "lista.h"
#include "utils.h"
#include "filme.h"
#include "arvore.h"

using namespace std;


filme starter(string lin) {

  filme f1(lin);
  return f1;

}

int main(int argc, char * argv[]) {

  int c = 0;
  string linha, chave;
  filme umFilme;
  arvore<filme> * arv = NULL; 

/*  if (argc < 2) {
    cerr << "Escreve direita o nome dessa desgraça de arquivo, seu animal." << endl;
    return 0;
  }
*/
  ifstream arq(argv[1]);
  if (not arq.is_open()) {
    cerr << "Essa porcaria não abriu, seu tanso!" << endl;
  return -1;
  }

  while(not arq.eof()){

    try {
      getline(arq, linha);
      if(linha.length() < 1){
        break;
      } else {
           
      umFilme = starter(linha);

        try {
          stringstream conv;
          conv << umFilme.sano();
 
          chave = umFilme.stitulo() + " " + conv.str();

          if (not arv) arv = new arvore<filme>(chave, umFilme);
          else arv -> adiciona(chave, umFilme);
        } catch (int e) {
          cerr << "Erro ao adicionar " << umFilme.stitulo() << endl;
        }
      }
    } catch (int e) {
      cerr << "Ops: você é um animal... ignorando sua existência" << endl;
    }
    //cout << "numero de fimes sendo passado pra arvore: " << c << endl;
    c++;
  }


  arq.close();

  cout << "Altura da árvore antes de balancear: " << arv -> altura() << endl << endl;
  cout << "FatorB antes de balancear: " << arv -> fatorB() << endl << endl;

  cout << "Tamanho: " << arv->tamanho() << endl;

  arv = arv -> balanceia();

  cout << "Altura da árvore depois de balancear: " << arv -> altura() << endl << endl;
  cout << "FatorB depois de balancear: " << arv -> fatorB() << endl << endl;

  cout << "Tamanho: " << arv->tamanho() << endl;
  arv = arv -> balanceia();

  cout << "Altura da árvore depois de balancear: " << arv -> altura() << endl << endl;
  cout << "FatorB depois de balancear: " << arv -> fatorB() << endl << endl;

  cout << "Tamanho: " << arv->tamanho() << endl;
  arv = arv -> balanceia();

  cout << "Altura da árvore depois de balancear: " << arv -> altura() << endl << endl;
  cout << "FatorB depois de balancear: " << arv -> fatorB() << endl << endl;

  cout << "Tamanho: " << arv->tamanho() << endl;
  arv = arv -> balanceia();

  cout << "Altura da árvore depois de balancear: " << arv -> altura() << endl << endl;
  cout << "FatorB depois de balancear: " << arv -> fatorB() << endl << endl;


  //ofstream arquero("arqzao.txt");
/* // arv -> escrevase(arquero);
  IteradorPreOrder<filme> it(arv);
  string escritora;
  filme movie;
  while (not it.fim()) {
    Par<filme> par = it.proximo();
    movie = par.valor;
    escritora = movie.formater();
    arquero << escritora << endl; 
  }
 
  string trink = "2014";
  int juiz = 0;
  IteradorPreOrder<filme> it(arv);
  lista<filme> filmes_possiveis;
  Par<filme> par;
  while(not it.fim()){
    par = it.proximo();
    juiz = comparador(trink, par.chave);
    if(juiz > 0){
      filmes_possiveis.anexa(par.valor);
    }
  }
  
  filmes_possiveis.escrevase(cout);
*/
/*
 string palchave = "Furious 7 2015";

 filme ret = (*arv)[palchave];
 cout << ret << endl;

 arv -> remove(palchave);
 try{ 
 ret = (*arv)[palchave];
 }catch(int e) {
   cout << e << endl;
 }
 cout << ret << endl;

   Par<T> key;
   Par<T> outropar;
   arvore<T> * aux;
   arvore<T> * aux2;
   arvore<T> * aux3;
 
   IteradorPreOrder<T> it(arv);
   while(palchave != key.chave){
     aux = it.proximo_ramo();
     key = it.proximo();
   }
   if(aux -> esq == NULL && aux -> dir == NULL){
     outropar = aux -> par;
     aux3 = aux -> pai;
     if(aux3 -> dir == aux) aux3 -> dir = NULL;
     if(aux3 -> esq == aux) aux3 -> esq = NULL;
     return outropar.valor;
   }
 
 
   if(aux -> fatorB() > 0){
     aux2 = aux -> esq;
     while(aux2 -> dir) aux2 = aux2->dir;
   }else {
     aux2 = aux -> dir;
     while(aux2 -> esq) aux2 = aux2 -> esq;
   }
   aux3 = aux2 -> pai;
   outropar = aux -> par;
   aux -> par = aux2 -> par;
   if(aux3 -> dir == aux2) aux3 -> dir = NULL;
   if(aux3 -> esq == aux2) aux3 -> esq = NULL;
   return outropar.valor;
 */


}
