#include "colecao.h"
#include "jogador.h"
#include <stdio.h>
#include <string.h>
#ifndef FUNCOES_C_
#define FUNCOES_C_

#define true 1
#define false 0

int cmpNome(void *key, void *atr) {

    Jogador *key_temp = (Jogador *)key;

    /* strcmp retorna 0 se for igual */

    if (strcmp(key_temp->nome, (char *)atr) == 0) {
        return true;
    }

    return false;
}

int cmpIdade(void *key, void *atr) {

    Jogador *key_temp = (Jogador *)key;

    if (key_temp->idade == *(int *)atr) {
        return true;
    }

    return false;
}

int cmpAltura(void *key, void *atr) {

    Jogador *key_temp = (Jogador *)key;

    if (key_temp->altura == *(float *)atr) {
        return true;
    }

    return false;
}

#endif // FUNCOES_C_