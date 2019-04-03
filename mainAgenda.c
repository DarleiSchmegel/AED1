#include <stdio.h>
#include <stdlib.h>
struct pessoa{
    char nome[20];
    int teleone;
};

void insere(void* pBuffer,int* i,int* quantAdd,int* quantTotal,struct pessoa* pessoas){
    //*i = 0;
	(*quantTotal) += (*quantAdd);
	pBuffer = (void*)realloc(pBuffer,(4*sizeof(int))+((*quantTotal)*(sizeof(struct pessoa))));

    for((*i) = 0;(*i) < (*quantAdd);(*i)++){
    	printf("Digite o nome da nova pessoa da agenda: ");
    	scanf("%s",&(*pessoas->nome));
    	pessoas++;

    }

}/*
void reallocar(void **pBuffer,int *novoTamanho){
    (*pBuffer) = (void*)realloc(*pBuffer,(*novoTamanho)*(sizeof(struct pessoa)));
}*/

int main(){
	void *pBuffer;
	int *i;//pBuffer[0]
	int *j;//pBuffer[1]
	int *k;//pBuffer[2]
	int *quantPessoas;//somatorio das n pessoas na agenda! pBuffer[3]
	struct pessoa *pessoas,*primeiraPessoa;//ponte para o ultimo e para o primeiro


    pBuffer = malloc((sizeof(int))+(sizeof(int))+sizeof(int)+sizeof(int)+sizeof(struct pessoa));
    i =(int*) pBuffer;
    j = (int*)i+1;
    k = (int*) j+1;
    quantPessoas = (int*)k+1;
    pessoas = (struct pessoa*)quantPessoas+1;
    primeiraPessoa = (struct pessoa*)quantPessoas+1;
    *quantPessoas = 0;
	*i = 0;
	

	printf("Digite! \n1 para add contato ,\n2 para retirar contado,\n3 imprimir contatos,\n4 sair do programa! \n");
	scanf("%d",i);
	while((*i) != 4){
			switch(*i){
					case 1:
						printf("Digite quantos contatos vc deseja add na agenda: ");
						scanf("%d",j);

						insere(pBuffer,i,j,quantPessoas,pessoas);
						*i = 1;
						
					break;
					case 2:
						
						
					break;
						

					case 3:
						printf("Printar");
						pessoas = primeiraPessoa;
						
						for(*i = 1;*i <= *quantPessoas; (*i)++ ){
							printf("Pessoa numero[%d] = %s\n",*i,pessoas->nome);
							pessoas++;
						}
						pessoas = primeiraPessoa;
					break;


			}
		printf("Digite! \n1 para add contato ,\n2 para retirar contado,\n3 imprimir contatos,\n4 sair do programa! \n");
		scanf("%d",i);




	}

	//printf("%s",pessoas->nome);

    //printf("I = %d\n",*i);
   // printf("J = %d\n",*k);


	free(pBuffer);

	return 0;
}