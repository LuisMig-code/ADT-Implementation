#ifndef _COLECAO_C_
#define _COLECAO_C_

#include <stdio.h>
#include <string.h>
#define true 1
#define false 0
#include "colecao.h"

typedef struct _colecao_ {
    int numItens;
    int maxItens;
    void **item;
    int atual;
} Colecao;

Colecao *colCreate(int n) {
    if (n < 1) {
        return NULL;
    }
    Colecao *col;
    col = (Colecao *)malloc(sizeof(Colecao));

    if (col == NULL) {
        free(col);
        return NULL;
    }

    col->item = (void **)malloc(n * sizeof(void *));
    if (col->item == NULL) {
        free(col->item);
        free(col);
        return NULL;
    }

    col->numItens = 0;
    col->maxItens = n;
    col->atual = 0;
    return col;
}

// ta funcionando beleza
int colInsert(Colecao *col, void *key) {
    if (col == NULL) {
        return false;
    }

    if (col->numItens < col->maxItens) {

        col->item[col->numItens] = key;
        col->numItens++;

        return true;
    }
    return false;
}

int colDestroy(Colecao *col) {
    if (col != NULL) {
        if (col->numItens == 0) {
            free(col->item);
            free(col);
            return true;
        }
    }
    return false;
}

void *colRemove(Colecao *col, void *key) {
    if (col == NULL) {
        return NULL;
    }

    if (col->numItens <= 0) {
        return NULL;
    }

    int i = 0, j = 0;
    void *data;
    while (i < col->numItens && col->item[i] != key) {
        ++i;
    }

    if (col->item[i] == key) {
        data = col->item[i];
        for (j = i; j < col->numItens; j++) {
            col->item[j] = col->item[j + 1];
        }
        col->numItens--;
        return data;
    }

    return NULL;
}

void *colQuery(Colecao *col, void *key) {

    if (col != NULL) {
        int i = 0;
        while (i < col->numItens && col->item[i] != key) {
            ++i;
        }
        void *data;
        if (col->item[i] == key) {
            data = col->item[i];
            return data;
        }
    }

    return NULL;
}

void *colQueryTeste(Colecao *col, void *key, int (*cmp)(void *, void *)) {

    if (col != NULL && col->numItens > 0) {
        int i;
        for (i = 0; i < col->numItens; i++) {
            if (cmp(col->item[i], key) == true) {
                return col->item[i];
            }
        }
    }

    return false;
}

void *colGetFirst(Colecao *col) {
    if (col != NULL) {
        if (col->numItens > 0) {
            col->atual = 0;
            return col->item[col->atual];
        }
    }
    return NULL;
}

void *colGetNext(Colecao *col) {
    if (col == NULL) {
        return NULL;
    } else {
        if (col->numItens > 0) {
            col->atual++;
            int posicao = col->atual;
            if (posicao + 1 > col->numItens) {
                return NULL;
            } else {
                return col->item[posicao];
            }
        }
    }
}

int colEsvazia(Colecao *col) {
    if (col != NULL) {
        if (col->numItens > 0) {
            for (int i = 0; i < col->numItens; i++) {
                col->item[i] = NULL;
            }
            col->numItens = 0;
            return true;
        }
    }
    return false;
}

#endif