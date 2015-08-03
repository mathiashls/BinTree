#include"filme.h"


filme::filme(){

}


filme::filme(const string & linha){
  lista<string> fulerona;
  fulerona = tokenizer(linha, ';');

  if(not fulerona.vazia()){

   if(fulerona.comprimento() > 0  and fulerona[0] != ""){
    titulo = fulerona[0];
   }


   if(fulerona.comprimento() > 1  and fulerona[1] != ""){
    ano = converte_para_int(fulerona[1]);
   }else { ano=0;}


   if(fulerona.comprimento() > 2  and fulerona[2] != ""){
    avaliacao = converte_para_float(fulerona[2]);

   }else { avaliacao=0;}



   if(fulerona.comprimento() > 3  and fulerona[3] != ""){
    votos = converte_para_int(fulerona[3]);

   }else { votos=0;}



   if(fulerona.comprimento() > 4  and fulerona[4] != ""){
    duracao = converte_para_int(fulerona[4]);

   }else { duracao=0;}



   if(fulerona.comprimento() > 5 and fulerona[5] != ""){
    orcamento = converte_para_float(fulerona[5]);

   }else { orcamento=0;}



   if(fulerona.comprimento() > 6 and fulerona[6] != ""){
    generos = tokenizer(fulerona[6], ',');

   }


   if(fulerona.comprimento() > 7  and fulerona[7] != ""){
    diretor = fulerona[7];

   }


   if(fulerona.comprimento() > 8  and fulerona[8] != ""){
    elenco = tokenizer(fulerona[8], ',');

   }


   if(fulerona.comprimento() > 9 and fulerona[9] != ""){
    paises = tokenizer(fulerona[9], ',');

   }


   if(fulerona.comprimento() > 10 and fulerona[10] != ""){

    url = fulerona[10];

   }

   if(fulerona.comprimento() > 11 and fulerona[11] != ""){
    sinopse = fulerona[11];
   }

  }
}

filme::~filme(){

}

string filme::stitulo(){
  return titulo;
}
int filme::sano(){
  return ano;
}
float filme::savaliacao(){
  return avaliacao;
}
int filme::svotos(){
  return votos;
}
int filme::sduracao(){
  return duracao;
}
float filme::sorcamento(){
  return orcamento;
}
lista<string> filme::sgeneros(){
  return generos;
}
string filme::sdiretor(){
  return diretor;
}
lista<string> filme::selenco(){
  return elenco;
}
lista<string> filme::spaises(){
  return paises;
}
string filme::surl(){
  return url;
}
string filme::ssinopse(){
  return sinopse;
}


ostream& operator<< (ostream & out, filme f1){
  out << "titulo: " << f1.stitulo() << endl;
  out << "ano: " << f1.sano() << endl;
  out << "avaliacao: " << f1.savaliacao() << endl;
  out << "votos: " << f1.svotos() << endl;
  out << "duracao: " << f1.sduracao() << endl;
  out << "orcamento: " << f1.sorcamento() << endl;
  out << "generos: " << f1.sgeneros() << endl;
  out << "diretor: " << f1.sdiretor() << endl;
  out << "elenco: " << f1.selenco() << endl;
  out << "paises: " << f1.spaises() << endl;
  out << "url: " << f1.surl() << endl;
  out << "sinopse: " << f1.ssinopse() << endl;
  return out;
}

string filme::formater(){

  string cat[3], valor;
  int c = 0;

  if(not generos.vazia()){  
  generos.inicia();
  while(c < generos.comprimento()){
    cat[0] += generos.proximo();
    if(c == generos.comprimento()) break;
    cat[0] += ",";
    c++;
  }
 }else { cat[0] = "";}

  if(not elenco.vazia()){
  c = 0;
  elenco.inicia();
  while(c < elenco.comprimento()){
    cat[1] += elenco.proximo();
    if(c == elenco.comprimento()) break;
    cat[1] += ",";
    c++;
  } 
  }else{ cat[1] = ""; }
 
  if(not paises.vazia()){
  c = 0;
  paises.inicia();
  while(c < paises.comprimento()){
    cat[2] += paises.proximo();
    if(c == generos.comprimento()) break;
    cat[2] += ",";
    c++;
  }
  }else{ cat[2] = ""; }

  stringstream cano;
  cano << ano;
  
  stringstream cavaliacao;
  cavaliacao << avaliacao;
  
  stringstream cvotos;
  cvotos << votos;
  
  stringstream cduracao;
  cduracao << duracao;
  
  stringstream corcamento;
  corcamento << orcamento;

  valor = titulo + ";" + cano.str() + ";" + cavaliacao.str() + ";" + cvotos.str() + ";" + cduracao.str() + ";" + corcamento.str() + ";" + cat[0] + ";" + diretor + ";" + cat[1] + ";" + cat[2] + ";" + url + ";" + sinopse; 
  return valor;

} 
