#include <stdio.h>
#include "../include/aluno.h"

#include <stdio.h>
#include "aluno.h"

int main(void) {
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

    printf("\nSaindo...");

    return 0;
}