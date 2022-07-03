#include "fase1.h"

encomenda *remover(encomenda *raiz, int chave){
    if(raiz == NULL){
        printf("Encomenda inexistente!\n");
        return NULL;
    }else{
       if(raiz->id == chave){

        if(raiz->esq == NULL && raiz->dir == NULL){

            printf("encomenda removida: %d!\n",chave);
            return NULL;
        }else{

           if(raiz->esq == NULL && raiz->dir == NULL){
                encomenda *aux = raiz->esq;
              while(aux->dir != NULL)
                raiz->id = aux->id;
                aux->id = chave;

                raiz->esq = remover(raiz->esq, chave);
                return raiz;

           }else{

             encomenda *aux;
             if(raiz->esq !=NULL)
                aux = raiz->esq;
             else
                aux = raiz->dir;
                free(raiz);
                printf("encomenda removida: %d!\n",chave);
                return aux;
           }
        }
       }else{
           if(chave < raiz->id)
            raiz->esq = remover(raiz->esq, chave);
             else
              raiz->dir = remover(raiz->dir, chave);


       }
    }
}

