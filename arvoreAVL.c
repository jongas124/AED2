#include <stdio.h>
#include <stdlib.h>
#include "arvoreAVL.h"

//Funções de Árvore

    // Função para calcular o máximo entre dois números
    int max(int a, int b){
        return (a > b) ? a : b;
    }

    // Função para calcular a altura de um nó
    int altura(struct Node *node) {
        if (node == NULL)
            return 0;
        return node->Altura;
}

    // Função para criar um novo nó com as informações inseridas e com a qntDisp sendo a mesma que a qntCopias
    struct Node *newNode(struct Node *raiz, char *nome, char *genero, char *plataforma, int copias, int ano){
        struct Node *node = (struct Node *)malloc(sizeof(struct Node));
        node->nome = nome;
        node->genero = genero;
        node->plataforma = plataforma;
        node->qntCopias = copias;
        node->qntDisp = copias;
        node->left = NULL;
        node->right = NULL;
        node->altura = 1;
    return node;
    } 

    // Função para realizar uma rotação simples à direita
    struct Node *rightRotate(struct Node *y){
        struct Node *x = y->left;
        struct Node *T2 = x->right;

        // Realiza a rotação
        x->right = y;
        y->left = T2;

        // Atualiza as alturas dos nós
        y->altura = max(altura(y->left), altura(y->right)) + 1;
        x->altura = max(altura(x->left), altura(x->right)) + 1;

        return x;
    }

    // Função para realizar uma rotação simples à esquerda
    struct Node *leftRotate(struct Node *x){
        struct Node *y = x->right;
        struct Node *T2 = y->left;

        // Realiza a rotação
        y->left = x;
        x->right = T2;

        // Atualiza as alturas dos nós
        x->altura = max(altura(x->left), altura(x->right)) + 1;
        y->altura = max(altura(y->left), altura(y->right)) + 1;

        return y;
    }

    // Função para obter o fator de balanceamento de um nó
    int getBalance(struct Node *raiz){
        if (raiz == NULL){
            return 0;
        }
        return altura(raiz->left) - altura(raiz->right);
    }

    // Função para inserir um novo nó na árvore AVL
    struct Node *addNode(struct Node *raiz, char *nome, char *genero, char *plataforma, int copias, int ano){
        // Realiza a inserção do nó da mesma forma que em uma árvore binária de busca
        if (raiz == NULL){
            return newNode(raiz, nome, genero, plataforma, copias, ano);
        }
        if (strncmp (raiz->nome, nome, 60) > 0){
            raiz->left = addNode(raiz->left, nome, genero, plataforma, copias, ano);
        }
        else if (strncmp (raiz->nome, nome, 60) < 0){
            raiz->right = addNode(raiz->right, nome, genero, plataforma, copias, ano);
        }
        else // Não permite a inserção de valores duplicados
            return raiz;

        // Atualiza a altura do nó atual
        raiz->altura = 1 + max(altura(raiz->left), altura(raiz->right));

        // Calcula o fator de balanceamento do nó atual
        int balance = getBalance(raiz);

        // Realiza as rotações necessárias para manter a árvore balanceada
            return rotateRight(raiz);

        if (balance < -1 && strncmp (nome, raiz->right->nome, 60) < 0)
            return rotateLeft(raiz);

        if (balance > 1 && strncmp (nome, raiz->left->nome, 60) < 0) {
            raiz->left = rotateLeft(raiz->left);
            return rotateRight(raiz);
        }

        if (balance < -1 && strncmp (nome, raiz->right->nome, 60) > 0) {
            raiz->right = rotateRight(raiz->right);
            return rotateLeft(raiz);
        }
        return raiz;
    } 

    // Função para buscar um jogo específico
    struct Node *busca(struct Node *raiz, char *nome){
        if (raiz != NULL){        
            if (strncmp (raiz->nome, nome, 60) == 0){	
	            return raiz;
	        }
	        if (strncmp (raiz->nome, nome, 60) > 0){
		        busca(raiz->left, nome);
            }	        
	        if (strncmp (raiz->nome, nome, 60) < 0){
                busca(raiz->right, nome);
            }
        }else            
            return NULL;
        
    }

    // Função para encontrar o nó com o valor mínimo em uma árvore
    struct Node *minNode(struct Node *raiz){
        struct Node *atual = raiz;    
        while (atual->left != NULL)
            atual = atual->left;    
        return atual;
    }

    // Função para remover um nó de uma árvore AVL
    struct Node *deleteNode(struct Node *raiz, char *nome, char *plataforma){
        // Realiza a remoção como em uma árvore de busca binária
        if (raiz == NULL)
            return raiz;
        if (strcmp(nome, raiz->nome)>0)
            raiz->left = deleteNode(raiz->left, nome);
        else if (strcmp(nome, raiz->nome)<0)
            raiz->right = deleteNode(raiz->right, nome);
        else {
            // O nó a ser removido foi encontrado
            // Caso 1: O nó não possui filhos ou possui apenas um filho
            if (raiz->left == NULL || raiz->right == NULL) {
                struct Node *temp = raiz->left ? raiz->left : raiz->right;
                // Caso de nenhum filho            
                if (temp == NULL) {
                    temp = raiz;
                    raiz = NULL;
                } else // Caso de um filho
                    *raiz = *temp; // Copia o conteúdo do filho
                free(temp);
            } else {
                // Caso 2: O nó possui dois filhos
                struct Node *temp = minNode(raiz->right);
                // Copia o valor do nó mínimo encontrado para o nó atual
                raiz->nome = temp->nome;
                raiz->genero = temp->genero;
                raiz->plataforma = temp->plataforma;
                raiz->qntCopias = temp->qntCopias;
                raiz->qntDisp = temp->qntDisp;
                raiz->anoLanc = temp->anoLanc;
                // Remove o nó mínimo encontrado na subárvore da direita
                raiz->right = deleteNode(raiz->right, temp->nome);
            }
        }

        // Se a árvore tinha apenas um nó, retorna
        if (raiz == NULL)
            return raiz;

        // Atualiza a altura do nó atual
        raiz->altura = 1 + max(altura(raiz->left), altura(raiz->right));

        // Verifica o fator de balanceamento do nó
        int balance = getBalance(raiz);

        // Casos de rotação para balanceamento
        if (balance > 1 && getBalance(raiz->left) >= 0)
            return rightRotate(raiz);
        if (balance > 1 && getBalance(raiz->left) < 0) {
            raiz->left = leftRotate(raiz->left);
            return rightRotate(raiz);
        }
        if (balance < -1 && getBalance(raiz->right) <= 0)
            return leftRotate(raiz);
        if (balance < -1 && getBalance(raiz->right) > 0) {
            raiz->right = rightRotate(raiz->right);
            return leftRotate(raiz);
        }
        return raiz;
    }



// Funções de Aplicação

    // Função para imprimir dados de um jogo
    void impressaoJogo(struct Node *jogo){

    }

    // Função para imprimir somente nome de jogos por gênero
    void impressaoGenero(struct Node *raiz, char *genero){

    }

    // Função para imprimir somente nome de jogos por plataforma
    void impressaoPlataforma(struct Node *raiz, char *plataforma){

    }

    // Função para imprimir somente nome de jogos por ano
    void impressaoAno(struct Node *raiz, int ano){

    }

    // Função para alugar um jogo
    void alugarJogo(struct Node *jogo){

    }

    // Função para devolver um jogo
    void devolverJogo(struct Node *jogo){

    }
