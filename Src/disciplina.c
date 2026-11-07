#include <stdio.h>
#include <stdlib.h>
#include "disciplina.h"

void inicializarArvore(ArvoreDisciplina *arvore) {
    arvore->raiz = NULL;
}

static No *inserir(No *no, No *pai, Disciplina d) {
    if (no == NULL) {
        No *novo = malloc(sizeof(No));
        novo->dados = d;
        novo->pai = pai;
        novo->esquerda = NULL;
        novo->direita = NULL;
        return novo;
    }
    if (d.codigo < no->dados.codigo)
        no->esquerda = inserir(no->esquerda, no, d);
    else
        no->direita = inserir(no->direita, no, d);
    return no;
}

void cadastrarDisciplina(ArvoreDisciplina *arvore, Disciplina disciplina) {
    arvore->raiz = inserir(arvore->raiz, NULL, disciplina);
}

No *consultarDisciplina(ArvoreDisciplina *arvore, int codigo) {
    No *atual = arvore->raiz;
    while (atual != NULL) {
        if (codigo == atual->dados.codigo)
            return atual;
        if (codigo < atual->dados.codigo)
            atual = atual->esquerda;
        else
            atual = atual->direita;
    }
    return NULL;
}

void consultarPreRequisitos(ArvoreDisciplina *arvore, int codigo) {
    No *no = consultarDisciplina(arvore, codigo);
    if (no == NULL) {
        printf("Disciplina nao encontrada.\n");
        return;
    }

    if (no->dados.qtdPreRequisitos == 0) {
        printf("%s nao tem pre-requisitos.\n", no->dados.nome);
        return;
    }

    printf("Pre-requisitos de %s: ", no->dados.nome);

    for (int i = 0; i < no->dados.qtdPreRequisitos; i++) {
        printf("%d ", no->dados.preRequisitos[i]);
    }

    printf("\n");
}

void listarDisciplinas(No *raiz) {
    if (raiz == NULL) return;
    listarDisciplinas(raiz->esquerda);
    printf("%d - %s - %dh - periodo %d\n", raiz->dados.codigo, raiz->dados.nome, raiz->dados.cargaHoraria, raiz->dados.periodo);
    listarDisciplinas(raiz->direita);
}

static No *remover(No *no, int codigo, No *pai) {

    if (no == NULL){
        printf("Disciplina não encontrada!");
        return NULL;
    }

    if (codigo < no->dados.codigo) {
        no->esquerda = remover(no->esquerda, codigo, no);
    } else if (codigo > no->dados.codigo) {
        no->direita = remover(no->direita, codigo, no);
    } else {

        if (no->esquerda == NULL) {
            No *filho = no->direita;
            if (filho != NULL) filho->pai = pai;
            free(no);
            return filho;
        }

        if (no->direita == NULL) {
            No *filho = no->esquerda;
            filho->pai = pai;
            free(no);
            return filho;
        }

        No *menor = no->direita;
        while (menor->esquerda != NULL)
            menor = menor->esquerda;
        no->dados = menor->dados;
        no->direita = remover(no->direita, menor->dados.codigo, no);
    }
    return no;
}

void removerDisciplina(ArvoreDisciplina *arvore, int codigo) {
    arvore->raiz = remover(arvore->raiz, codigo, NULL);
}

void liberarArvore(No *raiz) {
    if (raiz == NULL) return;
    liberarArvore(raiz->esquerda);
    liberarArvore(raiz->direita);
    free(raiz);
}