// fila_de_prioridade
typedef struct No{
    char *campus_livro;
    char *campus_aluno;
    char *responsavel;

    int prioridade;
    int pos;

    struct No * prox;
    struct No * ant;
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

		if (inicio == NULL) {	// lista vazia
			inicio = novo;
			fim = novo;
			tamanho_fila++;
		} else if (pos == 0) {	// início da lista
			novo -> prox = inicio;
			inicio = novo;
			tamanho_fila++;
		} else if (pos == tamanho_fila) {	// fim da lista
			fim -> prox = novo;		// tam aumenta por conta da lista vazia ou do início dela, por isso a posição sendo diferente de NULL ou de 0 será igual a tam
			fim = novo;
			tamanho_fila++;
		} else {	// meio da lista
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
	else {	// erro
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

/*
int antigo = 0;
void adicionar_fila(char *campus_livro, char *campus_aluno, char *responsavel, int prioridade) {

        NO * novo = malloc(sizeof(NO));
        novo->campus_livro = campus_livro;
        novo->campus_aluno = campus_aluno;
        novo->responsavel = responsavel;
        novo->prioridade = prioridade;
        novo->prox = NULL;

        if(inicio == NULL){ //fila vazia
            inicio = novo;
            fim = novo;
            tamanho_fila++;
        } else if (antigo < prioridade) {
            NO *aux = inicio;
            while(aux != NULL) {
                if (prioridade > aux->prioridade){
                    novo -> prox = aux -> prox;
                    aux -> prox = novo;
                }
                aux = aux -> prox;
            }
        }
        else{ //adiciona no antigo "fim" da lista
            fim->prox = novo;
            fim = novo;
            tamanho_fila++;
        }
        antigo = novo->prioridade;
}*/




char *priori;
int posicao;
void associa_prioridade (int prioridade) {  // associa o nome ao cpf
    NO * aux = inicio;
    while (aux != NULL) {
        if (prioridade == aux->prioridade) {
            posicao = aux->pos;
            remove_prioridade(posicao);
        }
        aux = aux ->prox;
    }
}

int a;
void buscar () {
    NO * aux = inicio;
    printf("\ndento\n");
    while (aux != NULL) {
        if (a<aux->prioridade) {
            a = aux->prioridade;
            printf("\nfoi\n");
        }
        aux = aux ->prox;
    }
    printf("\nA maior prioridade agora é: %s | %s | %s |%d", aux->campus_livro, aux->campus_aluno, aux->responsavel, a);
}

void remove_prioridade(int pos){

	int retorno;
	if (pos >= 0 && pos < tamanho_fila) {
		if (pos == 0) {	// remover no inicio
			NO * lixeira = inicio;
			if (tamanho_fila == 1) {	// caso o nó na lista seja único
				inicio = NULL;
			} else {	// caso tenha mais de um nó na lista
				inicio = inicio -> prox;
			}
			free(lixeira);
			tamanho_fila--;
		} else {	// remover no meio ou no fim
			NO * aux = inicio;
			int i;
			for (i = 0; i < pos - 1; i++) {	// caminhada de nó em nó
				aux = aux -> prox;	// aux aponta a cada volta do laço para o próximo nó
			}
			NO * lixeira = aux -> prox;
			aux -> prox = lixeira -> prox;
			free(lixeira);
			tamanho_fila--;
		}

	}
}
