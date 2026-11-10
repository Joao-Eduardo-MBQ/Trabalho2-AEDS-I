// MATRICULA UTILIZARA PILHA

#ifndef MATRICULA_H_INCLUDED
#define MATRICULA_H_INCLUDED
#include "util.h"

typedef struct {
    int   matriculaAluno;            // referencia ao Aluno
    int   codTurma;                  // referencia a Turma
    char  semestre[TAM_PERIODO];     // ex.: "2025.2"
    float nota;
    float frequencia;                // percentual (0 a 100)
    char  situacao[TAM_SITUACAO];    // calculada a partir de nota e frequencia
} Matricula;

typedef struct MatCelula {
    Matricula item;
    struct MatCelula *prox;
} MatCelula;

typedef struct {
    MatCelula *pFundo;
    MatCelula *pTopo;
} PilhaMatricula;

void FPVaziaMatricula(PilhaMatricula *p);
int  PVaziaMatricula(PilhaMatricula *p);
int  iniciarMatricula(Matricula *m, int matriculaAluno, int codTurma, const char *semestre, float nota, float frequencia);
int  InserirMatricula(PilhaMatricula *p, Matricula *m);
int  RemoverMatricula(PilhaMatricula *p, Matricula *m);
int  BuscarMatricula(PilhaMatricula *p, int matriculaAluno, int codTurma, Matricula *encontrada);
void ListarMatricula(PilhaMatricula *p);
void LiberarMatricula(PilhaMatricula *p);

#endif // MATRICULA_H_INCLUDED
