#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 25
#define TMAX 15
#define OFFSET 97
typedef struct pessoa{
    char nome[MAX];
    char telefone[TMAX];
}tPessoa;
typedef struct variaveis{
	int menu;
	int i;
	int j;
	int cont;
	int tamanhoPbuffer;
	char auxNome[MAX];
	char auxTelefone[TMAX];
	tPessoa *auxRemove;
}tVariaveis;

tVariaveis *var;
tPessoa *pessoas;
void* pBuffer;

void nomesIniciais(){
	preenche();
	strcpy(pessoas->nome,"Darlei\n");
	strcpy(pessoas->telefone,"11111\n");

	preenche();
	strcpy(pessoas->nome,"Ana\n");
	strcpy(pessoas->telefone,"222222\n");

	preenche();
	strcpy(pessoas->nome,"Paula\n");
	strcpy(pessoas->telefone,"333333\n");

	preenche();
	strcpy(pessoas->nome,"Bruna\n");
	strcpy(pessoas->telefone,"44444\n");


}
void preenche(){
		var->cont = var->cont+1;
        var->tamanhoPbuffer = (sizeof(struct variaveis)) + (var->cont * sizeof(struct pessoa));
        pBuffer = realloc(pBuffer,var->tamanhoPbuffer);

        var = pBuffer;
        pessoas = pBuffer+(var->tamanhoPbuffer - sizeof(struct pessoa));
}

void insere(){
        var->cont = var->cont+1;
        var->tamanhoPbuffer = (sizeof(struct variaveis)) + (var->cont * sizeof(struct pessoa));
        pBuffer = realloc(pBuffer,var->tamanhoPbuffer);

        var = pBuffer;
        pessoas = pBuffer+(var->tamanhoPbuffer - sizeof(struct pessoa));

		getchar();

        printf("Digite os dados a seguir!\n");
        printf("Nome : ");
        fgets(pessoas->nome, MAX, stdin);

        printf("Telefone: ");
        fgets(pessoas->telefone, TMAX, stdin);
}
void deleta(){
	printf("Digite o nome do contato que vc deseja excluir: ");
	getchar();
	fgets(var->auxNome, MAX, stdin);
	//printf("%s",var->auxNome);
	var->i = 0;
	pessoas = pBuffer + (sizeof(struct variaveis));
	while(strcmp(var->auxNome,pessoas->nome) != 0 && var->i < var->cont){

        pessoas = (tPessoa*)pessoas+1 ;
        var->i = var->i + 1;

	}
    if(var->i == var->cont){
    printf("Este nome nao esta na agenda!\n ");
    }
    else{
        var->auxRemove = (tPessoa*)pessoas+1;

        while(var->i < var->cont){
            strcpy(pessoas->nome,var->auxRemove->nome);
            strcpy(pessoas->telefone,var->auxRemove->telefone);

            var->auxRemove = (tPessoa*)var->auxRemove+1;
            pessoas = (tPessoa*)pessoas+1;
            var->i = var->i+1;
        }
        var->cont = var->cont -1;
        var->tamanhoPbuffer = (sizeof(struct variaveis)) + (var->cont * sizeof(struct pessoa));
        pessoas = pBuffer+(var->tamanhoPbuffer - sizeof(struct pessoa));
       /* if(!pessoas){
            return -1;
        }*/
        printf("Contato removido com sucesso!\n");
    }


}
void listar(){
	printf("Listando...\n");
	pessoas = pBuffer + (sizeof(struct variaveis));
	for(var->i = 0;var->i < var->cont; (var->i)++ ){
		printf("===========================\nContato[%d]\n",var->i);
		printf("Nome   = %s",pessoas[var->i].nome);
		printf("Numero = %s",pessoas[var->i].telefone);
		printf("===========================\n");
		//pessoas = pBuffer + (sizeof(struct variaveis) + ((var->i) * sizeof(struct pessoa)));
	}
}
void insertionSort(){

	pessoas = pBuffer + (sizeof(struct variaveis) );
	for (var->j = 1; var->j < var->cont; (var->j)++) {

    	var->i = var->j - 1;
    	strcpy(var->auxNome , pessoas[var->j].nome);
		strcpy(var->auxTelefone , pessoas[var->j].telefone);

		//strcmp(str1, str2) > 0 ent? str1 > str2 se strcmp(str1, str2) < 0 ent? str1 < str2 se strcmp(str1, str2) == 0 ent? str1 
		//== str2   O que tamb? implica que: se strcmp(str1, str2) >= 0 ent? str1 >=
    	while ( (var->i >= 0) && ((strcmp(var->auxNome ,pessoas[var->i].nome)) < 0 )) { //while ( (i>=0) && (tmp < data[i]) )
		
        	strcpy(pessoas[var->i +1].nome,pessoas[var->i].nome);
			strcpy(pessoas[var->i +1].telefone,pessoas[var->i].telefone);

        	(var->i)--;

    	}
    	strcpy(pessoas[var->i +1].nome ,var->auxNome );
    	strcpy(pessoas[var->i +1].telefone,var->auxTelefone);
	}
}

int main(){
    //void* pBuffer;


    pBuffer = malloc(sizeof(struct variaveis));
	var = pBuffer;
	var->cont = 0;
	nomesIniciais();

    printf("\nDigite! \n1 para add contato ,\n2 para retirar contado,\n3 imprimir contatos,\n4 sair do programa! \n5 ordenar\n\n");
    scanf("%d",&var->menu);

	while(var->menu != 4){
			switch(var->menu){
					case 1:
                        insere();
					break;
					case 2:
                        deleta();
					break;
					case 3:
						listar();					
					case 5:
						insertionSort();
					break;
			}
		printf("\nDigite! \n1 para add contato ,\n2 para retirar contado,\n3 imprimir contatos,\n4 sair do programa! \n5 ordenar\n");
		scanf("%d",&var->menu);
	}
	free(pBuffer);

	return 0;
}
