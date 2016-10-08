#include <stdio.h>
#include <stdlib.h>
#include "decisor.h"

/*
 * Cria uma arvore com um unico no que corresponde a uma decisao, inicializa os campos com zero ou NULL,
 * conforme o tipo do campo. Retorna o ponteiro para esse no.
*/

int atributoAnterior = -1;

No *criaArvore(void) {

    printf("criaArvore\n");
    /* cria ponteiro que será usada para apontar para a memória onde a árvore será criada */
    No *arv;
    /* reserva espaco na memória */
    arv = (No *) malloc(sizeof(No *));
    arv->atributoOuDecisao = 1;
    arv->categoria = 0;
    arv->lista = NULL;
    arv->prox = NULL;
    return arv;
}

/*
 * Cria um nó filho do nó pai, ajusta o atributo do pai, categoria e decisao do filho. Retorna o ponteiro para
 * o filho.
 */
No *criaFilho(No *pai, int atributoDoPai, int categoriaDoFilho, int atributoOuDecisao) {


    No *filho;
    No *paiAux;
    No **antecessor;
    antecessor = (No **) malloc(sizeof(No **));
    paiAux = (No *) malloc(sizeof(No *));
    paiAux = pai;
    /* reserva espaco na memória */
    filho = (No *) malloc(sizeof(No *));
    filho->atributoOuDecisao = atributoOuDecisao;
    filho->categoria = categoriaDoFilho;
    filho->lista = NULL;
    filho->prox = NULL;



    while (paiAux->lista) {

        paiAux = paiAux->lista;
    }


    printf("criaFilho %p ( %d, %d, %d) \n", filho, atributoDoPai, categoriaDoFilho, atributoOuDecisao);

    if (atributoAnterior == atributoDoPai){
        while (paiAux->prox){
            paiAux = paiAux->prox;
        }
        paiAux->prox = filho;
    } else {

        if (pai->lista && pai->lista != filho ){
            pai->lista->prox = filho;
        } else {
            paiAux->lista = filho;
        }
    }
    atributoAnterior = atributoDoPai;
    return filho;
}

No *buscaFilho(No *n, int atributo, int categoria, No **antecessor) {
    No *nAux;
    nAux = (No *) malloc(sizeof(No *));
    nAux = n;

    if (nAux->lista) {

        while (nAux->lista) {

            if (nAux->lista->atributoOuDecisao == atributo && nAux->lista->categoria == categoria) {
                *antecessor = nAux;
                return nAux->lista;
            }
            nAux = nAux->lista;
        }

    }
    if (nAux->prox) {

        while (nAux->prox) {

            if (nAux->prox->atributoOuDecisao == atributo && nAux->prox->categoria == categoria) {
                *antecessor = nAux;
                return nAux->prox;
            }
            nAux = nAux->prox;
        }

    }


    return NULL;
}

int decide(No *arvore, int *atributos) {
    int decisao = -1 ;
    No *noAux;
    noAux = (No *) malloc(sizeof(No *));
    int i = 1;
    noAux = arvore->lista;

    while (noAux->lista || noAux->prox){
        if(noAux->categoria == atributos[i]){
            if (noAux->lista){
                i = noAux->atributoOuDecisao;
                noAux = noAux->lista;
            } else {
                return noAux->atributoOuDecisao;
            }
        } else {
            if(noAux->prox) {
                noAux = noAux->prox;
                continue;
            } else {
                return noAux->atributoOuDecisao;
            }
        }
    }

    printf("decide\n");
    return decisao;
}