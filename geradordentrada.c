#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int i = 0, lib = 0, al1, al2, al3;
    FILE *arq, *arq2, *arq3, *arq4;
    char string1[1010], string2[1010], string3[1010], string4[1010], string5[1010], string6[1010]; 
    srand(time(0));
    arq = fopen("insertions.txt","r");
    arq2 = fopen("generos.txt","r");
    arq3 = fopen("nomes.txt","r");
    arq4 = fopen("Entrada.txt","w");
    while(i != 10010 || lib != 1255){
        al1 = rand() %7;
        i++;
        if(al1 == 0 && lib!= 1255){
            lib++;
            fgets(string1, 1000, arq);
            fputs(string1, arq4);
            fgets(string1, 1000, arq);
            fputs(string1, arq4);
            fgets(string1, 1000, arq);
            fputs(string1, arq4);
            fgets(string1, 1000, arq);
            fputs(string1, arq4);
            fgets(string1, 1000, arq);
            fputs(string1, arq4);
        }
        if(al1 == 1){
            fprintf(arq4, "2\n");
            fgets(string2, 1000, arq3);
            fputs(string2, arq4);
        }
        if(al1 == 2){
            fprintf(arq4 ,"3\n");
            fgets(string3, 1000, arq2);
            fputs(string3, arq4);
        }
        if(al1 == 3){
            al2 = rand() %9;
            fprintf(arq4, "4\n");
            if(al2 == 0){
                fprintf(arq4, "PlayStation 1\n");
            }
            if(al2 == 1){
                fprintf(arq4, "PlayStation 2\n");
            }
            if(al2 == 2){
                fprintf(arq4, "PlayStation 3\n");
            }
            if(al2 == 3){
                fprintf(arq4, "PlayStation 4\n");
            }
            if(al2 == 4){
                fprintf(arq4, "PlayStation 5\n");
            }
            if(al2 == 5){
                fprintf(arq4, "Xbox 360\n");
            }
            if(al2 == 6){
                fprintf(arq4, "Xbox One\n");
            }
            if(al2 == 7){
                fprintf(arq4, "Xbox Series\n");
            }
            if(al2 == 8){
                fprintf(arq4, "PC\n");
            }
        }
        if(al1 == 4){
            al3 = (rand() %24) + 1998;
            fprintf(arq4, "5\n%d\n", al3);
        }
        if(al1 == 5){
            fprintf(arq4, "6\n");
            fgets(string4, 1000, arq3);
            fputs(string4, arq4);
        }
        if(al1 == 6){
            fprintf(arq4, "7\n");
            fgets(string5, 1000, arq3);
            fputs(string5, arq4);
        }
        if(al1 == 7){
            fprintf(arq4, "8\n");
            fgets(string6, 1000, arq3);
            fputs(string6, arq4);
        }
    }
    printf("\nNumero de entradas geradas: %d\n",i);
}