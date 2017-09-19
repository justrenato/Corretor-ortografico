#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

unsigned char c; // se usar apenas char, nao identifica letras acentuadas :(

int ehletra(){
	return( ((c>64)&&(c<91)) || //igual de maiusculas ou
	 		((c>96)&&(c<123)) || //igual de minusculas ou
			((c>191)&&(c<256))	);	//igual de acentuados //função que identifica se o charactere lido é uma letra
}

int ehsimbolo(){
	return( ((c<65)||(c>90)) && //diferente de maiusculas e
			((c<97)||(c>122)) && //diferente de minusculas e
			((c<192)||(c>255)) ); //diferente de acentuados //função que identifica se o charactere lido é um simbolo
}


int main()
{
	FILE *dicionario;
	dicionario = fopen ("/usr/share/dict/brazilian", "r") ;
	// if(!dicionario) printf("Arquivo nao aberto\n"); else{ printf("Arquivo aberto\n");} //saber se dicionario foi aberto


	char palavra[50];
	int numElem=0;
	c=getc(dicionario);
	while((c!=255)&&(c!=-1)) { //calcula numero de caracteres do dicionario
		numElem++;
		c=getc(dicionario);
	}

	c = getchar();
	while ((c != 255) && (c != -1) ) //enquanto c for diferente de EOF (usar EOF não esta permitindo sair do while :/)
	{

		while((ehsimbolo()) && ((c != 255) && (c != -1))){ //enquanto o charactere lido for simbolo vai imprimindo
			putchar(c);
			c=getchar();
		}

		int i=0; 
		while((ehletra()) && (c!=255)){ //quando ler uma letra vai adicionando ela no vetor palavra até encontrar um simbolo
			palavra[i]=c;
			i++;
			c=getchar();
		}
		
		palavra[i]='\0'; //quando encontrar um simbolo sinaliza o final da palavra
		
		if(1/*existe*/) printf("%s",palavra ); else printf("[%s]",palavra );
	}
		

/*	char strvalues[][20] = {"verme","example","strings","here"};
	qsort (strvalues, 4, 20, (int(*)(const void*,const void*)) strcmp);
	char *existe;
	char palavra[20]= "verme";
	existe = (char*)bsearch( palavra,strvalues,4,20,(int(*)(const void*,const void*)) strcmp);
	printf("%p\n",existe);
	printf("%s\n",existe);
*/
	return 0;
}