#include <stdlib.h>
#ifndef _COLECAO_H_
#define _COLECAO_H_



#ifdef _COLECAO_C_
typedef struct _colecao_ Colecao;
Colecao *colCreate( int max_itens);
int colInsert(Colecao *col, void *item );
void *colRemove(Colecao *col, void *key );
void *colQuery (Colecao *col, void *key);
void *colGetFirst(Colecao *col);
void *colGetNext (Colecao *col);
int colDestroy (Colecao *col);
int colEsvazia(Colecao* col);
void *colRemoveTeste(Colecao *col, void* key);
void* colQueryTeste(Colecao *col, void* key, int (*cmp) (void*, void*));

#else
typedef struct _colecao_ Colecao;
Colecao *colCreate( int max_itens);
extern int colInsert(Colecao *col, void *item );
extern void *colRemove(Colecao *col, void *key );
extern void *colQuery (Colecao *col, void *key);
extern void *colGetFirst(Colecao *col);
extern void *colGetNext (Colecao *col);
extern int colDestroy (Colecao *col);
extern int colEsvazia(Colecao* col);
extern void *colRemoveTeste(Colecao *col, void* key);
extern void* colQueryTeste(Colecao *col, void* key, int (*cmp) (void*, void*));

#endif
#endif // _COLECAO_H_