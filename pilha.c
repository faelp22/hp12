/* 
 * File:   pilha.c
 * Author: Isael Sousa <faelp22@hotmail.com>
 *
 * Created on 24 de Setembro de 2015, 22:43
 */

#include "pilha.h"
#include <stdio.h>

void inicializa(Pilha *p) {

    for (int i = 0; i < TAMANHO - 1; i++) {
        p->valor[i] = 0;
        p->sinal[i] = 0;
        p->esprecao[i] = 0;
    }// esterilizando variáveis

    p->t1 = -1;
    p->t2 = -1;
    return;
}

void insere_sinal(Pilha *p, char v) {
    if (p->t1 < TAMANHO - 1) {
        p->t1++;
        p->sinal[p->t1] = v;
        return;
    }

    ver_cheia(p);
    return;
}

void insere_valor(Pilha *p, char v) {
    if (p->t2 < TAMANHO - 1) {
        p->t2++;
        p->valor[p->t2] = v;
        return;
    }

    ver_cheia(p);
    return;
}

void retira_sinal(Pilha *p) {
    if (p->t1 <= -1) {
        ver_vazia(p);
        return;
    }

    p->sinal[p->t1] = 0;
    p->t1--;
    return;
}

void ver_cheia(Pilha *p) {
    if (p->t1 == TAMANHO - 1) {
        printf("Pilha cheia so cabe %d elementos \n", TAMANHO);
        return;
    }

    printf("Ainda cabe %d elementos \n", (TAMANHO - 1) - p->t1);
    return;
}

void ver_vazia(Pilha *p) {
    if (p->t1 <= -1) {
        printf("Pilha vazia, cabe %d elementos \n", TAMANHO);
    }
}

void imprime_topo(Pilha *p) {
    printf("Topo %d \n", p->t1);
    return;
}

void hp12(Pilha *p) {
    int i = 0;
    int validador = 0; // usado para verificar se antes do sinal de operacao veio um numero, caso contrario a expreção esta errada
    while (p->esprecao[i] != 0) {
       
        if (p->esprecao[i] != '+' && p->esprecao[i] != '-' && p->esprecao[i] != '*' && p->esprecao[i] != '/' && p->esprecao[i] != '(' && p->esprecao[i] != ')') {
            validador = 1;
            insere_valor(p, p->esprecao[i]);
            if(p->esprecao[i+1] == 0 || i+1 == TAMANHO)
            {
                while(p->t1 > -1)
                {
                    insere_valor(p, p->sinal[p->t1]); //OBS analisar se o mesmo está retornado valor
                    retira_sinal(p);
                }
            }
        }
        else
        {
            if (p->esprecao[i] != '(' && p->esprecao[i] != ')')
            {
                insere_sinal(p, p->esprecao[i]);
            }
            else
            {
                if(p->esprecao[i] != '(')
                {
                    while(p->t1 > -1)
                    {
                        insere_valor(p, p->sinal[p->t1]); //OBS analisar se o mesmo está retornado valor
                        retira_sinal(p);
                    }
                }
            }
        }
        i++;
    }// end for
    printf("%s \n", p->valor);
}


