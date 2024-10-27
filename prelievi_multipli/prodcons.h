#ifndef _PRODCONS_H_
#define _PRODCONS_H_

#include "monitor_hoare.h"

#define DIM 10

typedef struct {
    int vettore[DIM];

    /* TBD: Definire un sotto-oggetto Monitor e le altre variabili per la sincronizzazione */
} ProdCons;

/* TBD: Definire delle macro per identificare le variabili condition */

void inizializza(ProdCons * p);
void consuma(ProdCons * p, int* val_1, int* val_2);
void produci(ProdCons * p, int val);
void rimuovi(ProdCons * p);

#endif
