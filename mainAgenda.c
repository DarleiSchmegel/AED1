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
void insere(void* pBuffer,struct pessoa* pessoas){


        printf("Digite os dados a seguir!\n");
        printf("Nome : ");
        scanf("%s",&(*pessoas->nome));
        pessoas = pessoas+1;



}


int main(){
    void* pBuffer;
    int* menu;
    int* i;
    int* cont;
    struct pessoa* pessoas;

    pBuffer = malloc(3*sizeof(int)+sizeof(struct pessoa));
    aponta(&pBuffer,&menu,&i,&cont);
    pessoas = cont+1;
    *cont = 1;

    printf("Digite! \n1 para add contato ,\n2 para retirar contado,\n3 imprimir contatos,\n4 sair do programa! \n");
    scanf("%d",menu);
	while((*menu) != 4){
			switch(*menu){
					case 1:

						pBuffer = realloc(pBuffer,((3*sizeof(int))+(*cont)*sizeof(struct pessoa)));

                        aponta(&pBuffer,&menu,&i,&cont);
                        pessoas = cont+1;


                        insere(pBuffer,pessoas);
                        (*cont)++;

					break;
					case 2:


					break;


					case 3:
						printf("Printando\n");
						//pessoas = primeiraPessoa;

						/*for(*i = 1;*i <= *quantPessoas; (*i)++ ){
							printf("Pessoa numero[%d] = %s\n",*i,primeiraPessoa->nome);
							primeiraPessoa++;
							//pessoas++;
						}*/
						//pessoas = primeiraPessoa;
					break;


			}
		printf("Digite! \n1 para add contato ,\n2 para retirar contado,\n3 imprimir contatos,\n4 sair do programa! \n");
		scanf("%d",menu);




	}



	free(pBuffer);

	return 0;
}