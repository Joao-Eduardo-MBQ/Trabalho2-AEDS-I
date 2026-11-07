#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "turma.h"


void FVaziaTurma(TurmaFila *FT) {
    FT->frente = (TurmaCell*) malloc(sizeof(TurmaCell));
    FT->tras = FT->frente;
    FT->frente->prox = NULL;
}

int VaziaTurma(TurmaFila FT) {
    return (FT.frente == FT.tras);
}

int InicializaTurma(Turma *Tm, int cod, int codDis, int codProf, float horario, char *sala, int vagas) {
    Tm->cod = cod;
    Tm->codDis = codDis;
    Tm->codProf = codProf;
    Tm->horario = horario;
    strncpy(Tm->sala, sala, TAM_SALA - 1);
    Tm->sala[TAM_SALA - 1] = '\0';
    Tm->vagas = vagas;
    return 0;
}

int CadastrarTurma(TurmaFila *FT, Turma Tm) {
    FT->tras->prox = (TurmaCell*) malloc(sizeof(TurmaCell));
    FT->tras = FT->tras->prox;
    FT->tras->dados = Tm;
    FT->tras->prox = NULL;
    return 0;
}

int RemoveTurma(TurmaFila *FT, Turma *Tm) {
    TurmaCell *aux;
    if (!VaziaTurma(*FT)) {
        aux = FT->frente->prox;
        FT->frente->prox = aux->prox;
        *Tm = aux->dados;
        free(aux);
        if (FT->frente->prox == NULL) {
            FT->tras = FT->frente;
        }
    }
    return 0; 
}

int PesquisarTurma(TurmaFila *FT, Turma x) {
    TurmaCell *aux = FT->frente->prox;
    while (aux != NULL) {
        if (aux->dados.cod == x.cod)
            return 1;
        aux = aux->prox;
    }
    return 0;
}

void ListarTurma(TurmaFila FT) {
    TurmaCell *aux = FT.frente->prox;
    while (aux != NULL) {
        printf("Código: %d\n", aux->dados.cod);
        printf("Código da Disciplina: %d\n", aux->dados.codDis);
        printf("Código do Professor: %d\n", aux->dados.codProf);
        printf("Horário: %.2f\n", aux->dados.horario);
        printf("Sala: %s\n", aux->dados.sala);
        printf("Vagas: %d\n", aux->dados.vagas);
        printf("------------------------\n");
        aux = aux->prox;
    }
}

void LiberarTurma(TurmaFila *FT) {
    Turma item;
    while (!VaziaTurma(*FT)) {
        RemoveTurma(FT, &item);
    }
    free(FT->frente);
}