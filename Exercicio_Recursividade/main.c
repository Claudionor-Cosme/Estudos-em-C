#include <stdio.h>
#include <stdlib.h>

/* Faça uma programa usando função, que receba um
valor inteiro n e retorne o fatorial de n */
// funcao recursiva para calcular fatorial

long long fatorial(int n) {
    if (n < 0) {
      
        printf("Fatorial indefinido para numeros negativos\n");
        return -1;
    }
    if (n == 0 || n == 1) {
        return 1; // caso base
    } else {
        return (long long)n * fatorial(n - 1);
    }
}

int main() {
    int n;
    printf("Digite um numero inteiro: ");
    scanf("%d", &n);

    long long resultado = fatorial(n);

    if (resultado != -1) { 
        printf("Fatorial de %d = %lld\n", n, resultado);
    }

    return 0;
}
