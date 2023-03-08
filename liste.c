#include "liste.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <curses.h>

/* stampa la lista */
void print_lista(punta_head* l){
  if(l->head==NULL){
    printf("\n\nLa lista è vuota\n\n");
    return;
  }else
    printf("\nLISTA:");
    lista* i = l->head;
    while(i!=NULL){
      printf("[%d]", i->info);
      i = i->next;
    }
    printf("\n\n");
}

punta_head* nuova_lista(){
  punta_head* new_testa = (punta_head*)malloc(sizeof(punta_head));
  new_testa->head = NULL;
  return new_testa;
}

void inserisci_in_testa(punta_head* l, int v){
  lista* nuovaTesta = (lista*)malloc(sizeof(lista));

  nuovaTesta->info = v;
  nuovaTesta->next = l->head;
  l->head = nuovaTesta;
  printf("\nValore inserito!\n\n");
}

void inserisci_in_coda(punta_head* l, int v){
  if(l->head == NULL){
    inserisci_in_testa(l,v);
  }else{
    lista* i = l->head;
    while(i->next != NULL){
      i = i->next;
    }
    lista* nuovaCoda = (lista*)malloc(sizeof(lista));
    nuovaCoda->info = v;
    nuovaCoda->next = NULL;
    i->next = nuovaCoda;
    printf("\nValore inserito in coda!\n\n");
  }
}

void rimuovi_in_testa(punta_head* l){
  if(l->head == NULL){
    printf("\nLista vuota!\n\n");
    exit(1);
  }else{
    lista* testaTemp = l->head;
    l->head = l->head->next;
    free(testaTemp);
    printf("\nValore rimosso!\n\n");
  }
}

void rimuovi_in_coda(punta_head* l){
  if(l->head == NULL){
    printf("\nLista vuota!\n\n");
    exit(1);
  }else if(l->head->next == NULL){
    rimuovi_in_testa(l);
  }else{
    lista* nodoCoda = l->head;
    while(nodoCoda->next->next != NULL){
      nodoCoda = nodoCoda->next;
    }
    lista* temp = nodoCoda->next;
    nodoCoda->next = NULL;
    free(temp);
    printf("\nValore rimosso!\n\n");
  }
}

void free_lista(punta_head* l){
  free(l);
}

void svuota_lista(punta_head* l){
  if(l->head != NULL){
    free_lista(l);
    printf("\nLista svuotata con successo!\n\n");
  }else{
    printf("\nLista già vuota\n\n");
  }
}

void elimina_elemento(punta_head* l,int v){

  int trovato = cerca(l, v);

  if(l->head == NULL){
    printf("\nLa lista è vuota\n\n");
  }
  if(l->head->info == v){
    rimuovi_in_testa(l);
    return;
  }
  if(trovato){
    lista* i = l->head;
    while(i->next->info!=v){
      i = i->next;
    }
    lista* temp = i->next;
    i->next = i->next->next;
    free(temp);
  }else{
    printf("\nNon è stato trovato il valore inserito\n");
  }
}

int massimo(punta_head* l){
  if(l->head == NULL){
    printf("\nLista vuota!\n\n");
    exit(1);
  }else{
    int max = l->head->info;
    lista* nodo = l->head;
    while(nodo->next != NULL){
      if(nodo->info > nodo->next->info){
        max = nodo->info;
      }
      nodo = nodo->next;
    }
    return max;
  }
}

int somma(punta_head* l){
  if(l->head == NULL){
    printf("\nLista vuota!");
    exit(1);
  }else{
    int somma = 0;
    lista* nodo = l->head;
    while(nodo->next != NULL){
      somma += nodo->next->info;
      nodo = nodo->next;
    }
    return somma;
  }
}

int cerca(punta_head* l, int v){
  int trovato = 0;
  if(l->head!=NULL){
    lista* i = l->head;
    while((!trovato) && (i != NULL)){
      if(i->info == v){
        trovato = 1;
      }
      i = i->next;
    }
  }else{
    printf("\nLista vuota\n\n");
  }
  return trovato;
}

int prev(punta_head* l, int x){

  int valore = -1;
  if(l->head != NULL) {
    lista* i = l->head;
    while(valore == -1 && i->next != NULL){
      if(i->next->info == x){
        valore = i->info;
      }
      i = i->next;
    }
  }else{
    printf("\nLista vuota\n\n");
  }
  return valore;
}

int verifica_ord_crescente(punta_head* l){
  
  if(l->head == NULL){
    printf("\nLista vuota!");
    exit(1);
  }else{
    lista* i = l->head;
    while(i->next != NULL){
      if(i->info > i->next->info){
        return 0;
      }
      i = i->next;
    }
    return 1;
  }
}

int verifica_primo_uguale_ultimo(punta_head* l){

  if(l->head == NULL){
    printf("\nLista vuota!\n\n");
    exit(1);
  }else{
    lista* i = l->head;
    while(i->next != NULL){
      i = i->next;
    }

    return (l->head->info == i->info);
  }
}

int verifica_duplicati(punta_head* l){
  if(l->head == NULL){
    printf("\nLista vuota!\n\n");
    exit(1);
  }else{
    lista* i = l->head;
    while(i->next != NULL){
      if(i->info == i->next->info){
        return 1;
      }
      i = i->next;
    }
    return 0;
  }
}

int conta_nodi_info_uguale_lunghezza(punta_head* l){
  if(l->head == NULL){
    printf("\nLista vuota!\n\n");
    exit(0);
  }else{
    int cont = 0;
    int lunghezza_lista = 0;
    lista* i = l->head;

    while(i != NULL){
      lunghezza_lista++;
      i = i->next;
    }

    lista* j = l->head;
    while(j != NULL){
      if(j->info == lunghezza_lista){
        cont++;
      }
      j = j->next;
    }
    return cont;
  }
}

int conta_minori_adiac_prec(punta_head* l){
  if(l->head == NULL){
    printf("\nLa lista è vuota\n\n");
    exit(0);
  }else{
    int cont = 0;
    lista* i = l->head;

    while(i->next != NULL){
      if(i->info < i->next->info){
        cont++;
      }
      i = i->next;
    }
    return cont;
  }
}

/* --------------------------------------------------------------- */

void caricamentoOperazioni(){

  printf("\nCaricamento in corso: ");
  printf("\n");
  for(int i=0; i<=100; i++){
    printf("\r[ %d%% ]",i);
    fflush(stdout);   //
    usleep(10000);
  }
  printf("\n\n");
}
