#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct noArv { 
    int info;
    struct noArv* esq; 
    struct noArv* dir;
}NoArv;

NoArv *abb_cria(void){
    return NULL;
}

void abb_PreImprime (NoArv *a){
    if(a != NULL){
        printf("\n\n Esq:%p Info:%d (%p) Dir:%p", a->esq, a->info, a, a->dir);
        abb_PreImprime(a->esq);
        abb_PreImprime(a->dir);
    }
}

NoArv * abb_insere(NoArv *a, int v){
    if(a==NULL){
        a = (NoArv*)malloc(sizeof(NoArv));
        a->info = v;
        a->esq = a->dir = NULL;
    }else if (v < a->info) {
        a->esq = abb_insere(a->esq,v);
    }else if(v >a->info){
        a->dir = abb_insere(a->dir,v);
    }
    return a;
}

NoArv * abb_retira(NoArv *r, int v){
    if(r==NULL){
        return NULL;
    }else if(r->info > v){
        r->esq = abb_retira(r->esq, v);
    }else if(r->info < v){
        r->dir = abb_retira(r->dir, v);
    }else{
        if(r->esq == NULL && r->dir == NULL){
            free(r);
            r = NULL;
        }else if(r->esq == NULL){
            NoArv *t = r;
            r = r->dir;
            free(t);
        }else if(r->dir == NULL){
            NoArv *t = r;
            r = r->esq;
            free(t);
        }else{
            NoArv *f = r->esq;
            while(f->dir != NULL){
                f = f->dir;
            }
            r->info = f->info;
            f->info = v;
            r->esq = abb_retira(r->esq, v);
        }
    }
    return r;
}

int totalNo_abb(NoArv *raiz){
    int esq, dir;

    if(raiz == NULL)
        return 0;
    esq = totalNo_abb(raiz->esq);
    dir = totalNo_abb(raiz->dir);
    return (esq+dir+1);
}

int Altura_abb(NoArv *raiz){
    int esq, dir;
    if(raiz==NULL)
        return -1;
    esq = Altura_abb(raiz->esq);
    dir = Altura_abb(raiz->dir);
    if(esq > dir){
        return (esq +1);
    }else{
        return (dir +1);
    }
}

NoArv* abb_removeImpar(NoArv *r, NoArv *raiz){
    if(r != NULL){
        abb_removeImpar(r->esq, raiz);
        if(r->info % 2 != 0){
            printf("\nNum %d removido\n", r->info);
            raiz = abb_retira(raiz, r->info);
            abb_PreImprime(raiz);
        }
        abb_removeImpar(r->dir, raiz);
        return raiz;
    }
}

NoArv* abb_removePar(NoArv *r, NoArv *raiz){
    if(r != NULL){
        abb_removeImpar(r->esq, raiz);
        if(r->info % 2 == 0){
            printf("\nNum %d removido\n", r->info);
            raiz = abb_retira(raiz, r->info);
            abb_PreImprime(raiz);
        }
        abb_removePar(r->dir, raiz);
        return raiz;
    }
}

int main(){
    NoArv *raiz;
    raiz = abb_cria();
    int i, num = 1;
    do{
        printf("Digite o novo valor: (0 para sair)");
        scanf("%d", &num);
        if(num != 0)
            raiz = abb_insere(raiz, num);
    }while(num != 0);

    printf("\nArvore Inicial.\n");
    abb_PreImprime(raiz);

    num = totalNo_abb(raiz);
    printf("\n\nNumero total de nos na arvore: %d\n", num);
    printf("A altura da arvore eh: %d\n", Altura_abb(raiz));

    printf("\nDigite um valor para ser removido da arvore: \n");
    scanf("%d", &num);
    raiz = abb_retira(raiz,num);
    abb_PreImprime(raiz);

    return 0;
}