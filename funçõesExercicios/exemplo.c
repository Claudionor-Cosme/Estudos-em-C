#include <stdio.h>
#include <stdlib.h>

// exenplo 1
/*
float potencia(float base, int exp){
    float resp = 1;
    int i;
    for(i=1; i<=exp; i++){
        resp *= base;
    }
    return resp;
}

int main(){
    float b;
    int e;

    printf("Informe a base: ");
    scanf("%f", &b);

    printf("Informe o expoente >= 0: ");
    scanf("%d", &e);

    printf("%.2f^%d = %.2f", b,e,potencia(b,e));
    }
*/

// exemplo 2
/*
int par(int val){
    return !(val % 2);
}

int main(){
     int val;

     printf("Valor: ");
     scanf("%d", &val);

     if(par(val)==1){
        printf("%d é par.", val);
     }else{
        printf("%d não é par.", val);
     }
}
*/