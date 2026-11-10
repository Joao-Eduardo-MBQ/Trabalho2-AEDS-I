#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matricula.h"

#define NOTA_MINIMA 6.0f
#define FREQ_MINIMA 75.0f

void FPVaziaMatricula(PilhaMatricula *p) {
    p->pTopo = (MatCelula *) malloc(sizeof(MatCelula));
    p->pFundo = p->pTopo;
    p->pTopo->prox = NULL;
}

int PVaziaMatricula(PilhaMatricula *p) {
    return (p->pTopo == p->pFundo);
}

static void calcularSituacao(Matricula *m) {
    const char *s;
    if (m->frequencia < FREQ_MINIMA)
        s = "Reprovado por falta";
    else if (m->nota < NOTA_MINIMA)
        s = "Reprovado por nota";
    else
        s = "Aprovado";
    strncpy(m->situacao, s, TAM_SITUACAO - 1);
    m->situacao[TAM_SITUACAO - 1] = '\0';
}

int iniciarMatricula(Matricula *m, int matriculaAluno, int codTurma, const char *semestre, float nota, float frequencia) {
    memset(m, 0, sizeof(*m));
    m->matriculaAluno = matriculaAluno;
    m->codTurma = codTurma;
    strncpy(m->semestre, semestre, TAM_PERIODO - 1);
    m->semestre[TAM_PERIODO - 1] = '\0';
    m->nota = nota;
    m->frequencia = frequencia;
    calcularSituacao(m);
    return 1;
}

// Inserir = empilhar (entra no topo)
int InserirMatricula(PilhaMatricula *p, Matricula *m) {
    MatCelula *novo = (MatCelula *) malloc(sizeof(MatCelula));
    if (novo == NULL) {
        return 0;
    }
    novo->item = *m;
    novo->prox = p->pTopo;
    p->pTopo = novo;
    return 1;
}

// Remover = desempilhar (sai do topo); devolve o item removido em *m
int RemoverMatricula(PilhaMatricula *p, Matricula *m) {
    MatCelula *aux;
    if (PVaziaMatricula(p)) {
        return 0;
    }
    aux = p->pTopo;
    *m = aux->item;
    p->pTopo = aux->prox;
    free(aux);
    return 1;
}

// Busca do topo ate o fundo, sem alterar a pilha
int BuscarMatricula(PilhaMatricula *p, int matriculaAluno, int codTurma, Matricula *encontrada) {
    MatCelula *aux = p->pTopo;
    while (aux != p->pFundo) {
        if (aux->item.matriculaAluno == matriculaAluno && aux->item.codTurma == codTurma) {
            if (encontrada != NULL) {
                *encontrada = aux->item;
            }
            return 1;
        }
        aux = aux->prox;
    }
    return 0;
}

static void imprimirMatricula(const Matricula *m) {
    printf("Aluno (matricula): %d\n", m->matriculaAluno);
    printf("Turma (codigo): %d\n", m->codTurma);
    printf("Semestre: %s\n", m->semestre);
    printf("Nota: %.1f\n", m->nota);
    printf("Frequencia: %.1f%%\n", m->frequencia);
    printf("Situacao: %s\n", m->situacao);
}

void ListarMatricula(PilhaMatricula *p) {
    MatCelula *aux;
    if (PVaziaMatricula(p)) {
        printf("Pilha de matriculas vazia!\n");
        return;
    }
    printf("Matriculas (topo para o fundo):\n");
    aux = p->pTopo;
    while (aux != p->pFundo) {
        imprimirMatricula(&aux->item);
        printf("------------------------\n");
        aux = aux->prox;
    }
}

void LiberarMatricula(PilhaMatricula *p) {
    Matricula item;
    while (!PVaziaMatricula(p)) {
        RemoverMatricula(p, &item);
    }
    free(p->pFundo);
    p->pTopo = NULL;
    p->pFundo = NULL;
}
