// login_secretario.h
typedef struct LOGIN {
    char *nome;
    int cpf;
    int senha;
    char *tipo;
    int id_sec;

    int cpf_v;
    int senha_v;

    struct LOGIN * prox;
} LOGIN;

LOGIN * principio = NULL;
int tam = 0;

void logar (char *nome, int cpf, int senha, char *tipo, int id_sec) {
    if (id_sec >= 0 && id_sec <= tam) {
        LOGIN * novo_sec = malloc(sizeof(LOGIN));
        novo_sec -> nome = nome;
        novo_sec -> cpf = cpf;
        novo_sec -> senha = senha;
        novo_sec -> tipo = tipo;
        novo_sec -> id_sec = id_sec;
        novo_sec -> prox = NULL;

        if (principio == NULL) {   // lista vazia
            principio = novo_sec;

        } else if (id_sec == 0) {  // inicio da lista
            novo_sec -> prox = principio;
            principio = novo_sec;

        } else {    // meio da lista ou fim
            LOGIN * aux = principio;
            for (int i = 0; i < id_sec -1; i++) {
                aux = aux -> prox;
            }

            novo_sec -> prox = aux -> prox;
            aux -> prox = novo_sec;
        }
        tam++;
    }
}
int bool;
void valida (int cpf_v, int senha_v) {
    bool = 0;
    LOGIN * aux = principio;

    while (aux != NULL) {
        if (cpf_v == aux->cpf && senha_v == aux->senha) {
            bool = 1;
            break;
        }
        aux = aux ->prox;
    }
}

char *responsavel;
void associa (int cpf_v) {  // associa o nome ao cpf
    LOGIN * aux = principio;
    while (aux != NULL) {
        if (cpf_v == aux->cpf) {
            responsavel = aux->nome;
        }
        aux = aux ->prox;
    }
}
