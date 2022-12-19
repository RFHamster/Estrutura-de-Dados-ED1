#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int dados;
    char nome [30]; 
    struct no *anterior;
    struct no *proximo;
}noptr;

void insere_lista(noptr **inifunc, noptr *novo, int valor){
    novo->dados=valor;
    novo->anterior=NULL;

    if(*inifunc==NULL)
       novo->proximo = NULL;
    else{
       novo->proximo=*inifunc;
       (*inifunc)->anterior=novo;
    }
    *inifunc=novo;
}

void remove_lista(noptr **inifunc){
    noptr *p;

    if(*inifunc==NULL){
       printf("\nLista Vazia!!!");
       return;
    }else{
       p=*inifunc;
       printf("\nValor Removido: %d",p->dados);
       *inifunc=p->proximo;
       (*inifunc)->anterior=NULL;
       free(p);
    }
}

void lista_todos(noptr *inifunc){
  if(inifunc==NULL){
     printf("\nLista Vazia!!!");
     return;
  }
  noptr *p;
  p = inifunc;
  while(p){
      printf("\nSaida: %d", p->dados);
      p = p->proximo;
  }
  printf("\n");
}

void insere_ordenado(noptr **inifunc, noptr *novo, int valor)
{
    noptr *p, *ant;


    novo->dados=valor;
    printf("\n Digite um nome a ser pesquisado: ");
    setbuf(stdin, NULL);
    fgets(novo->nome,29,stdin);
    novo->anterior=NULL;

    if(*inifunc==NULL){
       novo->proximo = NULL;
       *inifunc=novo;
       return;
    }

    p=*inifunc;

    while(p != NULL && p->dados <= valor){
       ant = p;
       p=p->proximo;
    }

    if (p == *inifunc)
    {
      novo->proximo=*inifunc;
      (*inifunc)->anterior=novo;
      *inifunc=novo;
    }
    else{
    ant->proximo = novo;
    novo->anterior = ant;
    novo->proximo = p;
    if (p)
      p->anterior = novo;
    }

}

void remove_inicio(noptr **inifunc)
{
    noptr *p;

    if(*inifunc==NULL)
    {
       printf("\nLista Vazia!!!");
       return;
    }
    else
    {
       p=*inifunc;
       printf("\nValor Removido: %d",p->dados);
       *inifunc=p->proximo;
       (*inifunc)->anterior=NULL;
       free(p);
    }
}

void invertelista(noptr *lista)
{
    noptr *p;

    p = lista;
    while(p->proximo != NULL)
        p = p->proximo;
    while(p != NULL){
        printf("%d ", p->dados);
        p = p->anterior;
    }
        
}


void main(){
  int recebe=1;
  char aux [30];

  noptr *inicio;
  inicio=NULL;
  noptr *info;

  while(recebe!=0){
    info=(struct no *) malloc(sizeof(noptr));
     if(!info){
       printf("\nSem Memoria!!!");
       return;
     }
     printf("Digite um valor: ");
     scanf("%d",&recebe);
     if(recebe!=0)
       insere_ordenado(&inicio,info,recebe);
  }
  invertelista(inicio);

} 
