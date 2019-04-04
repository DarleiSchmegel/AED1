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
        getchar();
        scanf("%s",pessoas->nome);
        getchar();
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

    printf("\nDigite! \n1 para add contato ,\n2 para retirar contado,\n3 imprimir contatos,\n4 sair do programa! \n\n");
    scanf("%d",menu);
	while((*menu) != 4){
			switch(*menu){
					case 1:

            *cont = *cont+1;
						//pBuffer = realloc(pBuffer,((3*sizeof(int))+(*cont)*sizeof(struct pessoa)));
            pBuffer = realloc(pBuffer,(sizeof(int)*3+sizeof(struct pessoa)*(*cont)));

            aponta(&pBuffer,&menu,&i,&cont);
            pessoas = (int*)cont+1;

            if( *cont == 1){
            insere(pessoas);
						}
						else{
                for(*i = 1; *i < *cont ;(*i)++) pessoas = pessoas+1;
                insere(pessoas);
            }
            pessoas = (int*)cont+1;

					break;
					case 2:



					break;


					case 3:
						printf("Printando\n");
						pessoas = (int*)cont+1;

						for(*i = 0;*i < *cont; (*i)++ ){
							printf("===========\nContato[%d]\n",*i);
							printf("Nome = %s\n",pessoas->nome);
							printf("Numero = %d\n",pessoas->teleone);
							printf("===========\n");
							pessoas = pessoas+1;
							//pessoas++;
						}
						pessoas = (int*)cont+1;
					break;


			}
		printf("\nDigite! \n1 para add contato ,\n2 para retirar contado,\n3 imprimir contatos,\n4 sair do programa! \n");
		scanf("%d",menu);




	}



	free(pBuffer);

	return 0;
}

