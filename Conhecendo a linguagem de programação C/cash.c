#include <stdio.h>
#include <cs50.h>
#include <math.h>

float change(void);

int main(void){

    //transforma reais em centavos
    float reais = change();
    int centavos = round(reais * 100);

    //variável de controle das moedas
    int v = 0;

    while(centavos >= 25){
        centavos = (centavos-25);

        v = v+1;
    };

    while(centavos >= 10){
        centavos = centavos - 10;

        v = v+1;
    };

    while(centavos >= 5){
        centavos = centavos - 5;

        v = v+1;
    };

    while(centavos > 0){
        centavos = centavos -1;

        v = v +1;
    }

    printf("%i\n", v);

}

//obtém o valor do troco
float change(void){

    float c;

    do{
        c = get_float("Informe o troco:");
    }
    while( c < 0);

    return c;
}