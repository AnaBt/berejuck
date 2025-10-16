/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <unistd.h>

int cafe = 0; //1
int leite = 5;//2
int chocolate = 5;//3
int acucar = 5; //4

void LiberaAgua(int dose){
    if (dose == 1){
        printf("Abrindo a valvula para bebida pequena\n");
        sleep(5);
        printf("valvula aberta para bebida pequena\n");
    } else {
        printf("Abrindo a valvula para bebida grande\n");
        sleep(10);
        printf("valvula aberta para bebida grande\n");
    }
}
void recarregar(int num){
    if(num == 1){
        cafe = 20;
        printf("Pó de café restabelecido para 20 unidades\n");
    } else if (num == 2){
        leite = 20;
        printf("Pó de leite restabelecido para 20 unidades\n");
    } else if (num == 3){
        chocolate = 20;
        printf("Pó de chocolate restabelecido para 20 unidades\n");
    } else {
        acucar = 20;
        printf("Pó de acucar restabelecido para 20 unidades\n");
    }
}
   
void PegarPo(int bebida,int dose,char QuerAcucar){
    if(cafe - dose < 0 || leite - dose < 0 || chocolate - dose < 0 || acucar - dose < 0){
        printf("Não há estoque disponivel de ingredientes disponiveis\n\nESTOQUE ATUAL\nCafe\t\t%d\nLeite\t\t%d\nChocolate\t%d\nAcucar\t\t%d\n\n gostaria de recarregar\n 1 - SIM\n 2 - NAO \n",cafe,leite,chocolate,acucar);
        recarregar(1);
     } else {
          //independente da bebiba eu tiro cafe
    printf("Colocando %d dose(s) de café\n" , dose);
    cafe = cafe - dose;
    sleep(dose);
    
    
    if(bebida == 2) {
        printf("Colocando %d dose(s) de leite\n" , dose);
        sleep(dose);
        
        leite = leite - dose;
    }
   
    else if (bebida == 3) {
        printf("Colocando %d dose(s) de leite\n" , dose);
        sleep(dose);
        printf("Colocando %d dose(s) de chocolate" , dose);
        sleep(dose);
        
        leite = leite - dose;
        chocolate = chocolate - dose;
    } 
    if(QuerAcucar == 'E'){
        printf("Colocando %d dose(s) de acucar\n" , dose);
        sleep(dose);
        acucar = acucar - dose;
    }
     LiberaAgua(dose);
     }
   
}
int main()
{
    int bebida = 0;
    printf("ESCOLHA SUA BEBIDA \nCafé puro (1)\nCafé com leite (2) \nMoccachino (3) \n");
    scanf ("%d" , &bebida);
    
    char tamanho;
    printf("ESCOLHA O TAMANHO \nPequeno (A)\nGrande (B)\n");
    scanf (" %c" , &tamanho);
    char QuerAcucar;
    printf("GOSTARIA DE ACUCAR \nSim (E)\nNao (F)\n");
    scanf (" %c" , &QuerAcucar);
    
    int dose = 0;
   if (tamanho == 'A'){
       dose = 1;
   } else {
       dose = 2;
   }
    
    PegarPo(bebida,dose,QuerAcucar);
   
    printf("Cafe %d , Leite %d , Chocolate %d , Acucar %d \n",
    cafe,leite,chocolate,acucar);
    return 0;
}
