/* 
 * File:   main.cpp
 * Author: Isael Sousa <faelp22@gmail.com>
 *
 * Created on 24 de Setembro de 2015, 22:41
 */

#include "pilha.h"
#include <stdio.h>

int main(int argc, char** argv) {

    printf("Conversor de Notação Polonesa Inversa v-1.0\n");
    Pilha p1;
    inicializa(&p1);
    printf("Digite sua expressao, ex: a+b ou (a+b)/c ou ((a*b)-(c*d))/(e*f) \ncom limite de ate %d caracteres\n", TAMANHO);
    printf("Digite: ");
    scanf("%s", p1.expressao);
    hp12(&p1);
    return 0;
}
