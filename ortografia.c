// ver wchar_t
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define string char *
#define SIZE 100
#define NONE -1
#define LIN 275503
#define COL 25

unsigned char c; // se usar apenas char, nao identifica letras acentuadas :(


int compareints (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

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








	
	c=getc(dicionario);
	while(!feof(dicionario)) { //calcula numero de caracteres do dicionario
		numElem++;
		if(c=='\n') numPala++;
		c=getc(dicionario);
	}

	// char vetorDici[numPala*20];
	// fseek (dicionario,  0, SEEK_SET) ;
	// int preencherPalavra=0;
	// int j = 0;
	
	// c=getc(dicionario); 
	// while ( j < numPala*20 ) //passar dicionario para um vetor para tentar usar o bsearch ;/
	// {
	// 	if (preencherPalavra==1)
	// 	{
	// 		vetorDici[j]='\0';
	// 	}else{ 
	// 		if (c!='\n'){
	// 			vetorDici[j]=c;
	// 			c=getc(dicionario);
	// 		}
	// 		else {
	// 			preencherPalavra=1;
	// 		} 
	// 	}
	// 	if (((j+1)%20)==0)
	// 			{
	// 				preencherPalavra=0;
	// 				c=getc(dicionario);

	// 			}
	// 	++j;
	// }



	

	// char *existe;
	// char palavra[20]= "Abadiânia";
	// existe = (char*)bsearch( palavra,vetorDici,4,20, (int(*)(const void*,const void*)) compareints);
	// printf("%p\n",existe);
	// printf("%s\n",existe);
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


		if (palavraMinuscula[i] >= 'A' && palavraMinuscula[i] <= 'Z') // se for letra minúscula
		{
			palavraMinuscula[i] += 32 ;  
		} 
		if (palavraMinuscula[i] >= 'À' && palavraMinuscula[i] <= 'Ü') // se for letra minúscula
		{
			palavraMinuscula[i] += 32 ;  
		}
			
			i++;
			c=getc(stdin);
		}
		
		palavra[i]='\n'; //quando encontrar um simbolo sinaliza o final da palavra
		palavra[i+1]='\0'; //quando encontrar um simbolo sinaliza o final da palavra

		palavraMinuscula[i]='\n'; //quando encontrar um simbolo sinaliza o final da palavra
		palavraMinuscula[i+1]='\0'; //quando encontrar um simbolo sinaliza o final da palavra
		
		




	// for (i=0; i < strlen (palavra); i++)      // varre todos os caracteres
	// {
	// 	if (palavra[i] >= 'A' && palavra[i] <= 'Z') // se for letra minúscula
	// 	{
	// 		palavra[i] += 32 ;  
	// 	} 
	// 	if (palavra[i] >= 'À' && palavra[i] <= 'Ü') // se for letra minúscula
	// 	{
	// 		palavra[i] += 32 ;  
	// 	}
	// }





	//	printf("%d\n",BinarySearch(palavra,mat,0,LIN));

		encontrou = BinarySearch(palavraMinuscula,mat,0,LIN);

		palavra[i]='\0'; //quando encontrar um simbolo sinaliza o final da palavra
		palavraMinuscula[i]='\0'; //quando encontrar um simbolo sinaliza o final da palavra

		

		if(encontrou>0) printf("%s",palavra ); else printf("[%s]",palavra );
	}



	// char dici[][20]={""};                      // passa o dicionario para um vetor
	// int j=0,i=0;

	// c = getc(dicionario);
	// while (!feof(dicionario)){
	// 	if (c=='\n')
	// 	{
	// 		dici[i][j]='\0'; // se for quebrar linha, insere caracter nulo indicando fim da string
	// 		i++; // passa para a proxima palavra
	// 		j=0; // seta j para 0 para colocar novas palavras no inicio do vetor
	// 	}
	// 	dici[i][j]=c;
	// 	j++;
	// 	c = getc(dicionario);
	// }
	
	// for (int i = 0; i < j; ++i)
	// {
	// 	// if (dici[i]=='\n')
	// 	// {
	// 	// 	dici[i]='\0';
	// 	// }
	// 	printf("%c",(dici[i]));
	// }



	// printf("\n");
	// char teste[][20]={"Aarão","Abade","Abadia","Abadiânia","Abaetetuba","Abaeté","Abaiara","Abaixo","Abaré","Abatiá"};
	// for (int i = 0; i < 200; ++i)
	// {
	// 	putchar(teste[0][i]);
	// 	// printf("%c = ",teste[0][i]);
	// 	// putchar(vetorDici[i]);
	// }
	// 	printf("\n");



	// char strvalues[][20] = {"verme","example","strings","here"};
	// qsort (strvalues, 4, 20, (int(*)(const void*,const void*)) strcmp);
	// char *existe;
	// char palavra[20]= "verme";
	// existe = (char*)bsearch( palavra,strvalues,4,20, (int(*)(const void*,const void*)) compareints);
	// printf("%p\n",existe);
	// printf("%s\n",existe);

	return 0;
}