#ifndef DISCIPLINA_H
#define DISCIPLINA_H
#include "util.h"

typedef struct {
    int codigo;
    char nome[TAM_NOME];
    int cargaHoraria;
    int periodo;
    int preRequisitos[MAX_PREREQ];
    int qtdPreRequisitos;  
} Disciplina;

typedef struct No {
    Disciplina dados;

    struct No *pai;
    struct No *esquerda;
    struct No *direita;

} No;

typedef struct {
    No *raiz;
} ArvoreDisciplina;

static No *criarNo(Disciplina d);

void inicializarArvore(ArvoreDisciplina *arvore);

void cadastrarDisciplina(ArvoreDisciplina *arvore, Disciplina disciplina);

No *consultarDisciplina(ArvoreDisciplina *arvore, int codigo);

void consultarPreRequisitos(ArvoreDisciplina *arvore, int codigo);

void listarDisciplinas(No *raiz);

void removerDisciplina(ArvoreDisciplina *arvore, int codigo);

void liberarArvore(No *raiz);

#endif