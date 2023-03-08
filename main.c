#include "liste.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <curses.h>
#include <string.h>

int main(int argc, char const *argv[]) {

  punta_head* l = nuova_lista();

  int scelta = -1;
  int x;

  while(scelta != 0){
    printf("---------------------------\n");

    printf("Funzioni su Lista:\n");
    printf("\n [1]  -> Inserire in testa un valore");
    printf("\n [2]  -> Inserire in coda un valore");
    printf("\n [3]  -> Rimuovere dalla testa un valore");
    printf("\n [4]  -> Rimuovere dalla coda un valore");
    printf("\n [5]  -> Svuota lista");
    printf("\n [6]  -> Elimina un elemento a tua scelta dalla lista");
    printf("\n [7]  -> Verifica il massimo tra i valori in lista");
    printf("\n [8]  -> Verifica la somma dei valori inseriti");
    printf("\n [9]  -> Verifica se il numero inserito è all'interno della lista");
    printf("\n [10] -> Verifica il valore del numero precedente in lista a quello inserito");
    printf("\n [11] -> Visualizza la lista");
    printf("\n [12] -> Verifica se la lista è ordinata in ordine crescente");
    printf("\n [13] -> Verifica se il primo elemento è uguale all'ultimo");
    printf("\n [14] -> Verifica se esistono valori duplicati nella lista");
    printf("\n [15] -> Conta i nodi che hanno valore pari alla lunghezza della lista");
    printf("\n [16] -> Conta il numero di nodi con valore minore dei successivi adiacenti");
    printf("\n [0]  -> Esci dal programma lista\n\n");
    printf("\n\n-->  ");
    scanf("%d",&scelta);
    fflush(stdin);

    switch (scelta) {
      case 0:
        printf("\n\nA presto!\n\n");
        break;
      case 1:
        printf("\n\nInserire un valore in testa: ");
        printf("\n\n-->  ");
        scanf("%d",&x);
        caricamentoOperazioni();
        inserisci_in_testa(l, x);
        print_lista(l);
        break;
      case 2:
        printf("\n\nInserire un valore in coda: ");
        printf("\n\n-->  ");
        scanf("%d",&x);
        caricamentoOperazioni();
        inserisci_in_coda(l, x);
        print_lista(l);
        break;
      case 3:
        print_lista(l);
        printf("\n\nRimuovere dalla testa un valore: ");
        caricamentoOperazioni();
        rimuovi_in_testa(l);
        print_lista(l);
        break;
      case 4:
        print_lista(l);
        printf("\n\nRimuovere dalla coda un valore: ");
        caricamentoOperazioni();
        rimuovi_in_coda(l);
        print_lista(l);
        break;
      case 5:
        print_lista(l);
        printf("\n\nSvuota la lista: ");
        caricamentoOperazioni();
        svuota_lista(l);
        l = nuova_lista();
        break;
      case 6:
        print_lista(l);
        printf("\n\nInserire il valore da eliminare: \n");
        printf("\n\n-->  ");
        scanf("%d",&x);
        caricamentoOperazioni();
        elimina_elemento(l,x);
        print_lista(l);
        break;
      case 7:
        print_lista(l);
        printf("\n\nVerifica il valore massimo: ");
        caricamentoOperazioni();
        int max = massimo(l);
        printf("\n\nIl valore massimo è: %d\n\n",max);
        break;
      case 8:
        print_lista(l);
        printf("\n\nVerifica il valore somma: ");
        caricamentoOperazioni();
        int sum = somma(l);
        printf("\n\nLa somma dei valore è: %d\n\n",sum);
        break;
      case 9:
        print_lista(l);
        printf("\n\nInserire il numero da cercare: ");
        printf("\n\n-->  ");
        scanf("%d",&x);
        fflush(stdin);
        caricamentoOperazioni();
        int c = cerca(l,x);
        if(c){
          printf("\n\nIl valore [%d] è presente nella lista\n\n", x);
        }else{
          char string_scelta[3];
          const char* string_si = "si";
          const char* string_no = "no";
          printf("\n\nIl valore [%d] non è presente nella lista. Vuoi aggiungerlo?", x);
          printf("\nDigitare \"si\" per procedere con l'aggiunta in lista, altrimenti \"no\" -->  ");
          scanf("%s", string_scelta);
          int scelta_si_boole = !strncasecmp(string_scelta, string_si,3);
          int scelta_no_boole = !strncasecmp(string_scelta, string_no,3);

          if(scelta_si_boole){
            caricamentoOperazioni();
            inserisci_in_testa(l,x);
            printf("\n[%d] è stato inserito in testa alla lista!\n",x);
            print_lista(l);
          }else if((!scelta_no_boole) && (!scelta_si_boole)){
            printf("\n\nScelta non valida\n");
          }
        }
        break;
      case 10:
        print_lista(l);
        printf("\n\nInserire un numero presente in lista: ");
        printf("\n\n-->  ");
        scanf("%d",&x);
        caricamentoOperazioni();
        int pre = prev(l,x);
        if(pre!=-1){
          printf("\n\nIl valore in lista precedente a quello inserito è: %d\n\n", pre);
        }else{
          printf("\n\nIl valore inserito non è presente in lista\n\n");
        }
        print_lista(l);
        break;
      case 11:
        print_lista(l);
        break;
      case 12:
        print_lista(l);
        if(verifica_ord_crescente(l)){
          printf("\n\nLa lista è ordinata in ordine crescente\n\n");
        }
        else{
          printf("\n\nLa lista non è ordinata in ordine crescente\n\n");
        }
        break;
      case 13:
        print_lista(l);
        if(verifica_primo_uguale_ultimo(l)){
          printf("\n\nIl primo elemento nella lista è uguale all'ultimo\n\n");
        }else{
          printf("\n\nIl primo elemento nella lista non è uguale all'ultimo\n\n");
        }
        break;
      case 14:
        print_lista(l);
        if(verifica_duplicati(l)){
          printf("\n\nEsistono duplicati nella lista\n\n");
        }else{
          printf("\n\nNon esistono duplicati nella lista\n\n");
        }
        break;
      case 15:
        print_lista(l);
        int cont1 = conta_nodi_info_uguale_lunghezza(l);
        printf("\n\nI nodi con valore uguale alla lunghezza della lista sono: %d\n\n",cont1);
        break;
      case 16:
        print_lista(l);
        int cont2 = conta_minori_adiac_prec(l);
        printf("\n\nI nodi con valore minore ai nodi adiacenti successivi nella lista sono: %d\n\n", cont2);
        break;
      default:
        printf("\n\nIl valore inserito non è valido, inserire un numero del menù\n\n");
        break;
    }
  }

  if(l->head != NULL){
    free_lista(l);
  }

  return 0;
}
