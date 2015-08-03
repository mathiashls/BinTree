#ifndef CATALOGO_H
#define CATALOGO_H
 
#include "filme.h"
#include "arvore.h"
#include "utils.h"
#include "lista.h"
 
class catalogo {

  protected:

    arvore<filme > * arv;
    string caminho_arquivo;
    int cont;
    filme starter(string lin);
 
  public:
 
    catalogo(char * path);
    ~catalogo();
    filme pesquisa(const string chave);
    lista<filme> pesquisa_parcial(const string chave);
    void exporta(char * path);
    filme pesquisa_ator(string ator);
    filme pesquisa_genero(string genero);
    filme pesquisa_diretor(string diretor);
    void insere_filme(string linha);
    filme remove_filme(const string & chave);
    void altera_campo();
    int comparador(const string chave, const string comparada);

};
 
#endif
