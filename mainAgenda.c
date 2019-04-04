#include <stdio.h>
#include <stdlib.h>
struct pessoa{
    char nome[20];
    int teleone;
};
void aponta(void** pBuffer,int** menu,int** i,int** cont){
    *menu = *pBuffer;
    *i = *menu+1;
    *cont = *i+1;

}
//insere(pBuffer,i,cont);
void insere(struct pessoa* pessoas){

        printf("Digite os dados a seguir!\n");
        printf("Nome : ");
        scanf("%s",&(*pessoas->nome));
        printf("Telefone: ");
        scanf("%d",&pessoas->teleone);

}


int main(){
    void* pBuffer;
    int* menu;
    int* i;
    int* cont;
    struct pessoa* pessoas;

    pBuffer = malloc(3*sizeof(int));
    aponta(&pBuffer,&menu,&i,&cont);
    
    *cont = 0;

    printf("Digite! \n1 para add contato ,\n2 para retirar contado,\n3 imprimir contatos,\n4 sair do programa! \n");
    scanf("%d",menu);
	while((*menu) != 4){
			switch(*menu){
					case 1:
						
                        (*cont)++;
						pBuffer = realloc(pBuffer,((3*sizeof(int))+(*cont)*sizeof(struct pessoa)));

                        aponta(&pBuffer,&menu,&i,&cont);
                        pessoas = (struct pessoa*)cont+1;
                        
                        if( *cont == 1){
                        	insere(pessoas);
						}
						else{
						
							for(*i = 0 ; *i < *cont ; (*i)++ ){
								pessoas = pessoas+1;
							}
							insere(pessoas);
                    	}
                        pessoas = (struct pessoa*)cont+1;

					break;
					case 2:


					break;


					case 3:
						printf("Printando\n");
						//pessoas = primeiraPessoa;

						for(*i = 0;*i < *cont; (*i)++ ){
							printf("===========\nContato[%d]\n",*i);
							printf("Nome = %s\n",pessoas->nome);
							printf("Numero = %d\n",pessoas->teleone);
							printf("===========\n");
							pessoas = pessoas+1;
							//pessoas++;
						}
						pessoas =(struct pessoa*)cont+1;
					break;


			}
		printf("Digite! \n1 para add contato ,\n2 para retirar contado,\n3 imprimir contatos,\n4 sair do programa! \n");
		scanf("%d",menu);




	}



	free(pBuffer);

	return 0;
}

