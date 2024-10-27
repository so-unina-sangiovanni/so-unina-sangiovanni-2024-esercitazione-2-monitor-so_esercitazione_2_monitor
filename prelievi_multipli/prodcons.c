#include <stdio.h>
#include <unistd.h>

#include "prodcons.h"

void inizializza(ProdCons * p) {

    /* TBD: Inizializzazione del monitor */
}

void consuma(ProdCons * p, int* val_1, int* val_2) {

    /* TBD: Ingresso nel monitor */


    printf("[%d] Ingresso consumatore\n", getpid());

    /* TBD: Sospendere qui il consumatore se non ci sono
     *      *almeno* 2 elementi disponibili nel vettore
     */

    
    *val_1 = p->vettore[p->coda];
    p->coda = (p->coda + 1) % DIM;
    p->totale_elementi--;

    printf("[%d] Prima consumazione: val_1=%d\n", getpid(), *val_1);



    *val_2 = p->vettore[p->coda];
    p->coda = (p->coda + 1) % DIM;
    p->totale_elementi--;

    printf("[%d] Seconda consumazione: val_2=%d\n", getpid(), *val_2);


    /* TBD: Effettuare signal_condition() per svegliare 2 produttori 
     *      (si sono appena liberati 2 buffer nel vettore)
     */


    printf("[%d] Uscita consumatore\n", getpid());

    /* TBD: Uscita dal monitor */
}

void produci(ProdCons * p, int val) {

    /* TBD: Ingresso nel monitor */

    printf("[%d] Ingresso produttore\n", getpid());

    /* TBD: Sospendere qui il produttore se il vettore è già pieno */


    p->vettore[p->testa] = val;
    p->testa = (p->testa + 1) % DIM;
    p->totale_elementi++;

    printf("[%d] Produzione: val=%d\n", getpid(), val);

    
    /* TBD: Svegliare un consumatore *solo se* sono disponibili almeno 2 messaggi. 
     *      Poiché è richiesto di utilizzare la semantica di Hoare, il consumatore
     *      sarà attivato immediatamente al momento della signal_condition().
     */

    printf("[%d] Uscita produttore\n", getpid());

    /* TBD: Uscita dal monitor */
}

void rimuovi(ProdCons * p) {

    /* TBD: Deallocazione del sotto-oggetto monitor */
}
