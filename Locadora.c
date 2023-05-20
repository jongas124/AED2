#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "arvoreAVL.h"

int opCode, opCode2;
char nome[60];
char genero[20];
char plataforma[20];
int ano;
int cont=1;
FILE *entrada;
int main(){



entrada = fopen("./Entrada.txt", "r");

if (entrada == NULL)
{    
    printf("Erro na abertura de arquivo: %s\n", strerror(errno));
    return 0;    
}

    struct Node *Raiz;
    Raiz = malloc(sizeof(struct Node));
    Raiz = NULL;
    fscanf(entrada, "%d", &opCode);
    while(opCode!=0){
        
        switch (opCode){//Lendo operação a ser realizada
        case 1: // Adicionar Título
            {   
            fscanf(entrada, "%c");
            fscanf(entrada,"%[^\n]%*c", nome);
            fscanf(entrada,"%[^\n]%*c", genero);
            fscanf(entrada,"%[^\n]%*c", plataforma);
            fscanf(entrada,"%d", &ano);
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
                Raiz = addNode(Raiz, nome, genero, plataforma, ano);
            }
            printf("%d Jogo Adicionado\n", cont);
            cont++;
            break;
            }
        case 2:{ // Buscar Título
            getchar();
            scanf("%[^\n]%*c", nome);            
            struct Node *tmp;
            tmp = NULL;
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
        
        case 8:{ //Deletar um jogo
            getchar();
            scanf("%[^\n]%*c", nome);
            Raiz = deleteNode(Raiz, nome);
            break;
        }

        case 9:{ //Imprimir toda a arvore
            impressaoTodos(Raiz);
            break;
        }

        case 0:{
            printf("\n\nFinalizando Execução");
            break;
            }

        default:{
            printf("\nOperação Inválida\n");
        }
        
        }
        if(opCode==0){
            break;
        }
        fscanf(entrada, "%d", &opCode);
    } 

printf("\n\n\tMenu\n");
printf("1: Incluir Jogo\n");
printf("2: Buscar Jogo\n");
printf("3: Buscar por Genero\n");
printf("4: Buscar por Plataforma\n");
printf("5: Buscar por Ano\n");
printf("6: Alugar Jogo\n");
printf("7: Devolver Jogo\n");
printf("8: Remover Jogo\n");
printf("9: Mostrar Todos os Jogos\n");
printf("0: Finalizar Aplicacao\n");
    scanf("%d", &opCode2);

    
    while(opCode2!=0){
        
        switch (opCode2){//Lendo operação a ser realizada
        case 1: // Adicionar Título
            {   
            getchar();
            printf("(Nome do jogo) (Cod. Plataforma)\n");
            scanf("%[^\n]%*c", nome);
            printf("(Genero)\n");
            scanf("%[^\n]%*c", genero);
            printf("(Plataforma)\n");
            scanf("%[^\n]%*c", plataforma);
            printf("(Ano)\n");
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
                Raiz = addNode(Raiz, nome, genero, plataforma, ano);
            }
            printf("%d Jogo Adicionado\n", cont);
            cont++;
            break;
            }
        case 2:{ // Buscar Título
            getchar();
            scanf("%[^\n]%*c", nome);                        
            struct Node *tmp;
            tmp = (struct Node*)malloc(sizeof(struct Node));
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
        
        case 8:{ //Deletar um jogo
            getchar();
            scanf("%[^\n]%*c", nome);
            Raiz = deleteNode(Raiz, nome);
            break;
        }

        case 9:{ //Imprimir toda a arvore
            impressaoTodos(Raiz);
            break;
        }

        case 0:{
            printf("\n\nFinalizando Execucao");
            break;
            }
        default:{
            printf("\nOperação Invalida\n");
            break;
        }
        }

        printf("\n\n\tMenu\n");
        printf("1: Incluir Jogo\n");
        printf("2: Buscar Jogo\n");
        printf("3: Buscar por Genero\n");
        printf("4: Buscar por Plataforma\n");
        printf("5: Buscar por Ano\n");
        printf("6: Alugar Jogo\n");
        printf("7: Devolver Jogo\n");
        printf("8: Remover Jogo\n");
        printf("9: Mostrar Todos os Jogos\n");
        printf("0: Finalizar Aplicacao\n");
        scanf("%d", &opCode2);
    } 
    return 0;
}