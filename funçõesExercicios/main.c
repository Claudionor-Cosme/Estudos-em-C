#include<stdio.h>
#include<conio.h>
/*
Nome da função: multiplica
recebe como parâmetos dois valores inteiros (N1,N2)
objetivo: multiplicar os valores recebidos nos parâmetros.
retorno: um parâmetro inteiro (res) contendo o resultado
*/
int multiplica(int N1, int N2) 
{
  int resultado;
  resultado = N1 * N2;
  return(resultado);
}

int main(void)
{
  int V1, V2, resultado;
  printf("Digite o primeiro valor:");
  scanf("%d", &V1);
  printf("Digite o segundo valor:");
  scanf("%d", &V2);
  

  resultado = multiplica(V1,V2);
  
  printf("Resultado = %d\n", resultado);
  
  getch();
  return 0;
}