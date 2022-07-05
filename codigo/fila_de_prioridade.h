// fila_de_prioridade
typedef struct No{
    char *campus_livro;
    char *campus_aluno;
    char *responsavel;

    int prioridade;
    int pos;

    struct No * prox;
}NO;

NO * inicio = NULL;
NO * fim = NULL;
int tamanho_fila = 0;
int antigo;



void adicionar_fila (char *campus_livro, char *campus_aluno, char *responsavel, int prioridade, int pos) {
	if (pos >= 0 && pos <= tamanho_fila) {
		NO * novo = malloc(sizeof(NO));
        novo->campus_livro = campus_livro;
        novo->campus_aluno = campus_aluno;
        novo->responsavel = responsavel;
        novo->prioridade = prioridade;
        novo->pos = pos;
        novo->prox = NULL;

		if (inicio == NULL) {
			inicio = novo;
			fim = novo;
			tamanho_fila++;
		} else if (pos == 0) {
			novo -> prox = inicio;
			inicio = novo;
			tamanho_fila++;
		} else if (pos == tamanho_fila) {
			fim -> prox = novo;
			fim = novo;
			tamanho_fila++;
		} else {
			NO * aux = inicio;
			int i;
			for (i = 0; i <= pos -1; i++) {
				aux = aux -> prox;
			}
			novo -> prox = aux -> prox;
			aux -> prox = novo;
			tamanho_fila++;
		}
	}
	else {
		printf("Deu ruim!\n");
	}
}

void imprimir_fila () {
    NO * aux = inicio;
    for(int i = 0; i < tamanho_fila; i++){
        printf("Campus do livro: %s | Campus do aluno: %s | Responsável: %s | Prioridade: %d\n", aux->campus_livro,
        aux->campus_aluno,
        aux->responsavel,
        aux->prioridade);

        aux = aux->prox;
    }
}

int a;
void buscar () {
    a = 0;
    NO * aux = inicio;
    while (aux != NULL) {
        if (a<aux->prioridade) {
            a = aux->prioridade;
        }

        aux = aux ->prox;
    }

}

char *priori;
int posicao;
void associa_prioridade (int prioridade) {
    NO * aux = inicio;
    while (aux != NULL) {
        if (prioridade == aux->prioridade) {
            posicao = aux->pos;
            printf("\nA maior prioridade agora é: %s | %s | %s |%d\n", aux->campus_livro, aux->campus_aluno, aux->responsavel, a);

        }
        aux = aux ->prox;
    }
}



void remove_prioridade(int pos){

	int retorno;
	if (pos >= 0 && pos < tamanho_fila) {
		if (pos == 0) {
			NO * lixeira = inicio;
			if (tamanho_fila == 1) {
				inicio = NULL;
			} else {
				inicio = inicio -> prox;
			}
			free(lixeira);
			tamanho_fila--;
		} else {
			NO * aux = inicio;
			int i;
			for (i = 0; i < pos - 1; i++) {
				aux = aux -> prox;
			}
			NO * lixeira = aux -> prox;
			aux -> prox = lixeira -> prox;
			free(lixeira);
			tamanho_fila--;
		}

	}
}
