#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvoreAVL.h"

//Funções de Árvore

    // Função para calcular o máximo entre dois números
    int max(int a, int b){
        return (a > b) ? a : b;
    }

    // Função para calcular a Altura de um nó
    int Altura(struct Node *node) {
        if (node == NULL)
            return 0;
        return node->Altura;
}

    // Função para criar um novo nó com as informações inseridas e com a qntDisp sendo a mesma que a qntCopias
    struct Node *newNode(struct Node *raiz, char *nome, char *genero, char *plataforma, int ano){
        struct Node *node = (struct Node *)malloc(sizeof(struct Node));
        strcpy(node->nome, nome);
        strcpy(node->genero, genero);
        strcpy(node->plataforma, plataforma);
        node->qntCopias = 1;
        node->qntDisp = 1;
        node->Left = NULL;
        node->Right = NULL;
        node->Altura = 1;
    return node;
    } 

    // Função para realizar uma rotação simples à direita
    struct Node *RightRotate(struct Node *y){
        struct Node *x = y->Left;
        struct Node *T2 = x->Right;

        // Realiza a rotação
        x->Right = y;
        y->Left = T2;

        // Atualiza as Alturas dos nós
        y->Altura = max(Altura(y->Left), Altura(y->Right)) + 1;
        x->Altura = max(Altura(x->Left), Altura(x->Right)) + 1;

        return x;
    }

    // Função para realizar uma rotação simples à esquerda
    struct Node *LeftRotate(struct Node *x){
        struct Node *y = x->Right;
        struct Node *T2 = y->Left;

        // Realiza a rotação
        y->Left = x;
        x->Right = T2;

        // Atualiza as Alturas dos nós
        x->Altura = max(Altura(x->Left), Altura(x->Right)) + 1;
        y->Altura = max(Altura(y->Left), Altura(y->Right)) + 1;

        return y;
    }

    // Função para obter o fator de balanceamento de um nó
    int getBalance(struct Node *raiz){
        if (raiz == NULL){
            return 0;
        }
        return Altura(raiz->Left) - Altura(raiz->Right);
    }

    // Função para inserir um novo nó na árvore AVL
    struct Node *addNode(struct Node *raiz, char *nome, char *genero, char *plataforma, int ano){
        // Realiza a inserção do nó da mesma forma que em uma árvore binária de busca
        if (raiz == NULL){
            return newNode(raiz, nome, genero, plataforma, ano);
        }
        if (strncmp (raiz->nome, nome, 60) > 0){
            raiz->Left = addNode(raiz->Left, nome, genero, plataforma, ano);
        }
        else if (strncmp (raiz->nome, nome, 60) < 0){
            raiz->Right = addNode(raiz->Right, nome, genero, plataforma, ano);
        }
        else {// Adciona cópia em título já existente
            raiz->qntCopias++;
            raiz->qntDisp++;
            return raiz;
        }
        
        // Atualiza a Altura do nó atual
        raiz->Altura = 1 + max(Altura(raiz->Left), Altura(raiz->Right));

        // Calcula o fator de balanceamento do nó atual
        int balance = getBalance(raiz);

        // Realiza as rotações necessárias para manter a árvore balanceada
        if (balance > 1 && strncmp (nome, raiz->Right->nome, 60) > 0)
            return RightRotate(raiz);

        if (balance < -1 && strncmp (nome, raiz->Right->nome, 60) < 0)
            return LeftRotate(raiz);

        if (balance > 1 && strncmp (nome, raiz->Left->nome, 60) < 0) {
            raiz->Left = LeftRotate(raiz->Left);
            return RightRotate(raiz);
        }

        if (balance < -1 && strncmp (nome, raiz->Right->nome, 60) > 0) {
            raiz->Right = RightRotate(raiz->Right);
            return LeftRotate(raiz);
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
		        busca(raiz->Left, nome);
            }	        
	        if (strncmp (raiz->nome, nome, 60) < 0){
                busca(raiz->Right, nome);
            }
        }else            
            return NULL;
        
    }

    // Função para encontrar o nó com o valor mínimo em uma árvore
    struct Node *minNode(struct Node *raiz){
        struct Node *atual = raiz;    
        while (atual->Left != NULL)
            atual = atual->Left;    
        return atual;
    }

    // Função para remover um nó de uma árvore AVL
    struct Node *deleteNode(struct Node *raiz, char *nome){
        // Realiza a remoção como em uma árvore de busca binária
        if (raiz == NULL)
            return raiz;
        if (strcmp(nome, raiz->nome)>0)
            raiz->Left = deleteNode(raiz->Left, nome);
        else if (strcmp(nome, raiz->nome)<0)
            raiz->Right = deleteNode(raiz->Right, nome);
        else {
            // O nó a ser removido foi encontrado
            // Caso 1: O nó não possui filhos ou possui apenas um filho
            if (raiz->Left == NULL || raiz->Right == NULL) {
                struct Node *temp = raiz->Left ? raiz->Left : raiz->Right;
                // Caso de nenhum filho            
                if (temp == NULL) {
                    temp = raiz;
                    raiz = NULL;
                } else // Caso de um filho
                    *raiz = *temp; // Copia o conteúdo do filho
                free(temp);
            } else {
                // Caso 2: O nó possui dois filhos
                struct Node *temp = minNode(raiz->Right);
                // Copia o valor do nó mínimo encontrado para o nó atual
                strcpy(raiz->nome, temp->nome);
                strcpy(raiz->genero, temp->genero);
                strcpy(raiz->plataforma, temp->plataforma);
                raiz->qntCopias = temp->qntCopias;
                raiz->qntDisp = temp->qntDisp;
                raiz->anoLanc = temp->anoLanc;
                // Remove o nó mínimo encontrado na subárvore da direita
                raiz->Right = deleteNode(raiz->Right, temp->nome);
            }
        }

        // Se a árvore tinha apenas um nó, retorna
        if (raiz == NULL)
            return raiz;

        // Atualiza a Altura do nó atual
        raiz->Altura = 1 + max(Altura(raiz->Left), Altura(raiz->Right));

        // Verifica o fator de balanceamento do nó
        int balance = getBalance(raiz);

        // Casos de rotação para balanceamento
        if (balance > 1 && getBalance(raiz->Left) >= 0)
            return RightRotate(raiz);
        if (balance > 1 && getBalance(raiz->Left) < 0) {
            raiz->Left = LeftRotate(raiz->Left);
            return RightRotate(raiz);
        }
        if (balance < -1 && getBalance(raiz->Right) <= 0)
            return LeftRotate(raiz);
        if (balance < -1 && getBalance(raiz->Right) > 0) {
            raiz->Right = RightRotate(raiz->Right);
            return LeftRotate(raiz);
        }
        return raiz;
    }



// Funções de Aplicação

    // Função para imprimir dados de um jogo
    void impressaoJogo(struct Node *jogo){
        if(jogo!=NULL){
            printf("\t\tDADOS DO JOGO \n");
            printf("Nome: %s\n", jogo->nome);
            printf("Genero: %s\n",jogo->genero);
            printf("Plataforma: %s\n", jogo->plataforma);
            printf("Copias Disponiveis: %d\n", jogo->qntDisp);
            printf("Copias Totais: %d\n", jogo->qntCopias);
            printf("Ano de Lancamento: %d\n\n",jogo->anoLanc);
        }
        else
            printf("Jogo nao encontrado\n");
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
        if(jogo!=NULL){
            if(jogo->qntDisp == 0){
                printf("Nao é possivel alugar pois nao há nenhuma copia do jogo disponivel\n");
            }
            else
                jogo->qntDisp--;
        }
        if(jogo==NULL){
            printf("Jogo nao encontrado\n");
        }
    }

    // Função para devolver um jogo
    void devolverJogo(struct Node *jogo){
        if(jogo!=NULL){
            if(jogo->qntDisp == jogo->qntCopias){
                printf("Nao é possivel devolver pois todos as copias deste jogo estao presentes em estoque\n");
            }
            else
                jogo->qntDisp++;
        }
        if(jogo==NULL){
            printf("Jogo nao encontrado\n");
        }
    }
