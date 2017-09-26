
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // preciso de strcmp

#define NONE -1

typedef char * string;

// A fun��o BinarySearch recebe uma cadeia de caracteres key e 
// um vetor array[low,high] de cadeias de caracteres cujos 
// elementos est�o em ordem lexicogr�fica (ordem de dicion�rio). 
// A fun��o devolve um �ndice de um elemento de array que seja
// igual a key. Se tal �ndice n�o existe, a fun��o devolve 
// NONE.


char * lista[]={""};
// char   lista[][10]={"abacate","banana","danone"};
// char   lista[]={ 'a','b','a','c','a','t','e','\0','b','a','n','a','n','a','\0','d','a','n','o','n','e','\0'};




char * palavra = "abacate";
int BinarySearch( string key, string array[], int low, int high) 
{
   int mid, cmp;

   if (low > high) return NONE;
   mid = (low + high) / 2;
   cmp = strcmp( key, array[mid]);
   if (cmp == 0 ) 
      return mid;
   if (cmp < 0) 
      return BinarySearch( key, array, low, mid - 1); 
   else 
      return BinarySearch( key, array, mid + 1, high); 
}

int main(int argc, char const *argv[])
{
  FILE *dicionario;
  dicionario = fopen("/usr/share/dict/brazilian","r");
  printf("%d\n",BinarySearch(palavra,lista,0,2));

 for (int i = 0; i < 275503; ++i)
  {
    fgets (&lista[i],100, stdin) ;
  }

   


  return 0;
}