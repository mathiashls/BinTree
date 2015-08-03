#ifndef ARVORE_H
#define ARVORE_H
 
#include <string>
#include <fstream>
#include "lista.h"
 
using namespace std;
 
template <class T> struct Par {

  string chave;
  T valor;
 
  Par(const string& k, const T& dado) {

    chave = k;
    valor = dado;

  }

  Par(const string& k) {

    chave = k;

  }

  Par() {}

  bool operator==(const Par<T> &outro) const {

    return chave == outro.chave;

  }

  bool operator!=(const Par<T> &outro) const {

    return chave != outro.chave;

  }

  bool operator<(const Par<T> &outro) const {

    return chave < outro.chave;

  }

  bool operator>(const Par<T> &outro) const {

    return chave > outro.chave;

  }

};
 
template <class T> class arvore {

  protected:

    Par<T> par; 
    arvore<T> * esq, * dir, * pai; 

  public:

    arvore(const Par<T> & umpar);
    arvore(const string & key, const T& data);
    arvore();
    ~arvore();
    void adiciona(const string & chave, const T & dado);
    void adiciona(const Par<T> & umPar);
    T & obtem(const string & chave);
    T & operator[](const string & chave);
    arvore<T> & operator=(const arvore<T> & outra);
    bool operator==(const arvore<T> & outra);
    bool operator!=(const arvore<T> & outra);
    T remove(const string & chave);
    void esvazia();
    unsigned int altura() const;
    void escrevase(ostream & out) const;
    arvore<T> * esquerda() const;
    arvore<T> * direita() const;
    lista<T> * valores() const;
    lista<string> * chaves() const;
    void valores(lista<T> & lista) const;
    void chaves(lista<string> & lista) const;
    Par<T> obtemRaiz();
    bool existe(const string & chave) const;

    //-FUNÇÕES DE BALANCEAMENTO
    int fatorB() const; //-Operação para calcular o fator de balanceamento
    arvore<T> * balanceia();     //-Operação de balanceia da árvore
    arvore<T> * rotaciona_LL();  //-Rotação esquerda-esquerda
    void rotaciona_LR();         //-Rotação esquerda-direita
    arvore<T> * rotaciona_RR();  //-Rotação direita-direita  
    void rotaciona_RL();         //-Rotação direita-esquerda 
    int tamanho() const;
};

template <class T> class IteradorPreOrder {

  protected:

    lista< arvore<T> * > pilha;
    arvore<T> * atual;

  public:

    IteradorPreOrder(arvore<T> * arv) : pilha() {
      atual = arv;
      pilha.push(arv);
    }

    ~IteradorPreOrder() {
    }

    Par<T> proximo() {
      if(not fim()){
        atual= pilha.pop();
        if(atual -> direita()) pilha.push(atual -> direita());
        if(atual -> esquerda()) pilha.push(atual -> esquerda());
        return atual -> obtemRaiz();
      } else {
        throw 1;
      }
    }

    arvore<T> * proximo_ramo() {
      return pilha.top();
    }

    bool fim() {
      return pilha.vazia();
    }

};

template <class T> arvore<T>::arvore() {

  esq = dir = pai = NULL;

}

template <class T> arvore<T>::arvore(const Par<T> & umPar) : par(umPar) {

  esq = dir = pai = NULL;

}

template <class T> arvore<T>::arvore(const string & key, const T& data) : par(key, data) {

  esq = dir = pai = NULL;

}

template <class T> arvore<T>::~arvore() {

}


template <class T> void arvore<T>::adiciona(const string & chave, const T & dado) {

  Par<T> p1(chave, dado);
  adiciona(p1);

}  

template <class T> void arvore<T>::adiciona(const Par<T> & umPar) {

  arvore<T> * ptr = this;

while(true){
  if(ptr -> par == umPar) {

    ptr -> par.valor = umPar.valor;
    return;

  }

  if(ptr -> par > umPar) {

    if(ptr -> esq == NULL) {
      ptr -> esq = new arvore<T>(umPar);
      ptr -> esq -> pai = ptr;
      return;
    }

    else {

      ptr = ptr -> esq;

    }

  }

  else {

    if(ptr -> dir == NULL) {

      ptr -> dir = new arvore<T>(umPar);
      ptr -> dir -> pai = ptr;
      return;
    }

    else {

      ptr = ptr -> dir;

    }

  }
}
}

template <class T> T arvore<T>::remove(const string & chave){

  Par<T> key;
  Par<T> outropar;
  arvore<T> * aux;
  arvore<T> * aux2;
  arvore<T> * aux3;

  IteradorPreOrder<T> it(this);
  key = par;
  aux = this;
  while(chave != key.chave){
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

  outropar = aux -> par;
  aux -> par = aux2 -> par;
  aux2 -> remove(aux2 -> par.chave);
  return outropar.valor;

} 

template <class T> void arvore<T>::valores(lista<T> & l1) const {

  if (esq != NULL) esq -> valores(l1);

  l1.anexa(par.valor);

  if (dir != NULL) dir -> valores(l1);

}

template <class T> T & arvore<T>::operator[](const string & chave) {

  arvore<T> * aux = this;

  while(true){
    if( aux -> par.chave == chave){
      return aux -> par.valor;
    }
    if(chave < aux->par.chave){
      if (aux -> esq == NULL){
        throw 3;
      }else aux = aux -> esq;
    }else {
      if(aux -> dir == NULL){
        throw 3;
      } else aux = aux -> dir;

    }
  }

}

template <class T> void arvore<T>::escrevase(ostream & out) const {

  if (esq != NULL) esq -> escrevase(out);

  out << this -> par.valor << endl;

  if (dir != NULL) dir -> escrevase(out);

}

template <class T> unsigned int arvore<T>::altura() const {

  unsigned int he=0, hd=0;
  
  if (not esq and not dir) return 0;
  if (esq) he = 1 + esq -> altura();
  if (dir) hd = 1 + dir -> altura();
  if (he > hd) return he;
  return hd;

}

template<class T> int arvore<T>::fatorB() const {

  int hesq = 0, hdir = 0;
 
  if (dir) hdir = 1+dir->altura();
  if (esq) hesq = 1+esq->altura();
  return hesq - hdir;
 
}

template<class T> arvore<T> * arvore<T>::balanceia() {

  arvore<T> * aux=this; 

  if (esq) {
    esq = esq -> balanceia();
    esq->pai = this;
  }
  if (dir) {
    dir = dir -> balanceia();
    dir->pai = this;
  }

  while(aux -> fatorB() < -1) {

   aux-> rotaciona_RL();
   aux = aux->rotaciona_RR();

  }

  while(aux -> fatorB() > 1) {

    aux -> rotaciona_LR();
    aux = aux -> rotaciona_LL();

  }

  return aux;


}

template<class T> arvore<T> * arvore<T>::rotaciona_LL() {

  arvore<T> * aux3 = this;
  arvore<T> * aux2 = aux3 -> esq;
  arvore<T> * aux1 = aux2 -> esq;

  aux3 -> esq = aux2 -> dir;
  aux2 -> dir = aux3;
  aux2 -> pai = aux3 -> pai;
  aux3 -> pai = aux2;
  if(aux3 -> esq) aux3 -> esq -> pai = aux3;
  
  return aux2;

}

template<class T> void arvore<T>::rotaciona_LR() {

  arvore<T> * aux3 = this;
  arvore<T> * aux1 = aux3 -> esq;
  arvore<T> * aux2 = aux1 -> dir;

  if(aux1 -> fatorB() >= 0) return;
  aux3 -> esq = aux2;
  aux1 -> dir = aux2 -> esq;
  aux2 -> esq = aux1;
  aux2 -> pai = aux3;
  aux1 -> pai = aux2;
  if(aux1 -> dir) aux1 -> dir -> pai = aux1;
  return;

}

template<class T> arvore<T> * arvore<T>::rotaciona_RR() {

  
  arvore<T> * aux1 = this;
  arvore<T> * aux2 = aux1 -> dir;
  arvore<T> * aux3 = aux2 -> dir;

  aux1 -> dir = aux2 -> esq;
  aux2 -> esq = aux1;
  aux2 -> pai = aux1 -> pai;
  aux1 -> pai = aux2;
  if(aux1 -> dir) aux1 -> dir -> pai = aux1;
  return aux2;

}

template<class T> void arvore<T>::rotaciona_RL() {

  arvore<T> * aux1 = this;
  arvore<T> * aux3 = aux1 -> dir; 
  arvore<T> * aux2 = aux3 -> esq;

  if(aux3 -> fatorB() <= 0) return;
  aux1 -> dir = aux2;
  aux3 -> esq = aux2 -> dir;
  aux2 -> dir = aux3;
  aux3 -> pai = aux2;
  aux2 -> pai = aux1;
  if(aux3 -> esq) aux3 -> esq -> pai = aux3;
  return;

}

template<class T> arvore<T> * arvore<T>::esquerda() const {
  return(this->esq);
}

template<class T> arvore<T> * arvore<T>::direita() const {
  return(this->dir);
}

template<class T> int arvore<T>::tamanho() const {
  int n = 0;

  if (esq) n += esq->tamanho();
  if (dir) n += dir->tamanho();
  return n+1;
}

template<class T> Par<T> arvore<T>::obtemRaiz() {
  return(par);
}

#endif
