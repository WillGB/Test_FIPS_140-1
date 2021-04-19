#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>

using namespace std;

char m[21][20100];
int conv[21][20100];
char aspas[2];

int vMonoBit[21];

int mPokerTest[21][16];

int mRunTest1[21][2];
int mRunTest2[21][2];
int mRunTest3[21][2];
int mRunTest4[21][2];
int mRunTest5[21][2];
int mRunTest6[21][2];

int mLongRunTest[21][2];

void input(){
    FILE * file = fopen("chaves_criptografia.txt","r");
    for(int i = 0 ; i<20; i++){
        fgets(m[i],5003,file);
        fgets(aspas,2,file);
    }   
        fclose(file);
}

void printHexadecimal(){

  for(int j=0; j<20;j++){
            printf("\n\nChave %d = \n",j+1);
    for(int i=1;i<=20000;i++){
      printf("%c",m[0][i]);
    }
  } 
}

void printBinarios(){

    for(int j=0; j<20;j++){
            printf("\n\nChave %d = \n",j+1);
        for(int i=0;i<20000;i++){
            printf("%d",conv[j][i]);
        }
    }        
}

void convert(){
    for(int j = 0 ; j<20 ; j++){
        int cont = 0;
        
        for(int i = 1; i <= 5000 ; i++){

      if(m[j][i] == '0')
      {
          conv[j][cont] = 0;
          conv[j][cont+1] = 0;
          conv[j][cont+2] = 0;
          conv[j][cont+3] = 0;
        cont = cont + 4;
      }
      else if(m[j][i] == '1')
      {
          conv[j][cont] = 0;
          conv[j][cont+1] = 0;
          conv[j][cont+2] = 0;
          conv[j][cont+3] = 1;
          cont = cont + 4;
      }
      else if(m[j][i] == '2')
      {
          conv[j][cont] = 0;
          conv[j][cont+1] = 0;
          conv[j][cont+2] = 1;
          conv[j][cont+3] = 0;
          cont = cont + 4;
      }
      else if(m[j][i] == '3')
      {
          conv[j][cont] = 0;
          conv[j][cont+1] = 0;
          conv[j][cont+2] = 1;
          conv[j][cont+3] = 1;
          cont = cont + 4;
      }
      else if(m[j][i] == '4')
      {
          conv[j][cont] = 0;
          conv[j][cont+1] = 1;
          conv[j][cont+2] = 0;
          conv[j][cont+3] = 0;
          cont = cont + 4;
      }
      else if(m[j][i] == '5')
      {
        conv[j][cont] = 0;
          conv[j][cont+1] = 1;
          conv[j][cont+2] = 0;
          conv[j][cont+3] = 1;
          cont = cont + 4;
      }
      else if(m[j][i] == '6')
      {
        conv[j][cont] = 0;
          conv[j][cont+1] = 1;
          conv[j][cont+2] = 1;
          conv[j][cont+3] = 0;
          cont = cont + 4;
      }
      else if(m[j][i] == '7')
      {
        conv[j][cont] = 0;
          conv[j][cont+1] = 1;
          conv[j][cont+2] = 1;
          conv[j][cont+3] = 1;
          cont = cont + 4;
      }
      else if(m[j][i] == '8')
      {
        conv[j][cont] = 1;
          conv[j][cont+1] = 0;
          conv[j][cont+2] = 0;
          conv[j][cont+3] = 0;
          cont = cont + 4;
      }
      else if(m[j][i] == '9')
      {
        conv[j][cont] = 1;
          conv[j][cont+1] = 0;
          conv[j][cont+2] = 0;
          conv[j][cont+3] = 1;
          cont = cont + 4;
      }
      else if(m[j][i] == 'A')
      {
          conv[j][cont] = 1;
          conv[j][cont+1] = 0;
          conv[j][cont+2] = 1;
          conv[j][cont+3] = 0;
          cont = cont + 4;
      }
      else if(m[j][i] == 'B')
      {
        conv[j][cont] = 1;
          conv[j][cont+1] = 0;
          conv[j][cont+2] = 1;
          conv[j][cont+3] = 1;
          cont = cont + 4;
      }
      else if(m[j][i] == 'C')
      {
        conv[j][cont] = 1;
          conv[j][cont+1] = 1;
          conv[j][cont+2] = 0;
          conv[j][cont+3] = 0;
          cont = cont + 4;
      }
      else if(m[j][i] == 'D')
      {
        conv[j][cont] = 1;
          conv[j][cont+1] = 1;
          conv[j][cont+2] = 0;
          conv[j][cont+3] = 1;
          cont = cont + 4;
      }
      else if(m[j][i] == 'E')
      {
        conv[j][cont] = 1;
          conv[j][cont+1] = 1;
          conv[j][cont+2] = 1;
          conv[j][cont+3] = 0;
          cont = cont + 4;
      }
      else if(m[j][i] == 'F')
      {
        conv[j][cont] = 1;
          conv[j][cont+1] = 1;
          conv[j][cont+2] = 1;
          conv[j][cont+3] = 1;
          cont = cont + 4;
      }
      }
    }
}

void monobit(){

  for(int j=0; j<20;j++){
    for(int i=0;i<20000;i++){
        if(conv[j][i] == 1){
            vMonoBit[j] = vMonoBit[j] + 1;
        }
    }
    if(vMonoBit[j] > 9654 && vMonoBit[j] < 10346){
      printf("\nChave %d: APROVADA, %d numeros 1\n",j+1,vMonoBit[j]);
    }
    else{
      printf("\nChave %d: REPROVADA, %d numeros 1\n",j+1,vMonoBit[j]);
    }
  }
}

void pokertest(){
  for(int i=0;i<20;i++){
    
    for(int j=1; j<=5000; j++){
        
      if(m[i][j] == '0'){
        mPokerTest[i][0] = mPokerTest[i][0]+1;
      }  
      if(m[i][j] == '1'){
        mPokerTest[i][1] = mPokerTest[i][1]+1;
      }  
      if(m[i][j] == '2'){
        mPokerTest[i][2] = mPokerTest[i][2]+1;
      }  
      if(m[i][j] == '3'){
        mPokerTest[i][3] = mPokerTest[i][3]+1;
      }  
      if(m[i][j] == '4'){
        mPokerTest[i][4] = mPokerTest[i][4]+1;
      }  
      if(m[i][j] == '5'){
        mPokerTest[i][5] = mPokerTest[i][5]+1;
      }  
      if(m[i][j] == '6'){
        mPokerTest[i][6] = mPokerTest[i][6]+1;
      }  
      if(m[i][j] == '7'){
        mPokerTest[i][7] = mPokerTest[i][7]+1;
      }  
      if(m[i][j] == '8'){
        mPokerTest[i][8] = mPokerTest[i][8]+1;
      }  
      if(m[i][j] == '9'){
        mPokerTest[i][9] = mPokerTest[i][9]+1;
      }  
      if(m[i][j] == 'A'){
        mPokerTest[i][10] = mPokerTest[i][10]+1;
      }  
      if(m[i][j] == 'B'){
        mPokerTest[i][11] = mPokerTest[i][11]+1;
      }  
      if(m[i][j] == 'C'){
        mPokerTest[i][12] = mPokerTest[i][12]+1;
      }  
      if(m[i][j] == 'D'){
        mPokerTest[i][13] = mPokerTest[i][13]+1;
      }  
      if(m[i][j] == 'E'){
        mPokerTest[i][14] = mPokerTest[i][14]+1;
      }  
      if(m[i][j] == 'F'){
        mPokerTest[i][15] = mPokerTest[i][15]+1;
      }  
    }
  }
   
  for(int i = 0 ; i<20; i++){

    float calc [21];
    for(int i = 0; i < 20; i++){

      float sum = 0;
      for(int j = 0; j <= 15; j++){
        sum = sum + pow(mPokerTest[i][j], 2);
      }
      calc[i] = 16.0/5000.0 * sum;
      calc[i] = calc[i] - 5000;
    }

    if(calc[i] >1.03 && calc[i] <57.4){
      printf("\n\nChave %d - Valor: %f - APROVADA",i+1, calc[i]);
    }
    else{
      printf("\n\nChave %d - Valor: %f - REPROVADA",i+1, calc[i]);
    }      
  }
}

void runtest(){

  for (int i = 0; i < 20; i++){
    int y = 0;
    while(y < 20000){

      int c1=0;
      while(conv[i][y] == 1){
        c1++;
        y++;
      }
      int c0=0;
        while(conv[i][y] == 0){
          c0++;
          y++;
      }

      if(c1 == 1){
          mRunTest1[i][1] = mRunTest1[i][1] +1;
      }

      if(c1 == 2){
          mRunTest2[i][1] = mRunTest2[i][1] +1;
      }
      if(c1 == 3){
          mRunTest3[i][1] = mRunTest3[i][1] +1;
      }
      if(c1 == 4){
          mRunTest4[i][1] = mRunTest4[i][1] +1;
      }
      if(c1 == 5){
          mRunTest5[i][1] = mRunTest5[i][1] +1;
      }
      if(c1 >= 6 ){
          mRunTest6[i][1] = mRunTest6[i][1] +1;
      }

      if(c0 == 1){
          mRunTest1[i][0] = mRunTest1[i][0] +1;
      }

      if(c0 == 2){
          mRunTest2[i][0] = mRunTest2[i][0] +1;
      }
      if(c0 == 3){
          mRunTest3[i][0] = mRunTest3[i][0] +1;
      }
      if(c0 == 4){
          mRunTest4[i][0] = mRunTest4[i][0] +1;
      }
      if(c0 == 5){
          mRunTest5[i][0] = mRunTest5[i][0] +1;
      }
      if(c0 >= 6 ){
          mRunTest6[i][0] = mRunTest6[i][0] +1;
      }
    }
  }

  for (int i = 0; i < 20; i++){

  
    if(mRunTest1[i][0]>2267 && mRunTest1[i][0]<2733
    && mRunTest1[i][1]>2267 && mRunTest1[i][1]<2733
    && mRunTest2[i][0]>1079 && mRunTest2[i][0]<1421
    && mRunTest2[i][1]>1079 && mRunTest2[i][1]<1421
    && mRunTest3[i][0]>502 && mRunTest3[i][0]<748
    && mRunTest3[i][1]>502 && mRunTest3[i][1]<748
    && mRunTest4[i][0]>223 && mRunTest4[i][0]<402
    && mRunTest4[i][1]>223 && mRunTest4[i][1]<402
    && mRunTest5[i][0]>90 && mRunTest5[i][0]<223
    && mRunTest5[i][1]>90 && mRunTest5[i][1]<223
    && mRunTest6[i][0]>90 && mRunTest6[i][0]<223
    && mRunTest6[i][1]>90 && mRunTest6[i][1]<223){

      printf("\n\n Chave %d - APROVADA\n",i+1);
    }
    else{
      printf("\n\n Chave %d - REPROVADA\n",i+1);
    }
    printf("\n Numero de sequencias de tamanho 1: ");
    printf("\n 0 = %d",mRunTest1[i][0]);
    printf("\n 1 = %d\n",mRunTest1[i][1]);

    printf("\n Numero de sequencias de tamanho 2:");
    printf("\n 0 = %d",mRunTest2[i][0]);
    printf("\n 1 = %d\n",mRunTest2[i][1]);

    printf("\n Numero de sequencias de tamanho 3:");
    printf("\n 0 = %d",mRunTest3[i][0]);
    printf("\n 1 = %d\n",mRunTest3[i][1]);

    printf("\n Numero de sequencias de tamanho 4:");
    printf("\n 0 = %d",mRunTest4[i][0]);
    printf("\n 1 = %d\n",mRunTest4[i][1]);

    printf("\n Numero de sequencias de tamanho 5:");
    printf("\n 0 = %d",mRunTest5[i][0]);
    printf("\n 1 = %d\n",mRunTest5[i][1]);

    printf("\n Numero de sequencias de tamanho 6+:");
    printf("\n 0 = %d",mRunTest6[i][0]);
    printf("\n 1 = %d\n",mRunTest6[i][1]);
  }
}

void longruntest(){

  for (int i = 0; i < 20; i++){

    int x = 0;
    while(x < 20000){

      int c1=0;
      while(conv[i][x] == 1 && x < 20000){
        c1++;
        x++;
      }

      int c0=0;
        while(conv[i][x] == 0 && x < 20000){
          c0++;
          x++;
      }

      if(c0 >= 34){
          printf("\nValor de quantidade de 0 eh: %d", c0);
          mLongRunTest[i][0] = mLongRunTest[i][0] + 1;
      }
      if(c1 >= 34){
          printf("\nValor de quantidade de 1 eh: %d", c1);
          mLongRunTest[i][1] = mLongRunTest[i][1] + 1;
      }
    }
  }

    for (int i = 0; i < 20; i++){

      
      printf("\n\nChave %d",i+1);
      printf("\nNumero de sequencias de tamanho 34+:");
      printf("\n0 = %d",mLongRunTest[i][0]);
      printf("\n1 = %d",mLongRunTest[i][1]);
    }
}

void sair(){

    printf("\n\t\t\t\t\t\t  Finalizando programa......\n\n");
    exit(0);

}

int main(){

  input();
    convert();

  int valor;
  
  do{

    puts("\n\n\t========== TESTES DE CHAVES DE CRIPTOGRAFIA ==========\n\n");
    puts("\t1 - MONOBIT\n");
    puts("\t2 - POKER TEST\n");
    puts("\t3 - RUN TEST\n");
    puts("\t4 - LONG RUN TEST\n");
    puts("\t5 - PRINT HEXADECIMAL\n");
    puts("\t6 - PRINT BINARIO\n");
    puts("\t7 - Sair\n");
    printf("\n\tDigite uma opcao que deseja ver: ");
    scanf("%d",&valor);

    switch (valor)
    {
      case 1 :
        monobit();
      break;
      
      case 2 :
        pokertest();
      break;
      
      case 3 :
        runtest();
      break;
      
      case 4 :
        longruntest();
      break;
      
      case 5 :
        printHexadecimal();
      break;
      
      case 6 :
        printBinarios();
      break;
      
      case 7 :
        sair();
      break;

      default:   
        printf("\n\t\t\t\t=============Opcao invalida! Tente novamente!===========\n\t\t");
        break;
    }
  }while(valor != 7);

  return 0;
}