// fase1 arvore
typedef struct Encomenda {
    char *nome;
    char *matricula;
    char *descricao;

     int id;

     struct Encomenda *dir;
     struct Encomenda * esq;
 } encomenda;

 encomenda * raiz = NULL;

 encomenda * buscar_arvore (char *nome, char *matricula, char *descricao, int x, encomenda * aux) {
     if (aux == NULL) {
         return NULL;
     } else if (x == aux -> id) {
         return aux;
     } else if (x < aux -> id){
         if (aux -> esq == NULL) {
             return aux;
         } else {
             return buscar_arvore(nome, matricula, descricao, x, aux -> esq);
         }
     } else {
         if (aux -> dir == NULL) {
             return aux;
         } else {
             return buscar_arvore(nome, matricula, descricao, x, aux -> dir);
         }
     }
 }

 void registro (char *nome, char *matricula, char *descricao, int x) {
     encomenda * aux = buscar_arvore(nome, matricula, descricao, x, raiz);
     if (aux != NULL && aux -> id == x) {
         printf("Insercao invalida\n");
     } else {
         encomenda * novo = malloc (sizeof(encomenda));
         novo -> nome = nome;
         novo -> matricula = matricula;
         novo -> descricao = descricao;
         novo -> id = x;
         novo-> esq = NULL;
         novo -> dir = NULL;

         if (aux == NULL) {
            raiz = novo;
         } else {
             if (x < aux -> id) {
                 aux -> esq = novo;
             } else {
                 aux -> dir = novo;
             }
         }
     }
 }


 void imprimir (encomenda * aux) {
     if (aux -> esq != NULL) {
         imprimir(aux -> esq);
     }

    printf("\nPedido cadastrado: \n\n");
    printf(" %s | %s | %s\n", aux->nome, aux->matricula, aux->descricao);
    printf("\n-------------------------\n");

     if (aux -> dir != NULL) {
        imprimir(aux -> dir);
     }
 }

 void visualizar (encomenda * aux) {

    if (aux -> esq != NULL) {
        visualizar(aux -> esq);
    }
    printf(" %s | %s | %s | %d \n", aux->nome, aux->matricula, aux->descricao, aux -> id);

    printf("\n____\n\n");

    if (aux -> dir != NULL) {
        visualizar(aux -> dir);
    }
 }

void encomendar () {
    char *nome;
    char *matricula;
    char *descricao;
    int num;

    printf("Digite o número de encomendas que deseja realizar:\n");
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        printf("Digite o nome do aluno: \n");
        char *nome = malloc(sizeof(char));
        scanf(" %[^\n]s", nome);
        printf("Digite a matricula do aluno: \n");
        char *matricula = malloc(sizeof(char));
        scanf(" %[^\n]s", matricula);
        printf("Digite a descrição do livro: \n");
        char *descricao = malloc(sizeof(char));
        scanf(" %[^\n]s", descricao);

        registro(nome, matricula, descricao, i);
    }
}
