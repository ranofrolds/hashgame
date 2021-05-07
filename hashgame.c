#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char i[3][3];
char simbolo;
char posicao;
bool result, sla;

int mostravelha(){

    for(int c=0;c<3;c++){
        for(int l=0;l<3;l++){
            printf("%c ", i[c][l]);
        }
    printf("\n");
    }
    return 0;
}

bool cadastravelha(){

    char num = 'a';

    for(int c=0;c<3;c++){
        for(int l=0;l<3;l++){
            i[c][l]=num;
            ++num;
        }
    }
    return 0;

}

bool velha(){
int c, l;
//caso colunas
    for (c=0; c<3; c++){
        if((i[c][0] == i[c][1])&&(i[c][1] == i[c][2])){
            result = true;
        }
    }
//caso linhas
    for (l=0; l<3; l++){
        if((i[0][l] == i[1][l])&&(i[1][l]== i[2][l])){
            result = true;
        }
    }
//caso diagonais

    if((i[0][0] == i[1][1]) && (i[1][1] == i[2][2])){
        result = true;
    }
    else if((i[2][0] == i[1][1]) && (i[1][1] == i[0][2])){
            result = true;
    }

//velha

    char n='a';
    int x=0;
    for(int c=0;c<3;c++){
        for(int l=0;l<3;l++){
          if ((i[c][l] != 'X') || (i[c][l]!= 'O')){
           x+=1;
          }
        ++n;
        }
    }
    if (x=0){
        result = true;
    }
return result;
}

void mudajogador(){

   switch (simbolo){
       case 'X':
            simbolo = 'O';
            break;

        case 'O':
            simbolo = 'X';
            break;
   }
}

bool mudou(char a, char b){
     for(int c=0;c<3;c++){
        for(int l=0;l<3;l++){
            if (i[c][l] == b){
                i[c][l] = a;
            sla =true;
            }
        }
     }

    return sla;
}

void limpa_buffer() {
  int c;

  do {
    c = getchar();
  } while (c != '\n' && c != EOF);
}

int main(){
    simbolo = 'X';
    cadastravelha();
    mostravelha();

    do{
        do{
            printf("Vai jogar %c em que posicao?\n", simbolo);
            scanf("%c", &posicao);
	    limpa_buffer()
                if (mudou(simbolo, posicao)!=true){
                    printf("JOGADA INVALIDA\n");
                }
        }
        while (mudou(simbolo, posicao)!=true);
    mudajogador();
    system("cls");
    mostravelha();
    }
    while(velha()!=true);
    printf("FIM DE JOGO");

    return 0;
}






