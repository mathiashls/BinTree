#include "utils.h"

lista<string> tokenizer(const string & texto, char delimitador){
  
  lista<string> lista_retornadeira;
  int c = 0;
  if(texto != ""){ 


    while(c < texto.size()){
	  string cop;    
	  while(texto[c] != delimitador and c < texto.size()){
  	    cop += texto[c];
  	    c++;
	  }
	  lista_retornadeira.anexa(cop);
	  c++;
    }
  }
  return lista_retornadeira;
 
}

int converte_para_int(const string & dado) {
  istringstream stream(dado);
  int r;
  stream >> r;
  if (stream.fail()) throw 1; // erro de conversão
  return r;
}


float converte_para_float(const string & dado) {
  istringstream stream(dado);
  float r;
  stream >> r;
  if (stream.fail()) throw 1; // erro de conversão
  return r;
}
 
 
double converte_para_double(const string & dado) {
  istringstream stream(dado);
  double r;
  stream >> r;
  if (stream.fail()) throw 1; // erro de conversão
  return r;
}


ostream& operator<<(ostream &out, lista<string> lista) {
	int c = 0;
	if(not lista.vazia()){
    	while(c < lista.comprimento()){
    	out << lista[c]  << " " ;
    	c++;
    	}
    	out << endl;
	}else{
    	out << endl;
	}
	return out;
}


ostream& operator<<(ostream &out, lista<filme> lista) {
	int c = 0;
	if(not lista.vazia()){
    	while(c < lista.comprimento()){
    	out << lista[c]  << endl << endl;
    	c++;
    	}
    	out << endl;
	}else{
    	out << endl;
	}
	return out;
}
