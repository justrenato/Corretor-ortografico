#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "dicionario.h"

unsigned char c; 

int ehletra()
{
	return( ((c>64)&&(c<91)) || //igual de maiusculas ou
	 		((c>96)&&(c<123)) || //igual de minusculas ou
			((c>191)&&(c<256))	);	//igual de acentuados //função que identifica se o charactere lido é uma letra
}


int ehsimbolo()
{
	return( ((c<65)||(c>90)) && //diferente de maiusculas e
			((c<97)||(c>122)) && //diferente de minusculas e
			((c<192)||(c>255)) ); //diferente de acentuados //função que identifica se o charactere lido é um simbolo
}

int BinarySearch( char *key, char **array, int low, int high) 
{
   int mid, cmp;

   if (low > high) return -1;
   mid = (low + high) / 2;
   cmp = strcmp( key, array[mid]);
   if (cmp == 0 ) 
      return mid;
   if (cmp < 0) 
      return BinarySearch( key, array, low, mid - 1); 
   else 
      return BinarySearch( key, array, mid + 1, high); 
}

void InicDic(char **mat)
{
	int i ;
	FILE *dicionario;

	dicionario = fopen ("/usr/share/dict/brazilian", "r") ;
	if(!dicionario) {
		perror("Arquivo nao aberto: "); //saber se dicionario foi aberto
		exit(1);
	}

	
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
	}
}


