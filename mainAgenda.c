#include <stdio.h>
#include <stdlib.h>
struct pessoa{
    char nome[20];
    int teleone;
};

void insere(void *pBuffer){
    int *quantAdd;
    int *zero;
    quantAdd = pBuffer;
    zero = quantAdd++;

}

int main(){
	void *pBuffer;
	int *i;
	int *j;
	float *kFloat;



    pBuffer = malloc((sizeof(int))+(sizeof(int))+sizeof(float));
    i =(int*) pBuffer;
    j = (int*)i+1;
    kFloat = (float*) kFloat+1;

    printf("Diga quantas pessoas vc deseja adicionar inicialmente: ");
    scanf("%d",&(*i));
    *j = 0;

    printf("I = %d\n",*i);
    printf("J = %d\n",*j);


	free(pBuffer);

	return 0;
}
