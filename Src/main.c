#include <stdio.h>
#include "..\include\aluno.h"
#include "..\include\professor.h"
#include "..\include\disciplina.h"

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

    printf("\n---------- Aperte enter para seguir para o teste da entidade disciplina! ---------- \n");
    getchar();

// ---------- TESTE ENTIDADE DISCIPLINA ---------- //
{
    ArvoreDisciplina disciplinas;

    // {codigo, nome, cargaHoraria, periodo, {pre-requisitos}, qtdPreRequisitos}
    Disciplina d1 = {10, "Algoritmos", 60, 1, {0}, 0};
    Disciplina d2 = {20, "Estrutura de Dados", 60, 2, {10}, 1};
    Disciplina d3 = {30, "Projeto Final", 80, 3, {10, 20}, 2};

    inicializarArvore(&disciplinas);

    cadastrarDisciplina(&disciplinas, d2);
    cadastrarDisciplina(&disciplinas, d1);
    cadastrarDisciplina(&disciplinas, d3);

    printf("\nLista de Disciplinas:\n\n");
    listarDisciplinas(disciplinas.raiz);

    printf("\n");
    consultarPreRequisitos(&disciplinas, 30);
    consultarPreRequisitos(&disciplinas, 10);

    removerDisciplina(&disciplinas, 20);
    printf("\nDisciplina %s removida...\n\n", d2.nome);

    printf("Lista de Disciplinas:\n\n");
    listarDisciplinas(disciplinas.raiz);

    liberarArvore(disciplinas.raiz);
}
     printf("\n---------- Aperte enter para seguir para o teste da entidade turma! ---------- \n");
    getchar();

// ---------- TESTE ENTIDADE TURMA ---------- //
{
    TurmaFila turmas;
    // {codigo, codigoDisciplina, codigoProfessor, horario, sala, vagas}
    Turma t1 = {101, 10, 1067, 9.30, "C103", 30};
    Turma t2 = {105, 20, 1087, 14.30, "D205", 25};
    Turma t3 = {205, 30, 1067, 11.00, "E301", 20};
    Turma pesquisa, aux;
    
    FVaziaTurma(&turmas);

    CadastrarTurma(&turmas, t1);
    CadastrarTurma(&turmas, t2);
    CadastrarTurma(&turmas, t3);

    printf("\nLista de Turmas:\n\n");
    ListarTurma(turmas);

    pesquisa.cod = 105;
    if(PesquisarTurma(&turmas, pesquisa) == 1) {
        printf("\nTurma encontrada!\n");
    } else {
        printf("\nTurma não encontrada.\n");
    }
    RemoveTurma(&turmas, &aux);
    printf("\nTurma %d removida...\n\n", aux.cod);

    printf("Lista de Turmas:\n\n");
    ListarTurma(turmas);
     
    LiberarTurma(&turmas);
}

    printf("\nSaindo...");

    return 0;
}
