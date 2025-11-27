#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int ra;
    char nome[50];
    char curso[50];
    float notas[4];
    int anoInicio;
    int idade;
} Aluno;


Aluno criarAluno(){
    Aluno a;
    int i;
    printf("Digite o RA do aluno: \n");
    scanf("%d", &a.ra);
    printf("Digite o nome do aluno: \n");
    scanf(" %[^\n]", a.nome);
    printf("Digite o curso do aluno: \n");
    scanf(" %[^\n]", a.curso);
    printf("Digite a idade do aluno: \n");
    scanf("%d", &a.idade);
    printf("Digite o ano de inicio: \n");
    scanf("%d", &a.anoInicio);

    printf("Digite as notas desse aluno: \n");
    for(i=0;i<4;i++){
        printf("Nota %d: ", i+1);
        scanf("%f", &a.notas[i]);
    }

    return a;
}


void exibirAluno(Aluno a){
    int i;
    printf("\nRA: %d\n", a.ra);
    printf("Nome: %s\n", a.nome);
    printf("Curso: %s\n", a.curso);
    printf("Idade: %d\n", a.idade);
    printf("Ano de inicio: %d\n", a.anoInicio);

    printf("Notas:\n");
    for(i=0; i<4; i++){
        printf("Nota %d: %.2f\n", i+1, a.notas[i]);
    }

    float media = 0;
    for(i=0;i<4;i++){
        media += a.notas[i];
    }
    media /= 4;
    printf("Media das notas: %.2f\n", media);
}


int buscarAluno(Aluno alunos[], int quantidade, int ra){
    int i;
    for(i=0; i<quantidade; i++){
        if(alunos[i].ra == ra){
            return i;
        }
    }
    return -1;
}


void exibirAlunoMaiorMedia(Aluno alunos[], int quantidade){
    if(quantidade == 0){
        printf("Nenhum aluno cadastrado.\n");
        return;
    }

    int i, j;
    int idxMaior = 0;
    float maiorMedia = -1;

    for(i=0; i<quantidade; i++){
        float soma = 0;
        for(j=0; j<4; j++){
            soma += alunos[i].notas[j];
        }
        float media = soma / 4;

        if(media > maiorMedia){
            maiorMedia = media;
            idxMaior = i;
        }
    }

    printf("\nAluno com a maior media:\n");
    exibirAluno(alunos[idxMaior]);
}


void mediaDasMedias(Aluno alunos[], int quantidade){
    if(quantidade == 0){
        printf("Nenhum aluno cadastrado.\n");
        return;
    }

    int i, j;
    float somaMedias = 0;

    for(i=0; i<quantidade; i++){
        float soma = 0;
        for(j=0; j<4; j++){
            soma += alunos[i].notas[j];
        }
        somaMedias += soma / 4;
    }

    float mediaGeral = somaMedias / quantidade;
    printf("\nMedia das medias: %.2f\n", mediaGeral);
}

int excluirAlunoPorRA(Aluno alunos[], int *quantidade, int ra){
    int idx = buscarAluno(alunos, *quantidade, ra);
    if(idx == -1){
        printf("Aluno nao encontrado.\n");
        return 0; 
    }

    int i;
    for(i = idx; i < *quantidade - 1; i++){
        alunos[i] = alunos[i + 1];
    }

    (*quantidade)--;
    printf("Aluno excluido com sucesso.\n");
    return 1;
}



int main(){
    int op, i;
    char resposta;
    Aluno alunos[40];
    int quantidade = 0;

    do{
        printf("\nBem vindo, qual funcao deseja realizar?\n");
        printf("[1] Cadastrar novo aluno\n");
        printf("[2] Listar todos os alunos\n");
        printf("[3] Buscar aluno pelo RA\n");
        printf("[4] Exibir o aluno com a maior media\n");
        printf("[5] Exibir a media das medias\n");
        printf("[6] Excluir um aluno pelo RA\n");
        printf("[7] Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &op);

        switch(op){
            case 1:
                do{
                    if(quantidade < 40){
                        alunos[quantidade] = criarAluno();
                        quantidade++;
                    } else{
                        printf("Limite de alunos atingido!\n");
                        break;
                    }
                    printf("Deseja continuar o cadastro dos alunos(s/n)? ");
                    scanf(" %c", &resposta);
                } while(resposta == 's' || resposta == 'S');
                break;

            case 2:
                if(quantidade <= 0){
                    printf("Nenhum aluno cadastrado\n");
                } else{
                    for(i=0;i<quantidade;i++){
                        exibirAluno(alunos[i]);
                    }
                }
                break;

            case 3:{
                int raProcurado;
                printf("Digite o RA do aluno a ser buscado: ");
                scanf("%d", &raProcurado);
                int idx = buscarAluno(alunos, quantidade, raProcurado);
                if(idx == -1){
                    printf("Aluno nao encontrado\n");
                } else{
                    exibirAluno(alunos[idx]);
                }
                break;
            }

            case 4:
                exibirAlunoMaiorMedia(alunos, quantidade);
                break;

            case 5:
                mediaDasMedias(alunos, quantidade);
                break;

            case 6:{
                int raExcluir;
                printf("Digite o RA do aluno a ser excluido: ");
                scanf("%d", &raExcluir);
                excluirAlunoPorRA(alunos, &quantidade, raExcluir);
                break;
            }

            case 7:
                printf("Programa encerrado.\n");
                break;

            default:
                printf("Opcao invalida\n");
                break;
        }

    } while(op != 7);

    return 0;
}

