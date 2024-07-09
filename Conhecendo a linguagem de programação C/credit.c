#include <stdio.h>
#include <cs50.h>
#include <math.h>

long card(void);

int firstSoma(long cardNumber, int lenght);

int lenghtCard(long cardNumber);

int main(void){

    long creditCard = card();
    int digitos = lenghtCard(creditCard);
    int bandeira = (creditCard / pow(10, (digitos - 2)));
    int soma1 = firstSoma(creditCard, digitos);
    int soma2 = 0;

//Realiza a segunda parte do Algoritmo de Luhn (Adicione essa soma à soma dos dígitos que não foram multiplicados por 2)
    for(int i = 0; i < digitos; i++){

        soma2 = soma2 + (creditCard % 10);

        creditCard = creditCard /100;
    };

    soma2 = soma2 + soma1;

//Confere se o cartão é válido e qual a bandeira
    if((soma2 % 10) != 0){
        printf("INVALID\n");
    }
    else{
        if(bandeira == 34 || bandeira == 37){
            printf("AMEX\n");
        }
        else if(bandeira >= 51 && bandeira <= 55){
            printf("MASTERCARD\n");
        }
        else if((bandeira/10) == 4){
            printf("VISA\n");
        }
        else{
            printf("INVALID\n");
        }
    }
    };

// Obtém o número do cartão do usuário
long card(void){
    long c;

    do{
        c = get_long("Digite o número do cartão:");
    }
    while(c <= 0);

    return c;
};

//Realiza a primera parte do Algoritmo de Luhn (Multiplique cada segundo digito por 2, começando com o penúltimo dígito do número e, em seguida, some os dígitos desses produtos.)
int firstSoma(long cardNumber, int lenght){
     int soma1 = 0;

    cardNumber = cardNumber /10;

    for(int i = 0; i < lenght; i++){

        int controle = (cardNumber  % 10) * 2;
        int c1 = 0;
        int c2 = 0;

        if(controle < 10){
            soma1 = soma1 + controle;
        }
        else{
            c1 = controle % 10;
            c2 = controle / 10;
            soma1 = soma1 + c1 +c2;
        }

        cardNumber = cardNumber / 100;
        };

        return soma1;
};

//Calcula o total de dígitos no número do cartão - para uso na estrutura for de soma;
int lenghtCard(long cardNumber){
    int lenght = 0;

    while(cardNumber > 0){
        cardNumber = cardNumber/10;
        lenght = lenght + 1;
    }

    return lenght;
}
