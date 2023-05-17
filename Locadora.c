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



    struct Node *Raiz = (struct Node *)malloc(sizeof(struct Node));
    Raiz = NULL;
    scanf("%d", &opCode);
    switch (opCode){//Lendo operação a ser realizada
        case 1: // Adicionar Título
            {            
            while(scanf("%c", &nome[cont]) != '#'){
                cont++;
            }
            cont = 0;
            while(scanf("%c", &genero[cont]) != '#'){
                cont++;
            }
            cont = 0;
            while(scanf("%c", &plataforma[cont]) != '#'){
                cont++;
            }            
            scanf("%d", &ano);            
            addNode(Raiz, nome, genero, plataforma, ano);
            break;
            }
        case 2:{ // Buscar Título
            scanf("%s", nome);            
            struct Node *tmp;
            tmp = busca(Raiz, nome);
            impressaoJogo(tmp);
            free(tmp);
            break;
            }
        case 3:{ // Imprimir todos os jogos de um gênero
            scanf("%s", nome);
            impressaoGenero(Raiz, genero);
            break;
            }

        case 4:{ // Imprimir todos os jogos de uma plataforma
            scanf("%s", nome);
            impressaoPlataforma(Raiz, plataforma);
            break;
            }

        case 5:{ // Imprimir todos os jogos de um ano
            scanf("%d", &ano);
            impressaoAno(Raiz, ano);
            break;
            }

        case 6:{ // Alugar um jogo
            scanf("%s", nome);            
            struct Node *tmp;
            tmp = busca(Raiz, nome);
            alugarJogo(tmp);
            free(tmp);
            break;
            }

        case 7:{ // Devolver um jogo
            scanf("%s", nome);            
            struct Node *tmp;
            tmp = busca(Raiz, nome);
            devolverJogo(tmp);
            free(tmp);
            break;
            }

        case 0:{
            printf("\n\nFinalizando Execução");
            break;
            }

    }


    return 0;
}