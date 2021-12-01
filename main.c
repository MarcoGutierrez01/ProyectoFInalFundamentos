/*@author Marco Gutierrez (mi pareja retiro la materia)
<00363621@uca.edu.sv>
@date 11/03/2021*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//declaracion de variables
int matriz[9][9];
int i, j, k, l, c = 0,rr = 9;
int score = 0;
int fourPlus = 0;
int row1 = 1,row2 = 2,row3 = 3,row4 = 4,row5 = 5,row6 = 6,row7 = 7,row8 = 8,row9 = 9;

//declaracion de funciones
void randomNum();
void printArray();
void getPair();
int emparejar(int, int, int, int, int);
void scoreBoard();
int addRow();

int main(int argc, char const *argv[]){
  printf("\n");
  printf("Match 10 \n\n"); // nombre del juego

  randomNum();

  int a = 0;
  while (a < 7){
    printArray();
    getPair();
      if (emparejar(i, j, k, l, c) > 0){
            matriz[i - 1][j - 1] = 0;
            matriz[k - 1][l - 1] = 0;
        }
    scoreBoard();
    
      if(addRow()==0){
        rr++;
        }
    }  return 0;
}

//recoleccion de datos para identificar que numero en la matriz se esta seleccionando
void getPair(){
    printf("\n Ingrese la fila seguido de la columna en la que se encuentra el primer numero que desea emparejar: \n");
    scanf("%d%d", &i, &j);
    printf("\n Ingrese la fila seguido de la columna en la que se encuentra el segundo numero que desea emparejar: \n");
    scanf("%d%d", &k, &l);
}

//generar numeros random en la matriz
void randomNum(){
    int i, j;
    srand(time(NULL));
    for (i = 0; i < 9; i++){
        for (j = 0; j < 9; j++){
            int num = (rand() % (9 - 1 + 1)) + 1;
            matriz[i][j] =num;
        }
    }
}

//imprimir matriz
void printArray(){
    int i, j;
    for (i = 0; i < rr; i++){
        for (j = 0; j < 9; j++) {
            if (matriz[i][j] != 0){
                printf("%d |", matriz[i][j]);
            }else {
                printf("  |");
            }
        }
        printf("\n");
    }
}

//logica para agregar fila cuando no hay mas pares en el juego
int addRow(){
    int rott=0;
    for(int ro1=0;ro1<rr;ro1++){
        for(int co1=0;co1<9;co1++){
            if(ro1<rr-1){
                if(matriz[ro1][co1]!=0){
                    if(matriz[ro1][co1] == matriz[ro1][co1+1] || matriz[ro1][co1] == matriz[ro1+1][co1]);
                    if (matriz[ro1][co1]== matriz[ro1+1][co1+1] || matriz[ro1][co1]+matriz[ro1][co1+1]==10);
                    if (matriz[ro1][co1]+matriz[ro1+1][co1]==10|| matriz[ro1][co1]+matriz[ro1+1][co1+1]==10){
                      rott++;
                    }
            }
            }else{
              if(matriz[ro1][co1]!=0){
                if(matriz[ro1][co1] == matriz[ro1][co1+1] || matriz[ro1][co1]+matriz[ro1][co1+1]==10){
                    rott++;
                }
                }
            }

        }

    }
    return rott;
}

// logica para sumar los numeros que se seleccionaron e identificar si el emparejamiento se puede o no
int emparejar(int i, int j, int k, int l, int c){
    int co;
    if (i + j == k + l - 1 || k + l == i + j - 1 || i + j == k + l || i - j == k - l || j == 9 && l == 1 ){
        if (matriz[i - 1][j - 1] == matriz[k - 1][l - 1] || matriz[i - 1][j - 1] + matriz[k - 1][l - 1] == 10 ){
            c++;
        }
    }
        if (matriz[i - 1][j - 1] == matriz[k - 1][l - 1] || matriz[i - 1][j - 1] + matriz[k - 1][l - 1] == 10 ){
        for(int lol= j ; lol < (l-1) ; lol++){
            if(matriz[i-1][lol] != 0){
                co++;
            }
        }
        if(co==0){
            c++;
            fourPlus ++;
        }
      }
        if (matriz[i - 1][j - 1] == matriz[k - 1][l - 1] || matriz[i - 1][j - 1] + matriz[k - 1][l - 1] == 10 ){
            if(i+j==k+l-2 || k+l==i+j+2){
            if(matriz[k-2][l-1]==0 && matriz[i][j-1]==0){
                c++;
                fourPlus ++;
            }
          }
        }
    return c;
}

//logica para identificar y sumar los puntos que gana el jugador por cada emparejamiento 
//que hace y guardarlos para despues imprimir
void scoreBoard(){
    int counter = 0, counter1=0, counter2=0;
    if(fourPlus > 0){
        if(i+j==k+l-2){
                score+=4;
        }
    }
    if(addRow()==0){  //cuando el jugador limpia de numeros el juego, gana 150 puntos y se termina el juego y ya no se agregan mas filas
        score+=150;
    }                 
    if (j == 9 && l == 1){    //sino, va ganando puntos hasta que ya no se pueden hacer mas parejas
        if (matriz[i - 1][j - 1] == matriz[k - 1][l - 1] || matriz[i - 1][j - 1] + matriz[k - 1][l - 1] == 10) {
                score+=2;
        }
    }
    if (i + j == k + l - 1 || k + l == i + j - 1) {
        if (matriz[i - 1][j - 1] == matriz[k - 1][l - 1] || matriz[i - 1][j - 1] + matriz[k - 1][l - 1] == 10) {
                score+=1;
        }
    }
    if (i + j == k + l || i - j == k - l) {
        if (matriz[i - 1][j - 1] == matriz[k - 1][l - 1] || matriz[i - 1][j - 1] + matriz[k - 1][l - 1] == 10) {
                score+=2;
        }
    }

        for(int col=0;col<9;col++){
            if(matriz[row1][col]!=0){
                counter++;
            }
        }
        if(counter==0){
            score+=10;
            row1=90;
        }

        for(int col=0;col<9;col++){
            if(matriz[row2][col]!=0){
                counter1++;
            }
        }
        if(counter1==0){
            score+=10;
            row2=90;
        }

        for(int col=0;col<9;col++){
            if(matriz[row3][col]!= 0){
                counter2++;
            }
        }
        if(counter2==0){
            score+=10;
            row3=90;
        }
        for(int col=0;col<9;col++){
            if(matriz[row4][col]!=0){
                counter2++;
            }
        }
        if(counter2==0){
            score+=10;
            row4=90;
        }
for(int col=0;col<9;col++){
            if(matriz[row5][col]!=0){
                counter2++;
            }
        }
        if(counter2==0){
            score+=10;
            row5=90;
        }
        for(int col=0;col<9;col++){
            if(matriz[row6][col]!=0){
                counter2++;
            }
        }
        if(counter2==0){
            score+=10;
            row6=90;
        }
        for(int col=0;col<9;col++){
            if(matriz[row7][col]!=0){
                counter2++;
            }
        }
        if(counter2==0){
            score+=10;
            row7=90;
        }
        for(int col=0;col<9;col++){
            if(matriz[row8][col]!=0){
                counter2++;
            }
        }
        if(counter2==0){
            score+=10;
            row8=90;
        }
        for(int col=0;col<9;col++){
            if(matriz[row9][col]!=0){
                counter2++;
            }
        }
        if(counter2==0){
            score+=10;
            row9=90;
        }
    
    //imprimir tablero y los puntos del jugador
    printf("\n              Scoreboard");
    printf("\nPlayer Points             ");
    printf("%d",score);
    printf("\n\n");
}
