#include <stdio.h>
#include <cs50.h>

int altura(void);

int main (void)
{
    int j = altura();
    int l = 1;

    do
    {   //adequa o alinhamento
        for(int a = l; a < j; a++){
            printf(".");
        };

        //imprime os blocos
        for(int h = 0; h < l; h++){
            printf("#");
        };

        printf("\n");

        l = l+1;
    }while (l <= j);
};

//obtém a altura da pirâmide
int altura(void){

    int n;

    do{
        n = get_int("Informe a altura da pirâmide: ");
    }
    while (n < 1 != n > 8);
    return n;
}
