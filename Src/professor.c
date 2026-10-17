#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "professor.h"


void iniciarP(ListaProfessores *l) {

    l->inicio = l->fim = NULL;
    l->tamanho = 0;

}

int iniciarProfessor(Professor *p, int matricula, const char *nome, const char *area, const char *email) {

    p->matricula = matricula;
    strncpy(p->nome,  nome,  TAM_NOME  - 1); 
    p->nome[TAM_NOME - 1]   = '\0';
    strncpy(p->area,  area,  TAM_AREA  - 1); 
    p->area[TAM_AREA - 1]   = '\0';
    strncpy(p->email, email, TAM_EMAIL - 1); 
    p->email[TAM_EMAIL - 1] = '\0';
    
    return 1;

}

int inserirP(ListaProfessores *l, Professor p){

    NoProfessor *no = malloc(sizeof(NoProfessor));

    no->dados = p;
    no->prox = NULL;
    no->ant = l->fim; 

    if(l->fim){
        l->fim->prox = no;
    }else{
        l->inicio = no;
    }

    l->fim = no;
    l->tamanho++;
    return 1;

}

NoProfessor *buscarP(const ListaProfessores *l, int matricula){

    for(NoProfessor *at = l->inicio; at; at = at ->prox){
        if(at->dados.matricula == matricula){
            return at;
        }
    }
    return NULL;

}

    int removerP(ListaProfessores *l, int matricula){

        NoProfessor *at = buscarP(l, matricula);

        if(at->ant){
            at->ant->prox = at->prox;
        }else{
            l->inicio = at->prox;
        }

        if(at->prox){
            at->prox->ant = at->ant;
        }else{
            l->fim = at->ant;
        }

        free(at);
        l->tamanho--;
        return 1;

    }

static void imprimirProfessor(const Professor *p) {

    printf("%d | %s | %s | %s\n", p->matricula, p->nome, p->area, p->email);

}

void listarP(const ListaProfessores *l){

    for(NoProfessor *at = l->inicio; at; at = at->prox){
        imprimirProfessor(&at->dados);
    }

}

void liberarP(ListaProfessores *l){

    NoProfessor *at = l->inicio;
    while (at) {
        NoProfessor *prox = at->prox;
        free(at);
        at = prox;
    }

    l->inicio = l->fim = NULL;
    l->tamanho = 0;

}

