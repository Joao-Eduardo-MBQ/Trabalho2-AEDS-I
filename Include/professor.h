// PROFESSOR UTILIZARÁ LISTA

#ifndef PROFESSOR_H_INCLUDED
#define PROFESSOR_H_INCLUDED
#include "util.h"

typedef struct {
    int  matricula;
    char nome[TAM_NOME];
    char area[TAM_AREA];
    char email[TAM_EMAIL];
} Professor;

typedef struct {
    Professor dados;
    struct NoProfessor *prox;
} NoProfessor;

typedef struct {
    NoProfessor *inicio;
    NoProfessor *fim;     
    int tamanho;
} ListaProfessores;

void iniciarP(ListaProfessores *l);
int iniciarProfessor(Professor *p, int matricula, const char *nome, const char *area, const char *email);
int inserirP(ListaProfessores *l, Professor p);
int removerP(ListaProfessores *l, int matricula);
NoProfessor *buscarP(const ListaProfessores *l, int matricula);
void listarP(const ListaProfessores *l);
void liberarP(ListaProfessores *l);

#endif