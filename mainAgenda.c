#include <stdio.h>
#include <stdlib.h>
struct pessoa{
    char nome[20];
    int teleone;
};
void aponta(void** pBuffer,int** menu,int** i,int** cont,char** nome){
    *menu = *pBuffer;
    *i = *menu+1;
    *cont = *i+1;
    *nome = *cont+1;
}
void insere(struct pessoa* pessoas){

        printf("Digite os dados a seguir!\n");
        printf("Nome : ");
        getchar();
        scanf("%s",pessoas->nome);
        getchar();
        printf("Telefone: ");
        scanf("%d",&pessoas->teleone);

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
    int* menu;
    int* i;
    int* cont;
    char *xNome;

    struct pessoa* pessoas;

    pBuffer = malloc(3*sizeof(int)+(sizeof(char)*20));
    aponta(&pBuffer,&menu,&i,&cont,&xNome);

    *cont = 0;

    printf("\nDigite! \n1 para add contato ,\n2 para retirar contado,\n3 imprimir contatos,\n4 sair do programa! \n\n");
    scanf("%d",menu);
	while((*menu) != 4){
			switch(*menu){
					case 1:

            			*cont = *cont+1;
						//pBuffer = realloc(pBuffer,((3*sizeof(int))+(*cont)*sizeof(struct pessoa)));
           			 	pBuffer = realloc(pBuffer,(sizeof(int)*3+sizeof(struct pessoa)*(*cont)));

            			aponta(&pBuffer,&menu,&i,&cont,&xNome);
            			pessoas =(char*)xNome+(sizeof(char)*20);

            			if( *cont == 1){
            				insere(pessoas);
						}
						else{
               				for(*i = 1; *i < *cont ;(*i)++) pessoas = pessoas+1;
                			insere(pessoas);
            			}
            			pessoas =(char*)xNome+(sizeof(char)*20);

					break;
					case 2:
						printf("Digite o nome que vc deseja remover: \n");
						scanf("%s",xNome);
						pessoas = (pessoas,xNome,i,cont);
						//deleta(pessoas,i,cont);
						if(pessoas == NULL) printf("Este contato nao esta na agenda!!!\n"); 
						pessoas =(char*)xNome+(sizeof(char)*20);
						
					break;


					case 3:
						printf("Printando\n");
						pessoas =(char*)xNome+(sizeof(char)*20);

						for(*i = 0;*i < *cont; (*i)++ ){
							printf("===========\nContato[%d]\n",*i);
							printf("Nome = %s\n",pessoas->nome);
							printf("Numero = %d\n",pessoas->teleone);
							printf("===========\n");
							pessoas = pessoas+1;
							//pessoas++;
						}
						pessoas =(char*)xNome+(sizeof(char)*20);
					break;


			}
		printf("\nDigite! \n1 para add contato ,\n2 para retirar contado,\n3 imprimir contatos,\n4 sair do programa! \n");
		scanf("%d",menu);
	}
	free(pBuffer);

	return 0;
}
