#include <stdio.h>
#include <stdlib.h>
#include <string.h> // preciso de strcmp

#define NONE -1
#define LIN 275503
#define COL 25
#define string char *

unsigned char c; // se usar apenas char, nao identifica letras acentuadas :(
char * palavra = {"abacate"};

// char * lista[]={""};
// char   lista[][10]={"abacate","banana","danone"};
// char   lista[]={ 'a','b','a','c','a','t','e','\0','b','a','n','a','n','a','\0','d','a','n','o','n','e','\0'};

int BinarySearch( string key, char **array, int low, int high) 
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
	dicionario = fopen ("/usr/share/dict/brazilian", "r") ;
	if(!dicionario) {
		perror("Arquivo nao aberto: "); //saber se dicionario foi aberto
		exit(1);
	}	

	int numElem=0,numPala=0;
	char **mat;
	int i, j ;
	char aux[20];
	// aloca um vetor de LIN ponteiros para linhas
	mat = malloc (LIN * sizeof (int*)) ;

	// aloca um vetor com todos os elementos da matriz
	mat[0] = malloc (LIN * COL * sizeof (int)) ;	

	// ajusta os demais ponteiros de linhas (i > 0)
	for (i=1; i < LIN; i++){
	  mat[i] = mat[0] + i * COL ;
	}
		
	// percorre a matriz
	for (i=0; i < LIN; i++){
		fgets(mat[i],COL,dicionario ) ;
		//printf("%s\n",mat[i] );
	}
		//printf("%s\n",mat[1] );


	printf("%d\n",BinarySearch(palavra,mat,0,LIN));
	return 0;
}