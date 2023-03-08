#ifndef _LISTE_H
#define _LISTE_H

// typedef struct ldc{
//   int info_dc;
//   struct ldc* prev_dc;
//   struct ldc* next_dc;
// }lista_dc;
//
// typedef struct punta_lista_dc{
//   lista_dc* head_dc;
// }punta_head_dc;

typedef struct l{
  int info;
  struct l* next;
}lista;

typedef struct punta_lista{
  lista* head;
}punta_head;

punta_head* nuova_lista();
void inserisci_in_testa(punta_head* l, int v);
void inserisci_in_coda(punta_head* l, int v);
void rimuovi_in_testa(punta_head* l);
void rimuovi_in_coda(punta_head* l);
void svuota_lista(punta_head* l);
void elimina_elemento(punta_head* l,int v);
void print_lista(punta_head* l);
int prev(punta_head* l, int x);
int massimo(punta_head* l);
int somma(punta_head* l);
void free_lista(punta_head* l);
int cerca(punta_head* l, int v);
int verifica_ord_crescente(punta_head* l);
int verifica_primo_uguale_ultimo(punta_head* l);
int verifica_duplicati(punta_head* l);
int conta_nodi_info_uguale_lunghezza(punta_head* l);
int conta_minori_adiac_prec(punta_head* l);

/* ---------------------- */
void caricamentoOperazioni();

#endif
