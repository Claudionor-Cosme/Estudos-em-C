// exercicio 1

#include <stdio.h>
#include <stdlib.h>

float calcSum(float x, float y){
    return x+y;
}

float calcSub(float x, float y){
    return x-y;
}

float calcMul(float x, float y){
    return x*y;
}

float calcDiv(float x, float y){
    return x/y;
}

int menu(){
    int op;
    printf("\n1 - soma");
    printf("\n2 - subtracao");
    printf("\n3 - multiplicacao");
    printf("\n4 - divisao");
    printf("\n5 - sair");
    
    printf("informe a opcao: ");
    scanf("%d", &op);
}

int main(){
    float n1, n2;
    int op;

    do{
        op = menu();

        if(op >= 1 && op <= 4){
            printf("Informe o primeiro valor: ");
            scanf("%f", &n1);
            printf("Informe o segundo valor: ");
            scanf("%f", &n2);
        }
        
        switch (op){
        case '1':
            printf("%.2f + .2%f = .2%f", n1, n2,calcSum(n1,n2));
            break;
        case '2':
            printf("%.2f - .2%f = .2%f", n1, n2,calcSub(n1,n2));
            break;
        case '3':
            printf("%.2f * .2%f = .2%f", n1, n2,calcMul(n1,n2));
            break;
        case '4':
            if(n2 != 0)
                printf("%.2f * .2%f = .2%f", n1, n2,calcMul(n1,n2));
            else
                printf("Nao eh possivel realizar a divisao por zero.\n");
            break;
        case '5':
            printf("\nAté logo.");
        default:
            printf("Caso invalido!\n");
            return 0;
    }
    }while(op!=5);
    
}

/*
#include <stdio.h>
#include <stdlib.h>

float operacoes(float x, float y, char op){

    switch (op){
        case '+':
            printf("%f + %f = %f", x, y, x+y);
            break;
        case '-':
            printf("%f - %f = %f", x, y, x-y);
            break;
        case '*':
            printf("%f * %f = %f", x, y, x*y);
            break;
        case '/':
            if(y != 0)
                printf("%f / %f = %f", x, y, x/y);
            else
                printf("Nao eh possivel realizar a divisao por zero.\n");
            break;
        default:
            printf("Caso invalido!\n");
            return 0;
    }
}

int main(){

    float x, y;
    char op;
    
    printf("Calculadora basica em C\n");
    printf("As operacoes disponiveis sao \n\n");
    printf("Adicao (+)\n");
    printf("Subtracao (-)\n");
    printf("Multiplicacao (*)\n");
    printf("Divisao (/)\n");
    printf("\n\nDigite um numero, a operacao e outro numero, como mostra o exemplo: 397 + 635.2 ");
    scanf("%f, %c, %f", &x, &op, &y);    


}
*/

// exercicio 2
/*
*/
#include <stdio.h>
#include <stdlib.h>

void fibonacci(int n){
    int i;
    int ult=1, pen=1, aux;

    printf("Os %d primeiros numeros de fibonacci sao:\n", n);
    for(i=1;i<=n;i++){
        if(i>2){
            aux = ult+pen;
            pen = ult;
            ult = aux;
        }
        printf("%d", ult);
    }
}

int main(){
    int n;

    printf("Informe N: ");
    scanf("%d", &n);

    fibonacci(n);
}