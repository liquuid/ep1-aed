#include <stdio.h>
#include <stdlib.h>
#include "decisor.h"

int atributoAnterior = -1;

/*
 * Cria uma arvore com um unico no que corresponde a uma decisao, inicializa os campos com zero ou NULL,
 * conforme o tipo do campo. Retorna o ponteiro para esse no.
*/

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
    paiAux = (No *) malloc(sizeof(No *));
    paiAux = pai;

    /* reserva espaco na memória */
    filho = (No *) malloc(sizeof(No *));
    filho->atributoOuDecisao = atributoOuDecisao;
    filho->categoria = categoriaDoFilho;
    filho->lista = NULL;
    filho->prox = NULL;

    /* corre a lista */
    while (paiAux->lista) {
        paiAux = paiAux->lista;
    }

    printf("criaFilho %p ( %d, %d, %d) \n", filho, atributoDoPai, categoriaDoFilho, atributoOuDecisao);

    if (atributoAnterior == atributoDoPai) {
        while (paiAux->prox) {
            paiAux = paiAux->prox;
        }
        paiAux->prox = filho;
    } else {

        if (pai->lista && pai->lista != filho) {
            pai->lista->prox = filho;
        } else {
            paiAux->lista = filho;
        }
    }
    atributoAnterior = atributoDoPai;
    return filho;
}

/*
 * Busca, entre os filhos de n aquele com atributo e categoria dados como parâmetro. Retorna os ponteiros para o filho e
 * seu antecessor (se houver, como \textbf{conteúdo} do parâmetro). Caso não haja antecessor atribui NULL ao conteúdo do
 * parâmetro.  Caso não encontre filho, não há antecessor e retorna NULL.
 *
*/

No *buscaFilho(No *n, int atributo, int categoria, No **antecessor) {
    No *nAux;
    nAux = (No *) malloc(sizeof(No *));
    nAux = n;

    if (nAux->lista) {

        while (nAux->lista) {
            /* corre a lista, caso o atributo e a categoria sejam a procurada retorna o nó */
            if (nAux->lista->atributoOuDecisao == atributo && nAux->lista->categoria == categoria) {
                *antecessor = nAux;
                return nAux->lista;
            }
            nAux = nAux->lista;
        }

    }
    if (nAux->prox) {

        while (nAux->prox) {
            /* corre os próximos, caso o atributo e a categoria sejam a procurada retorna o nó */
            if (nAux->prox->atributoOuDecisao == atributo && nAux->prox->categoria == categoria) {
                *antecessor = nAux;
                return nAux->prox;
            }
            nAux = nAux->prox;
        }

    }
    return NULL;
}

/*
 * Recebe uma árvore de decisão e um vetor de atributos e retorna a decisão computada pela árvore.
 *
 */
int decide(No *arvore, int *atributos) {
    int decisao = -1;
    No *noAux;
    noAux = (No *) malloc(sizeof(No *));
    int i = 1;
    noAux = arvore->lista;

    while (noAux->lista || noAux->prox) {
        if (noAux->categoria == atributos[i]) {
            if (noAux->lista) {
                i = noAux->atributoOuDecisao;
                noAux = noAux->lista;
            } else {
                return noAux->atributoOuDecisao;
            }
        } else {
            if (noAux->prox) {
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