#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_VAR 100
#define MAX_LUNG 5
//------------------------------------------------------STRUTTURE LISTE---------------------------------------------------------
//inzializzazione struttura della lista 
typedef struct lista{
	int info ;
	struct lista* next;				//puntatore all'elemento successivo della lista
}Lista;
typedef Lista* plist;			//puntatore alla lista
//------------------------------------------------------------------------------------------------------------------------------

//----------------------------------------------FUNZIONE CHE COSTURISCE LE LISTE------------------------------------------------
plist costruisci_lista_dinamica(){
    plist p = NULL;

    int lung;

    srand(time(NULL));
    for(int i = 0; i<MAX_LUNG; i++){
        lung = (rand() % 10)+1;
    }

    int L[lung];

    srand(time(NULL));
    for(int i = 0; i<lung; i++){
        L[i] = (rand() % 100)+1;
    }

    for(int i = 0; i < lung; i++ ) {
        plist temp = (plist)malloc(sizeof(Lista*));
        temp->info = L[i];
        temp->next = p;
        p = temp;
    }
    return p;
}

plist costruisci_lista_statica_1(){
    plist p = NULL;

    int L[]={9,7,1,9,1};

    for(int i = 0; i < 5; i++) {
        plist temp = (plist)malloc(sizeof(Lista*));
        temp->info = L[i];
        temp->next = p;
        p = temp;
    }
    return p;

}

plist costruisci_lista_statica_2(){
    plist p = NULL;

    int L[]={0,2,78,93,11};

    for(int i = 0; i < 5; i++) {
        plist temp = (plist)malloc(sizeof(Lista*));
        temp->info = L[i];
        temp->next = p;
        p = temp;
    }
    return p;

}

//-------------------------------------------------------------------------------
void print_lista(plist l);
int prev(plist l, int x);
int massimo(plist l);
int somma(plist l);
void free_lista(plist l);
int cerca(plist l, int v);
int verifica_ord_crescente(plist l);
int verifica_primo_uguale_ultimo(plist l);
int verifica_duplicati(plist l);
int verifica_duplicati_gen(plist l);
int verifica_info_uguale_lunghezza(plist p);
int conta_nodi_info_uguale_lunghezza(plist p);
int conta_minori_adiac_prec(plist l);
int comuni(plist p1, plist p2);
int lunghezza(plist p);
//-------------------------------------------------------------------------------

int main(int argc, char const *argv[]) {

  plist l = costruisci_lista_dinamica();
  plist ll = costruisci_lista_dinamica();
  plist ls = costruisci_lista_statica_1();
  plist ls2 = costruisci_lista_statica_2();

  int scelta = -1;
  int x;

  while(scelta != 0){
    printf("---------------------------\n");
    print_lista(l);
    printf("---------------------------\n");

    printf("Funzioni su Lista:\n");
    printf("\n [2]  -> Verifica che esistono due nodi con lo stesso campo info anche non consecutivi");
    printf("\n [3]  -> Calcola la lunghezza della lista");
    printf("\n [4]  -> Conta gli elementi nella prima lista che sono presenti nella seconda : l1 = {1, 2, 1} | l2 = {1} -> 2 ");
    printf("\n [6]  -> Verifica se esiste un nodo pari alla lunghezza della lista");
    printf("\n [7]  -> Verifica il massimo tra i valori in lista");
    printf("\n [8]  -> Verifica la somma dei valori inseriti");
    printf("\n [9]  -> Verifica se il numero inserito è all'interno della lista");
    printf("\n [10] -> Verifica il valore del numero precedente in lista a quello inserito");
    printf("\n [11] -> Visualizza la lista");
    printf("\n [12] -> Verifica se la lista è ordinata in ordine crescente");
    printf("\n [13] -> Verifica se il primo elemento è uguale all'ultimo");
    printf("\n [14] -> Verifica se esistono valori duplicati consecutivi nella lista");
    printf("\n [15] -> Conta i nodi che hanno valore pari alla lunghezza della lista");
    printf("\n [16] -> Conta il numero di nodi con valore minore dei successivi adiacenti");
    printf("\n [17] -> Verifica se l'ultimo elemento della lista è maggiore al primo");
    printf("\n [0]  -> Esci dal programma lista\n\n");
    printf("\n\n-->  ");
    scanf("%d",&scelta);
    fflush(stdin);

    switch (scelta) {
      case 0:
        printf("\n\nA presto!\n\n");
        break;
      case 2:
        print_lista(ls);
        if(verifica_duplicati_gen(ls)){
          printf("\n\nEsistono due nodi con campo info uguale anche non consecutivi\n\n");
        }
        else{
          printf("\n\nNon esistono due nodi con campo info uguale anche non consecutivi\n\n");
        }
        break;
      case 3:
        print_lista(l);
        int lung = lunghezza(l);
        printf("\n\n La lunghezza della lista é %d\n\n",lung+1);
        break;
      case 4:
        print_lista(ls);
        printf("\n--------------------------\n");
        print_lista(ls2);
        int cont = comuni(ls, ls2);
        printf("\n\nIl numero di elementi nella prima lista presenti nella seconda é: %d", cont);
        break;
      case 6:
        print_lista(ls);
        printf("\n\nVerifica se esiste un nodo pari alla lunghezza della lista\n\n");
        if(verifica_info_uguale_lunghezza(ls)){
          printf("\n\nEsiste un nodo con campo info pari alla lunghezza della lista\n\n");
        }else{

          printf("\n\nNon esiste un nodo con campo info pari alla lunghezza della lista\n\n");
        }
        break;
      case 7:
        print_lista(l);
        printf("\n\nVerifica il valore massimo: ");
        int max = massimo(l);
        printf("\n\nIl valore massimo è: %d\n\n",max);
        break;
      case 8:
        print_lista(l);
        printf("\n\nVerifica il valore somma: ");
        int sum = somma(l);
        printf("\n\nLa somma dei valore è: %d\n\n",sum);
        break;
      case 9:
        print_lista(l);
        printf("\n\nInserire il numero da cercare: ");
        printf("\n\n-->  ");
        scanf("%d",&x);
        fflush(stdin);
        int c = cerca(l,x);
        if(c){
          printf("\n\nIl valore [%d] è presente nella lista\n\n", x);
        }else{
          printf("\n\nIl valore [%d] non è presente nella lista\n\n", x);
        }
        break;
      case 10:
        print_lista(l);
        printf("\n\nInserire un numero presente in lista: ");
        printf("\n\n-->  ");
        scanf("%d",&x);
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
        print_lista(ls);
        if(verifica_primo_uguale_ultimo(ls)){
          printf("\n\nIl primo elemento nella lista è uguale all'ultimo\n\n");
        }else{
          printf("\n\nIl primo elemento nella lista non è uguale all'ultimo\n\n");
        }
        break;
      case 14:
        print_lista(ls);
        if(verifica_duplicati(ls)){
          printf("\n\nEsistono duplicati nella lista consecutivi\n\n");
        }else{
          printf("\n\nNon esistono duplicati nella lista consecutivi\n\n");
        }
        break;
      case 15:
        print_lista(ls);
        int cont1 = conta_nodi_info_uguale_lunghezza(ls);
        printf("\n\nI nodi con valore uguale alla lunghezza della lista sono: %d\n\n",cont1);
        break;
      case 16:
        print_lista(ls);
        int cont2 = conta_minori_adiac_prec(ls);
        printf("\n\nI nodi con valore minore ai nodi adiacenti successivi nella lista sono: %d\n\n", cont2);
        break;
      default:
        printf("\n\nIl valore inserito non è valido, inserire un numero del menù\n\n");
        break;
    }
  }

  if(l != NULL){
    free_lista(l);
  }

  return 0;
}

int massimo(plist l){
  if(l == NULL){
    printf("\nLista vuota!\n\n");
    exit(1);
  }else{
    int max = l->info;
    while(l->next != NULL){
	if(max < l->next->info) max = l->next->info;
	l = l->next;
    }
    return max;
  }
}

int somma(plist l){
  if(l == NULL){
    printf("\nLista vuota!");
    exit(1);
  }else{
    int somma = l->info;
    while(l->next != NULL){
      somma += l->next->info;
      l = l->next;
    }
    return somma;
  }
}

int cerca(plist l, int v){
  if(l == NULL){
    printf("\nLista vuota!");
    exit(1);
  }else{
    while(l->next != NULL){
      if(l->info == v) return 1;
      l = l->next;
    }
    return 0;
  }
}
/* alternativa
int cerca(plist l, int v){
  int trovato = 0;
  if(l!=NULL){
    plist i = l;
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
*/
int prev(plist l, int x){

  int valore = -1;
  if(l!= NULL) {
    plist i = l;
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

int verifica_ord_crescente(plist l){
   if(l == NULL) return 0;
   while(l->next != NULL){
      if(l->info > l->next->info){
         return 0;
      }
      l = l->next;
   }
   return 1;
}

int verifica_primo_uguale_ultimo(plist l){

  if(l == NULL){
    printf("\nLista vuota!\n\n");
    exit(1);
  }else{
    plist i = l;
    while(l->next != NULL){
      l = l->next;
    }

    return (l->info == i->info);
  }
}


int verifica_duplicati(plist l){
  if(l == NULL){
    printf("\nLista vuota!\n\n");
    exit(1);
  }else{
    while(l->next != NULL){
      if(l->info == l->next->info) return 1;
      l = l->next;
    }
    return 0;
  }
}

int verifica_duplicati_gen(plist l){
  if(l == NULL) return 0;
  while(l->next != NULL){
    plist n = l->next;
    if(n->info == l->info) return 1;
    while(n->next != NULL){
      n = n->next;
      if(n->info == l->info) return 1;
    }
    l = l->next;

  }
  return 0;
}

/*

int verifica_info_uguale_lunghezza(plist l){
  if(l == NULL){
    printf("\nLista vuota!\n\n");
    exit(1);
  }else{
    int lung = 0;
    plist tmp = l;
    while(tmp->next != NULL){
      lung++;
      tmp = tmp->next;
    }

    while(l->next != NULL){
      if(l->info == lung) return 1;
      l = l->next;
    }

    return 0;
  }
}*/
/*
int lunghezza(plist p){
  int c = 0;
  if(p == NULL){
    c = 0;
  }
  else{
    c = 1 + lunghezza(p->next);
  }
  return c;
}*/

int lunghezza(plist p){
  if(p == NULL) return 0;
  int s = 0;
  while(p->next != NULL){
    s++;
    p = p->next;
  }
  return s;
}

int verifica_info_uguale_lunghezza(plist p){
  if(p == NULL){
    printf("\nLista vuota!\n\n");
    exit(1);
  }else{
    int l = lunghezza(p);
    if(p->info == l) return 1;
    while(p->next != NULL){
      p = p->next;
      if(p->info == l) return 1;
    }
    return 0;
  }
}


int conta_nodi_info_uguale_lunghezza(plist p){
  if(p == NULL){
    printf("\nLista vuota!\n\n");
    exit(1);
  }else{
    int l = lunghezza(p);
    int c = 0;
    if(p->info == l) c++;
    while(p->next!= NULL){
      p = p->next;
      if(p->info == l) c++;
    }
    return c;
  }
}

int conta_minori_adiac_prec(plist l){
  if(l == NULL){
    printf("\nLa lista è vuota\n\n");
    exit(1);
  }else{
    int cont = 0;
    while(l->next != NULL){
      if(l->info < l->next->info) cont++;
      l = l->next;
    }
    return cont;
  }
}

void free_lista(plist l){
  free(l);
}

void print_lista(plist l){
  if(l==NULL){
    printf("\n\nLa lista è vuota\n\n");
    return;
  }else
    printf("\nLISTA:");
    plist i = l;
    while(i!=NULL){
      printf("[%d]", i->info);
      i = i->next;
    }
    printf("\n\n");
}

int comuni(plist p1, plist p2){
  if(p1 == NULL || p2 == NULL){
    printf("\n\nUno o entrambe le liste sono vuote\n\n");
    exit(1);
  }
  int count = 0;
  while(p1 != NULL){
    int verificato = 0;
    plist temp = p2;
    while(temp != NULL && !verificato){
      if(p1->info == temp->info){
        count++;
        verificato = 1;
      }
      else{
        temp = temp->next;
      }
    }
    p1 = p1->next;
  }
  return count;
}
