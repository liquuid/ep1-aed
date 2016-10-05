#include <stdio.h>
#include <stdlib.h>
#include "decisor.h"

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
    arv->atributoOuDecisao = 0;
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
    printf("criaFilho\n");

    No *filho;
    /* reserva espaco na memória */
    filho = (No *) malloc(sizeof(No *));
    filho->atributoOuDecisao = atributoOuDecisao;
    filho->categoria = categoriaDoFilho;
    filho->lista = NULL;
    filho->prox = NULL;
    return filho;
}

No *buscaFilho(No *n, int atributo, int categoria, No **antecessor) {
    printf("buscaFilho\n");
    return NULL;
}

int decide(No *arvore, int *atributos) {
    printf("decide\n");
    return 0;
}

int teste(){
    return 0;
}