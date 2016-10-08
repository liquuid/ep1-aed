#include <stdio.h>
#include <stdlib.h>
#include "decisor.h"

No *arv;

void main(void) {

    No *aux, *aux2;
    No *arv2;
    No **antecessor;
    antecessor = (No **) malloc(sizeof(No **));
    int *v;
    /* Cria árvore do exemplo */
    arv = criaArvore();
    arv2 = arv;
    aux = criaFilho(arv, 1, 1, 3);
    criaFilho(aux, 3, 0, 1);
    criaFilho(aux, 3, 1, 0);
    criaFilho(aux, 3, 2, 1);
    criaFilho(aux, 3, 3, 0);
    criaFilho(aux, 3, 4, 1);

    aux = criaFilho(arv, 1, 0, 5);
    criaFilho(aux, 5, 0, 3);

    aux2 = criaFilho(aux, 5, 1, 4);
    criaFilho(aux, 5, 2, 0);
    criaFilho(aux, 5, 3, 0);

    criaFilho(aux2, 4, 0, 2);
    criaFilho(aux2, 4, 1, 0);
    criaFilho(aux2, 4, 2, 2);
    criaFilho(aux2, 4, 3, 0);

    printf("arv: %p \n", arv);
    printf("buscaFilho: %p \n", buscaFilho(arv,1,0, antecessor ));
    printf("buscaFilho: %p \n", buscaFilho(aux,2,0, antecessor ));
    printf("buscaFilho: %p \n", buscaFilho(aux2,2,2, antecessor ));

    printf("*antecessor: %p \n", *antecessor );

    /* Cria um vetor de atributos */
    v = (int *) malloc(8 * sizeof(int));
    /*ID, sexo, relacionamento, renda, região, celular, transporte, restaurante*/
    v[0] = 1234;
    v[1] = 0;
    v[2] = 1;
    v[3] = 2;
    v[4] = 1;
    v[5] = 1;
    v[6] = 1;
    v[7] = 2;
    printf("decisão: %d\n", decide(arv, v));

    /* -------------- */

    printf("arv = %p \n", arv);

}