// ver wchar_t
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dicionario.h"
#define string char *
#define SIZE 100
#define NONE -1
#define LIN 275503
#define COL 25

unsigned char c; // se usar apenas char, nao identifica letras acentuadas :(


int main()
{
	FILE *dicionario;
	dicionario = fopen ("/usr/share/dict/brazilian", "r") ;
	if(!dicionario) {
		perror("Arquivo nao aberto: "); //saber se dicionario foi aberto
		exit(1);
	}	

	int numElem=0,numPala=0; //criando matriz com ponteiros
	char **mat;
	int i ;
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

	c=getc(dicionario);
	while(!feof(dicionario)) { //calcula numero de caracteres do dicionario
		numElem++;
		if(c=='\n') numPala++;
		c=getc(dicionario);
	}

	char palavra[20];
	char palavraMinuscula[20];
	int encontrou;
	c = getc(stdin);
	while (!feof(stdin) ) //enquanto c for diferente de EOF (usar EOF não esta permitindo sair do while :/)
	{
		while((ehsimbolo()) && (!feof(stdin))){ //enquanto o charactere lido for simbolo vai imprimindo
			putchar(c);
			c=getc(stdin);
		}

		int i=0; 
		while((ehletra()) && (!feof(stdin))) { //quando ler uma letra vai adicionando ela no vetor palavra até encontrar um simbolo
			palavra[i]=c;
			palavraMinuscula[i]=c;


			if (palavraMinuscula[i] >= 65 && palavraMinuscula[i] <= 90) // se for letra minúscula
			{
				palavraMinuscula[i] += 32 ;  
			} 
			if (palavraMinuscula[i] >= 192 && palavraMinuscula[i] <= 255) // se for letra minúscula
			{
				palavraMinuscula[i] += 32 ;  
			}
			
			// if (palavraMinuscula[i] >= -64 && palavraMinuscula[i] <= -1) // se for letra minúscula
			// {
			// 	palavraMinuscula[i] += 32 ;  
			// }

			// if (ftell (stdin)==3797)
			// {
			// 	printf("int: %d, char: %c.\n",palavraMinuscula[i],palavraMinuscula[i] );
			// }


			i++;
			c=getc(stdin);

		}
		
		palavra[i]='\n'; //quando encontrar um simbolo sinaliza o final da palavra
		palavra[i+1]='\0'; //quando encontrar um simbolo sinaliza o final da palavra

		palavraMinuscula[i]='\n'; //quando encontrar um simbolo sinaliza o final da palavra
		palavraMinuscula[i+1]='\0'; //quando encontrar um simbolo sinaliza o final da palavra
		
		
		encontrou = BinarySearch(palavraMinuscula,mat,0,LIN);

		palavra[i]='\0'; //quando encontrar um simbolo sinaliza o final da palavra
		palavraMinuscula[i]='\0'; //quando encontrar um simbolo sinaliza o final da palavra

		if(encontrou>0) printf("%s",palavra ); else printf("[%s]",palavra );
	}
	return 0;
	int fcloseall (void);
}