#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "arvoreAVL.h"

int opCode;
char nome[60];
char genero[20];
char plataforma[20];
int ano;
int cont;

int main(){



    struct Node *Raiz;
    Raiz = malloc(sizeof(struct Node));
    Raiz = NULL;
    scanf("%d", &opCode);
    while(opCode != 0){
        
        switch (opCode){//Lendo operação a ser realizada
        case 1: // Adicionar Título
            {   
            getchar();
            scanf("%[^\n]%*c", nome);
            scanf("%[^\n]%*c", genero);
            scanf("%[^\n]%*c", plataforma);
            scanf("%d", &ano);
            if(Raiz==NULL){
                Raiz = malloc(sizeof(struct Node));
                strcpy(Raiz->nome, nome);
                strcpy(Raiz->genero, genero);
                strcpy(Raiz->plataforma, plataforma);
                Raiz->qntCopias = 1;
                Raiz->qntDisp = 1;
                Raiz->anoLanc = ano;
                Raiz->Left = NULL;
                Raiz->Right = NULL;
                Raiz->Altura = 1;
            }else{
                addNode(Raiz, nome, genero, plataforma, ano);
            }
            break;
            }
        case 2:{ // Buscar Título
            getchar();
            scanf("%[^\n]%*c", nome);            
            struct Node *tmp;
            tmp = busca(Raiz, nome);
            impressaoJogo(tmp);
            break;
            }
        case 3:{ // Imprimir todos os jogos de um gênero
            getchar();
            scanf("%[^\n]%*c", genero);
            impressaoGenero(Raiz, genero);
            break;
            }

        case 4:{ // Imprimir todos os jogos de uma plataforma
            getchar();
            scanf("%[^\n]%*c", plataforma);
            impressaoPlataforma(Raiz, plataforma);
            break;
            }

        case 5:{ // Imprimir todos os jogos de um ano
            getchar();
            scanf("%d", &ano);
            impressaoAno(Raiz, ano);
            break;
            }

        case 6:{ // Alugar um jogo
            getchar();
            scanf("%[^\n]%*c", nome);            
            struct Node *tmp;
            tmp = busca(Raiz, nome);
            alugarJogo(tmp);
            break;
            }

        case 7:{ // Devolver um jogo
            getchar();
            scanf("%[^\n]%*c", nome);            
            struct Node *tmp;
            tmp = busca(Raiz, nome);
            devolverJogo(tmp);
            break;
            }
        
        /*DELETAR JOGO AINDA ESTÁ DANDO ERRO NA ÁRVORE
        case 8:{ //Deletar um jogo
            getchar();
            scanf("%[^\n]%*c", nome);
            deleteNode(Raiz, nome);
            break;
        }*/

        case 0:{
            printf("\n\nFinalizando Execução");
            break;
            }
        default:{
            printf("\nOperação Inválida\n");
        }
        }
    scanf("%d", &opCode);
    } 
    return 0;
}