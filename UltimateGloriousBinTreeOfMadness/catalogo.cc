#include "catalogo.h"
#include "utils.h"
#include "arvore.h"
//a principio não precisa pesquisar por ator diretor e essa parad
//a toda, portanto uma arvela só ta 10


catalogo::catalogo(char * path) {

  arv =  NULL; 
  string linha, chave;
  filme umFilme;
  
  ifstream arq(path);
  
  if (not arq.is_open()) {
    cerr << "Essa porcaria não abriu, seu tanso!" << endl;
    throw 30;
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
  }


  arq.close();

  int compare;

  while(compare != arv -> altura()){
    compare = arv -> altura();
    arv = arv -> balanceia();   
  }
}


catalogo::~catalogo(){
}  

filme catalogo::pesquisa(const string chave){

  try{
    filme ret = (*arv)[chave];
    return ret;
  } catch(int e) {
    if(e == 3) throw 3;
  }

}

lista<filme> catalogo::pesquisa_parcial(const string chave){

  int juiz = 0;
  IteradorPreOrder<filme> it(arv);
  lista<filme> filmes_possiveis;
  Par<filme> par;
  while(not it.fim()){
    par = it.proximo();
    juiz = comparador(chave, par.chave);
    if(juiz > 0){
      filmes_possiveis.anexa(par.valor);
    }
  }
  if(not filmes_possiveis.vazia()) { 
    return filmes_possiveis;
  } else throw 24;
}

void catalogo::exporta(char * path){

  ofstream arqout(path);
  IteradorPreOrder<filme> it(arv);
  string linha;
  filme movie;
  while (not it.fim()) {
    Par<filme> par = it.proximo();
    movie = par.valor;
    linha = movie.formater();
    arqout << linha << endl;
  }
}


void catalogo::insere_filme(string linha){
  
  filme fin(linha);
  
  stringstream conv;
  conv << fin.sano();
  
  string chave = fin.stitulo() + " " + conv.str();  

  arv->adiciona(chave, fin);

}

filme catalogo::remove_filme(const string & chave){

  return arv->remove(chave);

}
  

filme catalogo::starter(string lin) {

  filme f1(lin);
  return f1;

}


int catalogo::comparador(const string chave, const string comparada){

  if(chave == ""){
   throw 1;
  }

  int c = 0, l = 0, semelhanca = 0;

  lista<string> l1, l2;
  l1 = tokenizer(chave, ' ');
  l2 = tokenizer(comparada, ' ');
  while(c < l1.comprimento()){
    while(l < l2.comprimento()){
      if(l1[c] == l2[l]){
        semelhanca++;
      }
      l++;
    }
    c++;
  }
  return semelhanca;
}
