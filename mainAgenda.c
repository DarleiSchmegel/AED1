#include <stdio.h>
#include <stdlib.h>
struct pessoa{
    char nome[20];
    int teleone;
};

void insere(void *pBuffer,int *quantAdd){
	int *quantAcumulada;
	quantAcumulada = pBuffer;
	
	printf("%d\n",*quantAcumulada);
	//printf("%d\n",quantAcumulada);

	
    

}

int main(){
	void *pBuffer;
	int *i;//pBuffer[0]
	int *j;//pBuffer[1]
	int *k;//pBuffer[2]
	int *quantPessoas;//somatorio das n pessoas na agenda! pBuffer[3]


    pBuffer = malloc((sizeof(int))+(sizeof(int))+sizeof(int)+sizeof(int));
    i =(int*) pBuffer;
    j = (int*)i+1;
    k = (int*) j+1;
    quantPessoas = (int*)k+1;
    *quantPessoas = 0;
	

	printf("Digite 1 para add contato ,2 para retirar contado,3 imprimir contatos,4 sair do programa! \n");
	scanf("%d",&(*i));
	while((*i) != 4){
			switch(*i){
					case 1:
						printf("Digite quantos contatoss vc deseja add na agenda: ");
						scanf("%d",&(*j));
						
						insere(pBuffer,j);
					
					
					break;
					case 2:
					
					break;
					
					case 3:
					
					break;
				
				
			}
		printf("Digite 1 para add contato ,2 para retirar contado,3 imprimir contatos,4 sair do programa! \n");
		scanf("%d",&(*i));
		
		
		
		
	}
	
	

    //printf("I = %d\n",*i);
    //printf("J = %d\n",*j);


	free(pBuffer);

	return 0;
}
