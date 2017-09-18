#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

unsigned char c;

int ehletra(){
	return( ((c>64)&&(c<91)) || //igual de maiusculas ou
	 		((c>96)&&(c<123)) || //igual de minusculas ou
			((c>191)&&(c<256))	);	//igual de acentuados
}

int ehsimbolo(){
	return( ((c<65)||(c>90)) && //diferente de maiusculas e
			((c<97)||(c>122)) && //diferente de minusculas e
			((c<192)||(c>255)) ); //diferente de acentuados
}

int main()
{

	char *endereco ;
	endereco = calloc (SIZE, sizeof(char)) ;




	c = getchar();
	int i=0;
	int sair=0;
	/*while (c != 255)*/while(sair==0) //enquanto c for diferente de EOF (usar EOF não esta permitindo sair do while :/)
	{


		if (ehletra())
		{
			endereco[i]=c;
			
		}else
		{ 
			endereco[i]='\0';
			sair=1;
		}
		i++;



	
		c = getchar();
	}
	printf("[%s]",endereco );
	return 0;
}