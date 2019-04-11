#include <stdio.h>
#include <stdlib.h>
#define MAX 25
#define TMAX 15
typedef struct pessoa{
    char nome[MAX];
    char telefone[TMAX];
}tPessoa;
typedef struct variaveis{
	int menu;
	int i;
	int cont;
	int tamanhoPbuffer;
	char auxNome[MAX];
}tVariaveis;


tVariaveis *var;
tPessoa *pessoas;


void insere(struct pessoa* pessoas){
		getchar();
        printf("Digite os dados a seguir!\n");
        printf("Nome : ");
        fgets(pessoas->nome, MAX, stdin);
        
        printf("Telefone: ");
        fgets(pessoas->telefone, TMAX, stdin);
}
void deleta(struct pessoa *lista,char* rNome,int* i,int *cont){
	for (*i = 0; *i < *cont; (*i)++){
		printf("pessoa[%d] = %s\n",*i,lista->nome);
	}
}

struct pessoa *retornaLugar(struct pessoa* pessoas,char *rNome,int* i,int* cont){
	for(*i = 0; *i < *cont;(*i)++){
		if(pessoas->nome == rNome) return pessoas;
		pessoas = pessoas+1;
	}
	return NULL;
}

int main(){
    void* pBuffer;
	

    pBuffer = malloc(sizeof(struct variaveis));
	var = pBuffer;
	var->cont = 0;

    printf("\nDigite! \n1 para add contato ,\n2 para retirar contado,\n3 imprimir contatos,\n4 sair do programa! \n\n");
    scanf("%d",&var->menu);

	while(var->menu != 4){
			switch(var->menu){
					case 1:
						var->cont = var->cont+1;
						var->tamanhoPbuffer = (sizeof(struct variaveis)) + (var->cont * sizeof(struct pessoa));

           			 	pBuffer = realloc(pBuffer,var->tamanhoPbuffer);

           			 	var = pBuffer;
           			 	pessoas = pBuffer+(var->tamanhoPbuffer - sizeof(struct pessoa));

            			insere(pessoas);

					break;
					case 2:

						/*printf("Digite o nome que vc deseja remover: \n");
						scanf("%s",xNome);
						pessoas = (pessoas,xNome,i,cont);
						//deleta(pessoas,i,cont);
						if(pessoas == NULL) printf("Este contato nao esta na agenda!!!\n"); 
						pessoas =(char*)xNome+(sizeof(char)*20);*/
						
					break;


					case 3:
						printf("Listando...\n");
						pessoas = pBuffer + (sizeof(struct variaveis));

						for(var->i = 1;var->i <= var->cont; (var->i)++ ){
							printf("===========================\nContato[%d]\n",var->i);
							printf("Nome   = %s",pessoas->nome);
							printf("Numero = %s",pessoas->telefone);
							printf("===========================\n");
							pessoas = pBuffer + (sizeof(struct variaveis) + ((var->i) * sizeof(struct pessoa)));
						}
					break;
			}
		printf("\nDigite! \n1 para add contato ,\n2 para retirar contado,\n3 imprimir contatos,\n4 sair do programa! \n");
		scanf("%d",&var->menu);
	}
	free(pBuffer);

	return 0;
}
