#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;
 

// Esta struct Ã© usada para representar nodos da lista
template <class T> struct nodo {

  T dado;
  nodo * proximo;
  nodo * anterior; // usar no caso de lista duplamente encadeada
  nodo(const T & umDado); // constructor da struct ... conveniente para criar uma variÃ¡vel do tipo Nodo

};

 
// a classe Lista representa listas encadeadas
template <class T> class lista {

  protected:

    nodo<T> * inicio, * fim, * atual; // atributos da classe: referencias ao primeiro e Ãºltimo nodos da lista
    int comp;// conta quantos nodos existem na lista

  public:

    lista(); // construtor da class
    ~lista(); // destrutor ...
    T& inicia();
    T& proximo();
    bool end() const;
    void adiciona(const T & umDado); // adiciona no inicio
    void anexa(const T & umDado); // acrescenta ao final
    void insere(const T & umDado, int posicao); // insere em uma posiÃ§Ã£o qualquer
    T remove(int posicao); // remove de uma posiÃ§Ã£o
    T remove(const T & algo); // remove uma determinada string
    T& operator[](int pos); // equivalente a "obtem"
    bool vazia(); // retorna verdadeiro se a lista estiver vazia
    int comprimento(); // retorna o comprimento da lista
    void esvazia(); // esvazia a lista
    void escrevase(ostream & out);// escreve a lista em um arquivo separando as palavras por linha	
    void escrevase(ostream & out, char delimitador);// escreve a lista em um arquivo separando as palavras por um delimitador ex:.um csv
    void insereordenado(T algo);//insere ordenando a lista em ordem decrecente, onde o primeiro 'e o maior e o ultimo o menor...
    void operator=(lista<T> lista2);//funÃ§~ao que habilita  lista a se comparar com outra
    T& procura(T& algo) const;        
    void ordenaBolha();
    bool operator<(lista<string> outralista);
    bool operator==(lista<string> outralista); 

//  ##########~FUNÇÕES DE PILHA IMPLEMENTADAS NA LISTA~##########

    void push(T dado); // empilha um dado
    T pop(); // desempilha um dado
    T top(); // retorna o dado do topo da pilha, sem retirá-lo

};

//                        ############### construtores e destrutres de classes ou structs ###############
// Construtor da struct, se comporta como construtor de uma classe -m

template <class T> nodo<T>::nodo(const T & umDado) { 
		
  proximo = NULL;
  anterior = NULL;
  dado = umDado;
		
}

//construtor da lista...
template <class T> lista<T>::lista() {

  inicio = NULL;
  fim = NULL;
  comp = 0;
			
}

// Destrutor da classe, existe (NESSECASO) por protocolo -m
template <class T> lista<T>::~lista() { 
				
}

//                          ################# metodos de inserção da lista #########################

template <class T> void lista<T>::adiciona(const T & umDado) { 
			
  nodo<T> * aux = new nodo<T>(umDado);
  aux -> proximo = inicio;

  if(inicio == NULL) {

		inicio = aux;
		fim = inicio;			

	}

  else {

    inicio -> anterior = aux;
		inicio = aux;

	}
						
	comp++;

}
   
template <class T> void lista<T>::anexa(const T & umDado) { //Acrescenta ao final -l

  nodo<T> * aux = new nodo<T>(umDado);

  if (comp == 0) { // Caso seja o primeiro nodo<T> inserido na lista, basta apontar inicio e fim para tal nodo -m

    fim = aux;
    inicio = fim;

  }

  else {          

    fim -> proximo = aux;
    aux -> anterior = fim;
    aux -> proximo = NULL;
    fim = aux;

  }

  comp++;

}
		
template <class T> void lista<T>::insere(const T & umDado, int posicao) {

  if(posicao == 0) { // Verificar se a posiÃ§Ã£o nÃ£o Ã© a primeira. Se sim, usa a funÃ§Ã£o adiciona -m

    adiciona(umDado);
    return;

  }
            
  if(posicao == (comp)) { // Verifica se a posiÃ§Ã£o nÃ£o Ã© a Ãºltima. Se sim, chama a funÃ§Ã£o anexa -m

    anexa(umDado);
    return;

  }
						
  nodo<T> * aux = new nodo<T>(umDado);
  nodo<T> * aux2 = inicio;
  int x = 0;
      
  do {

    aux2 = aux2 -> proximo;
    x++;      	

  }

  while ((posicao) != x);      

  comp++;
            
  aux -> proximo = aux2;
  aux -> anterior = aux2 -> anterior;       
  aux2 -> anterior -> proximo = aux;
  aux2 -> anterior = aux;

}

//insere ordenado s'o funciona se a lista ja estiver ordenada ou vazia... caso nao esteja utilize bubblesort...
template <class T> void lista<T>::insereordenado(T algo) {

  if(inicio == NULL){

    anexa(algo);
    return;

  }

  int c = 0;
  if((inicio -> dado) < algo) {

    adiciona(algo);
    return;

  }

  if(algo < fim -> dado){

    anexa(algo);
    return;

  }
 
  nodo<T>* aux = inicio; 
  while(c < comp) {

    if (aux -> dado < algo) {

      insere(algo, c);
      return;

    }

    else {

      aux = aux -> proximo;
      c++;

    }

    if(aux -> dado == algo) {

      insere(algo, c);
      return;

    }

  }             

} 

	
//                  ################ metodos de remoÃ§~ao da lisa ################a

// remove uma string escolhida pelo usiario
template <class T> T lista<T>::remove(const T & algo) { 
  
  T var_ret, dado;
  int c = 0;
  
  inicia();

  while(not end()) {

    dado=proximo();

    if(dado == algo){
      
      return remove(c);

    }

    c++;
    
  }
 
  throw 666;
  
}

template <class T> T lista<T>::remove(int posicao) { 

  T var_ret;
  nodo<T> * aux = inicio;
  
  if(vazia()) throw 1;
			
  if (posicao >= comp) throw 2;

  for(int x=0; x < (posicao); x++)  {

    aux = aux -> proximo;

  }

	if(aux -> anterior == NULL) {

    if(aux -> proximo == NULL) {
     
      var_ret = aux -> dado;
      esvazia();
      return var_ret;
       
    }

	  var_ret = aux -> dado;
	  aux -> proximo -> anterior = NULL;
	  inicio = aux -> proximo;
	  delete aux;
	  comp--;
    return var_ret;

  }

	if(aux -> proximo == NULL) {

    var_ret = aux -> dado;
    aux -> anterior -> proximo = NULL;
    fim = aux -> anterior;
	  delete aux;
	  comp--;
	  return var_ret;
	
	} 
	
	var_ret = aux -> dado;
	aux -> anterior -> proximo = aux -> proximo;
	aux -> proximo -> anterior = aux -> anterior;
	delete aux;
	comp--;
	return var_ret;
	
}

// esvazia a lista
template <class T> void lista<T>::esvazia() {

	inicio = NULL;
	fim = NULL;
	comp = 0;	// nao sei se precisa dar um delete aqui em algum lugar ou se isso ja fica meio que induzido qualquer coisa so falta o delete
		
}

		
//                                 ############# metodos de interaÃ§~ao da lista ##############a


// equivalente a "obtem"
template <class T> T& lista<T>::operator[](int pos) {

  if(pos < comp){
 
    nodo<T> * aux2 = inicio;
    for(int x=0; x < comp; x++) { 

      if(x == pos){

        return (aux2 -> dado); 

      }

      aux2 = aux2 -> proximo;	

    }
      
  	throw 1;

  }

  throw 2;

}

		
// retorna verdadeiro se a lista estiver vazia
template <class T> bool lista<T>::vazia() { 

	if(inicio == NULL) {

    return true;

  }

  else {

    return false; 

  }

}
		
// retorna o comprimento da lista
template <class T> int lista<T>::comprimento() {

  return (comp);

}
    
//escreve a lista em um arquivo, separando os nodos por linha
template <class T> void lista<T>::escrevase(ostream & out){

  nodo<T> * aux = inicio;
  int c = 0;
  if(comp == 0){

    out << "nao ha dados a serem mostrados" << endl;
    return;

  }

  for( ;  ; ) {

    out  <<  aux -> dado << endl;
    aux = aux -> proximo;

    if(c == (comp - 1)) {

      break;

    }

    c++;

  }

}

//escreve a lista em um arquivo, separando os nodos por um delimitador a escolha
template <class T> void lista<T>::escrevase(ostream & out, char delimitador) { 

  nodo<T> * aux = inicio;
  int c = 0;

  if(comp == 0) {

    out << "nao ha dadosaseremmostrados" << endl;
    return;

  }

  for( ;  ; ) {

    out  <<  aux -> dado << delimitador;
  	aux = aux -> proximo;
    if(c == (comp - 1)) {

      break;

    }
    c++;

  } 
		
}

//metodo de atribuição do conteudo de uma lista para outra lista...                  
template <class T> void lista<T>::operator=(lista<T> lista2){
    esvazia();
    if(not lista2.vazia()){
        int c = 0;
        T aux;
        while(c < lista2.comprimento()){
            aux = lista2[c];
            insere(aux, c);
            c++;
            //cout << "num de pos de lista sendo copiada: " << c << endl;
        }
    }
}
            

template <class T> T& lista<T>::procura(T& algo) const {
     
     nodo<T> * aux2 = inicio;
 
     for(int x=0; x < comp; x++) {
         if(algo == aux2 -> dado){
             return (aux2 -> dado);
         }
         aux2 = aux2 -> proximo;
     }
     throw 3;
 

}        
      


template <class T> void lista<T>::ordenaBolha() {
/*
    nodo<T> * aux1=NULL;
    nodo<T> * aux2=NULL;
    nodo<T> * aux3=NULL;
    nodo<T> * aux4=NULL;

      for(aux1 = inicio; aux1 != fim -> anterior; aux1 = aux1 -> proximo) {

        for(aux2 = inicio -> proximo; aux2 != NULL; aux2 = aux2 -> proximo) {

            if((aux1 -> dado).compare(aux2 -> dado) > 0) {

              aux3 = aux2 -> anterior;
              aux4 = aux2 -> proximo;
              aux2 -> proximo = aux1 -> proximo;
              aux2 -> anterior = aux1 -> anterior;
              aux1 -> proximo = aux4;
              aux1 -> anterior = aux3;

              if(aux1 -> proximo == NULL) {

                  fim = aux1;

              }

              if(aux2 -> anterior == NULL) {

                  inicio = aux2;

              }
            }
        }
      }*/
  
    nodo<T> * aux_c = inicio;
    nodo<T> * aux_l = inicio -> proximo;
    //int c = 0;
    //int l = 0;
    cout << "entrou no bubblesort" << endl;
    cout << "valor de (comp - 1) " << (comp - 1) << endl;
    //T aux1;
    //T aux2;
    for(int c = 0;c < (comp - 1);c++){

    //while(c < (comp - 1)){
    	cout << "entrou no for do c" << endl;
    	//aux1 = operator[](c);
    	//cout << "valor de aux1 " << aux1 <<endl;
        //l = c + 1;

        
		for(int l = c + 1;l < comp; l++){
        //while(l < comp){
        	cout << "entrou no for do l" << endl;        	
            //aux2 = operator[](l);
            //cout << "valor de aux2 " << aux2 << endl;

            if(aux_c -> dado < aux_l -> dado){ // aux1 < aux2
                cout << "entrou no if" << endl;
                cout << "ponteiro que deu bosta"  << aux_c -> anterior -> proximo << endl;
                    
                
                aux_c -> anterior -> proximo = aux_l;
                cout << "segunda ponteiragem" << endl;
                aux_c -> proximo = aux_l -> proximo;
                cout << "terceira ponteiragem" << endl;
                aux_l -> proximo = aux_c;
                cout << "quarta ponteiragem" << endl;
                aux_c -> proximo -> anterior = aux_c;
                cout << "quinta ponteiragem" << endl;
                aux_c -> anterior -> proximo -> anterior = aux_c -> anterior;
                cout << "sexta ponteiragem" << endl;
                aux_c -> anterior = aux_c -> anterior -> proximo;
                cout << "setima ponteiragem" << endl;
                
                
                cout << "final do if" << endl; 
                cout << "valor de c e l respectivamente " << c << l << endl;
          /*      aux1 = remove(c);
                aux2 = remove(l);
                cout << "valor de aux1 " << aux1 << endl;
                cout << "valor de aux2 " << aux2 << endl;
                insere(aux1, l);
                insere(aux2, c); */
            }
            
            //l++;
            aux_l = aux_l -> proximo;
            cout << "deu bosta 1" << endl;
        }
        //c++;
        aux_c = aux_c -> proximo;
        cout << "deu bosta 2" << endl;
    }
}
                           
/* para j da posicao 0 atÃ© o penÃºltimo item da lista
  para k da posicao j+1 atÃ© o fim da lista
    se nodo k < nodo j entÃ£o troca suas posiÃ§Ãµes
  fim para
fim para/
    }
    





}

*/

template <class T> T& lista<T>::inicia() {

  if (vazia()) throw 1;
 
  atual = inicio;

}

template <class T> T& lista<T>::proximo() {

  if (end()) throw 1;

   T & dado = atual -> dado;
   atual = atual -> proximo;
 
   return dado;

}

template <class T> bool lista<T>::end() const {

  return atual == NULL;

}

template <class T> bool lista<T>::operator<(lista<string> outralista){
    if(comp < outralista.comprimento()){
        return 1;
    }else{
        return 0;
    }
}

template <class T> bool lista<T>::operator==(lista<string> outralista){
      if(comp == outralista.comprimento()){
          return 1;
      }else{
          return 0;
      }
  }

template <class T> void lista<T>::push(T dado) {

  adiciona(dado);

}

template <class T> T lista<T>::pop() {

  return remove(0);

}

template <class T> T lista<T>::top() {

  return operator[](0); //Implementada nessa sintaxe por motivo de não saber como aplicar usando 'lista[1]' - teria que ser passado uma lista para a função 'top()'?  

}

#endif

