#include <stdio.h>
#include <string.h>
#include "../include/aluno.h"

void iniciarA(VetorAlunos *v){

    v->tamanho = 0;
}

int iniciarAluno(Aluno *a, int matricula, const char *nome, const char *curso, const char *periodo, const char *email){
    
    memset(a, 0, sizeof(*a));
    a->matricula = matricula;
    strncpy(a->nome, nome, sizeof(a->nome) - 1);
    a->nome[sizeof(a->nome) - 1] = '\0';
    strncpy(a->curso, curso, sizeof(a->curso) - 1);
    a->curso[sizeof(a->curso) - 1] = '\0';
    strncpy(a->periodo, periodo, sizeof(a->periodo) - 1);
    a->periodo[sizeof(a->periodo) - 1] = '\0';
    strncpy(a->email, email, sizeof(a->email) - 1);
    a->email[sizeof(a->email) - 1] = '\0';
    return 1;
}

int inserirA(VetorAlunos *v, Aluno a){

    v->dados[v->tamanho] = a;
    v->tamanho++;
    return 1;
}

int removerA(VetorAlunos *v, int matricula){

    int i = buscarA(v, matricula);

    if(i != -1){

    for(int j = i; j < v->tamanho - 1; j++){
        v->dados[j] = v->dados[j + 1];
    }
    v->tamanho--;
    return 1;
    }
    return 0;
}

int buscarA(const VetorAlunos *v, int matricula){

    for(int i = 0; i < v->tamanho; i++){
        if(v->dados[i].matricula == matricula){
            return i;
        }
    }
    return -1;
}

void imprimirAluno(const Aluno *a){
    printf("Matricula: %d | Nome: %s | Curso: %s | Periodo: %s | E-mail: %s\n",
           a->matricula, a->nome, a->curso, a->periodo, a->email);
}

void listarA(const VetorAlunos *v){

    for(int i = 0; i < v->tamanho; i++){
        imprimirAluno(&v->dados[i]);
    }
}