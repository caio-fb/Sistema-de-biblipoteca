#include "fase1.h"

encomenda *remover(encomenda *raiz, int chave){
    if(raiz == NULL){
        printf("Encomenda inexistente!\n");
        return NULL;
    }else{
       if(raiz->id == chave){
        //remover no sem filhos
        if(raiz->esq == NULL && raiz->dir == NULL){
            //free(raiz);
            printf("encomenda removida: %d!\n",chave);
            return NULL;
        }else{
           //Remover no que possuem 2 filhos
           if(raiz->esq == NULL && raiz->dir == NULL){
                encomenda *aux = raiz->esq;
              while(aux->dir != NULL)
                raiz->id = aux->id;
                aux->id = chave;
                //printf("elemento trocado:%d ! \n", chave);
                raiz->esq = remover(raiz->esq, chave);
                return raiz;

           }else{
             //Remover nos que possuem 1 apenas um filho
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
            // return chave;

       }
    }
}

