#ifndef UTILS_H
#define UTILS_H


#include "lista.h"
#include <string>
#include <fstream>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <sstream>
#include <cstdlib>
#include "filme.h"

ostream& operator<<(ostream &out, lista<string> lista);
int converte_para_int(const string & dado);
float converte_para_float(const string & dado);
double converte_para_double(const string & dado);
lista<string> tokenizer(const string & texto, char delimitador);

#endif

