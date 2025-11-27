/*#include <stdio.h>
#include <stdlib.h>

float potencia(float base, int exp){
	float resp = 1;
	int i;
	for(i=1; i<=exp; i++)
		resp = resp * base;
	
	return resp;
		
	
	
}

int main(int argc, char *argv[]) {
	float b;
	int e;
	
	printf("informe a base: ");
	scanf("%f", &b);
	
	printf("Informe o expoente >=0:  ");
	scanf("%d", &e);
	
	
	printf("%.2f^%d = %.2f",b,e,potencia(b,e));
	
	return 0;
} */

#include <stdio.h>
#include <stdlib.h>

int ehPar(int val){
	return !(val % 2); 
		
}

int main(int argc, char *argv[]) {
	int val;
	
	
	printf("Valor: ");
	scanf("%d", &val);
	
	
	
	if(ehPar(val))
		printf("%d e par.", val);
	else
		("%d nao e par.", val);
		
	
	return 0;
} 