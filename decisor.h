#ifndef _DECISOR_H_
#define _DECISOR_H_
typedef struct node {
	int categoria;
	int atributoOuDecisao;
	struct node *prox;
	struct node *lista;
} No;

/*Cria uma árvore com um único nó que corresponde a uma decisão, inicializa os campos com zero ou NULL, conforme o tipo do campo. Retorna o ponteiro para esse nó.*/
No *criaArvore(void);

/*Cria um nó filho do nó pai, ajusta o atributo do pai, categoria e decisao do filho. Retorna o ponteiro para o filho.*/
No *criaFilho (No *pai, int atributoDoPai, int categoriaDoFilho, int decisao);

/*Busca, entre os filhos de n aquele com atributo e categoria dados como parâmetro. Retorna os ponteiros para o filho e seu antecessor (se houver, como \textbf{conteúdo} do parâmetro). Caso não haja antecessor atribui NULL ao \textbf{conteúdo} do parâmetro.  Caso não encontre filho, não há antecessor e retorna NULL. */
No *buscaFilho (No *n, int atributo, int categoria, No **antecessor);

/*Recebe uma árvore de decisão e um vetor de atributos e retorna a decisão computada pela árvore.*/
int decide (No *arvore, int *atributos);

#endif