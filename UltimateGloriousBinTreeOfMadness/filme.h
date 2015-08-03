#ifndef FILME_H
#define FILME_H

#include "utils.h"
#include "lista.h"

class filme {

  protected:

    string titulo, diretor, url, sinopse;
    lista<string> generos, elenco, paises;
    int ano, votos, duracao;
    float avaliacao, orcamento;
    
  public:

    filme();
    filme(const string & linha);
    ~filme();
    string stitulo();
    int sano();
    float savaliacao();
    int svotos();
    int sduracao();
    float sorcamento();
    lista<string> sgeneros();
    string sdiretor();
    lista<string> selenco();
    lista<string> spaises();
    string surl();
    string ssinopse();
    string formater();

};

ostream& operator<<(ostream & out, filme f1);

#endif
