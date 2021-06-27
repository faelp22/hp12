/* 
 * File:   pilha.h
 * Author: Isael Sousa <faelp22@gmail.com>
 *
 * Created on 24 de Setembro de 2015, 22:43
 */

#ifndef PILHA_H
#define	PILHA_H

#define TAMANHO 50

struct pilha {
	char sinal[TAMANHO];
	char valor[TAMANHO];
	char expressao[TAMANHO];
	int t1; // topo para sinal
	int t2; // topo para valor
};

typedef struct pilha Pilha;

void inicializa(Pilha *p);

void insere_sinal(Pilha *p, char v);

void insere_valor(Pilha *p, char v);

void retira_sinal(Pilha *p);

void ver_cheia(Pilha *p);

void ver_vazia(Pilha *p);

void imprime_topo(Pilha *p);

void hp12(Pilha *p);

#endif
