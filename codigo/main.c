// main.c -- menu
// chamando bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
// chamando os outros arquivos
#include "remocao_encomenda.h"
#include "fila_de_prioridade.h"
#include "login_secretario.h"

// executando as funções dos outros arquivos
int main () {
    setlocale (LC_ALL, "portuguese");
    logar("Carlos", 34567, 1234, "secretario", 0);
    logar("Flávia", 53636, 1243, "secretario", 1);
    logar("Lúcia", 76413, 4321, "secretario", 2);
    //----- transportadores
    logar("Rogério", 12345, 1234, "transportador", 3);
    logar("Jéssica", 79323, 1243, "transportador", 4);
    logar("Anna", 56812, 4321, "transportador", 5);
    logar("Cleber", 35467, 1243, "transportador", 6);
    logar("Valdemir", 54623, 4321, "transportador", 7);

    int resp = -1;
    while(resp != 0){
        printf(" Encomendar um livro [1]\n");
        printf(" Remover uma encomenda de livro [2]\n");
        printf(" Remover um pedido de livro [3]\n");
        printf(" Sair do sistema [0]\n");
        printf("\nDigite a funcionalidade desejada:\n");
        scanf("%d", &resp);

        if (resp == 1) {
            encomendar();
            imprimir(raiz);
        }
        else if (resp == 2) {
            printf("Acesso Permitido somente a secretários\n");
            printf("Por favor se identifique!\n");
            printf("Digite seu cpf:\n");
            int cpf;
            scanf("%d", &cpf);
            //-----------------------------
            printf("Digite sua senha:\n");
            int senha;
            scanf("%d", &senha);
            //------------------------------
            valida(cpf, senha);
            if (bool == 1) {
                printf("\n----Encomendas Cadastradas----\n\n");
                visualizar(raiz);
                //--------------------
                printf("Digite o id do pedido que deseja remover:\n");
                int id_removido;
                scanf("%d", &id_removido);
                remover(raiz, id_removido);
                visualizar(raiz);
                printf("Digite o campus do livro: \n");
                char *campus_livro = malloc(sizeof(char));
                scanf(" %[^\n]s", campus_livro);
                printf("Digite ao campus do aluno: \n");
                char *campus_aluno = malloc(sizeof(char));
                scanf(" %[^\n]s", campus_aluno);
                printf("Digite a prioridade:\n");
                int prioridade;
                scanf("%d", &prioridade);
                associa(cpf);  // vai chamar a função que diz o nome do responsável de acordo com o cpf
                adicionar_fila(campus_livro, campus_aluno, responsavel, prioridade, 0);
                imprimir_fila();
            }
            else {
                printf("Por favor insira credencias válidas!!\n");
            }

        } else if (resp == 3) {
            printf("Acesso Permitido somente a transportadores\n");
            printf("Por favor se identifique!\n");
            printf("Digite seu cpf:\n");
            int cpf_t;
            scanf("%d", &cpf_t);
            //-----------------------------
            printf("Digite sua senha:\n");
            int senha_t;
            scanf("%d", &senha_t);
            //------------------------------
            valida(cpf_t, senha_t);
            if (bool == 1) {
                int remove;
                buscar();
                printf("Digite '1' para remover e '0' para cancelar\n");

                scanf("%d", &remove);
                if (remove == 1) {
                    associa_prioridade (a);
                    printf("Removido"\n);
                }
                else if (remove == 0) {
                    printf("Remocao cancelada!\n");
                }
            }
            else {
                printf("Por favor insira credencias válidas!!\n");
            }
        }

        else if (resp == 0) {
            break;
        }

        else {
            printf("Por favor digite uma opção válida!\n");
        }
    }
    return 0;
}
