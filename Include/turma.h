#ifndef TURMA_H__INCLUDED
#define TURMA_H__INCLUDED
#include "util.h"

typedef struct {
    int cod;
    int codDis;
    int codProf;
    float horario;
    char sala[TAM_SALA];
    int vagas;
} Turma;

typedef struct TurmaCell {
    Turma dados;
    struct TurmaCell *prox;
} TurmaCell;

typedef struct TurmaFila{
    TurmaCell *frente;
    TurmaCell *tras;
} TurmaFila;

void FVaziaTurma(TurmaFila *FT);

int VaziaTurma(TurmaFila FT);

int InicializaTurma(Turma *Tm, int cod, int codDis, int codProf, float horario, char *sala, int vagas);

int CadastrarTurma(TurmaFila *FT, Turma Tm);

int RemoveTurma(TurmaFila *FT, Turma *Tm);

int PesquisarTurma(TurmaFila *FT, Turma x);

void ListarTurma(TurmaFila FT);

void LiberarTurma(TurmaFila *FT);

#endif // TURMA_H__INCLUDED