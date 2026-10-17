#include <stdio.h>
#include "aluno.h"
#include "professor.h"

int main(void) {

// ---------- TESTE ENTIDADE ALUNO ---------- //
{
    VetorAlunos alunos;
    Aluno a1, a2;

    int   mat1 = 2528021, mat2 = 2419052;
    char *nome1 = "Dario Argento", *nome2 = "Agnes Varda";
    char *curso1 = "Engenharia de Computacao", *curso2 = "Sistema de Informacao";
    char *periodo1 = "2025.2", *periodo2 = "2024.1";
    char *email1 = "dario.argento@gmail.com", *email2 = "agnes.varda@gmail.com";

    iniciarA(&alunos);

    iniciarAluno(&a1, mat1, nome1, curso1, periodo1, email1);
    inserirA(&alunos, a1);

    iniciarAluno(&a2, mat2, nome2, curso2, periodo2, email2);
    inserirA(&alunos, a2);

    printf("Lista de Alunos:\n\n");
    listarA(&alunos);

    removerA(&alunos, mat2);
    printf("\nAluno %s removido...\n\n", nome2);

    printf("Lista de Alunos:\n\n");
    listarA(&alunos);
}

    printf("\n---------- Aperte enter para seguir para o teste da entidade professor! ---------- \n");
    getchar();

// ---------- TESTE ENTIDADE PROFESSOR ---------- //
{
    ListaProfessores professores;
    Professor p1, p2;

    int   mat1 = 1067, mat2 = 1087;
    char *nome1 = "Andrei Tarkovsky", *nome2 = "Ingmar Bergman";
    char *area1 = "Estrutura de Dados", *area2 = "Banco de Dados";
    char *email1 = "andrei.tarkovsky@gmail.com", *email2 = "ingmar.bergman@gmail.com";

    iniciarP(&professores);

    iniciarProfessor(&p1, mat1, nome1, area1, email1);
    inserirP(&professores, p1);

    iniciarProfessor(&p2, mat2, nome2, area2, email2);
    inserirP(&professores, p2);

    printf("\nLista de Professores:\n\n");
    listarP(&professores);

    removerP(&professores, mat2);
    printf("\nProfessor %s removido...\n\n", nome2);

    printf("Lista de Professores:\n\n");
    listarP(&professores);

    liberarP(&professores);
}

    printf("\nSaindo...");

    return 0;
}