#ifndef __DICIONARIO__
#define __DICIONARIO__
#define LIN 275503
#define COL 25

//retorna um valor não nulo se o caracter lido é uma letra
int ehletra();

//retorna um valor não nulo se o caracter lido é uma simbolo
int ehsimbolo();

//retorna um valor não nulo se a palavra informada for encontrada no vetor informado.
int BinarySearch( char *key, char **array, int low, int high) ;

void InicDic();
#endif