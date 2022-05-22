#include "colecao.h"
#include "funcoes.h"
#include "jogador.h"

#define _MAIN_C_

#include <stdio.h>
#include <string.h>

#define true 1
#define false 0

// OK

void printMenu() {
    printf("\n----------------------------\n");
    printf("MENU:\n");
    printf("1) Criar o TAD\n");
    printf("2) Inserir item na Colecao\n");
    printf("3) Listar itens da Colecao\n");
    printf("4) Consultar item na Colecao\n");
    printf("5) Remover item da Colecao\n");
    printf("6) Destruir Colecao\n");
    printf("7) Esvaziar a Colecao\n");
    printf("8) Sair do programa\n");
    printf("----------------------------\n");
    printf("Digite o valor: ");
}

int main() {
    printf("-----------------\n");
    // Receber esses dados do usuario:

    int max = -1;
    int numItens = 0;

    printf("Quantidade Maxima de Elementos: ");
    scanf("%i", &max);
    while (max <= 0) {
        printf("Valor invalido... Tente novamente: ");
        scanf("%i", &max);
    }

    Colecao *gCol = NULL;
    Jogador *jog;

    int loop = true, i = 0, j = 0;
    int n, num, l;
    int criado = false;
    int cont_remove;

    Jogador *elem;
    while (loop == true) {

        int selecao;
        printMenu();
        scanf("%i", &selecao);

        // Aplicação em si:
        switch (selecao) {

            case 1: // Criar  Colecao
                if (criado == true) {
                    printf("TAD ja criado");
                    break;
                }
                gCol = colCreate(max);

                if (gCol == NULL) {
                    printf("Nao foi possível alocar o time, tente novamente\n");
                    break;
                }
                printf("TAD CRIADO\n");
                criado = true;
                break;

                // OK //

            case 2: // Inserir itens no Colecao:
                if (gCol == NULL) {
                    printf("Aloque primeiro a colecao\n");
                    break;
                }

                if (criado == false) {
                    printf("Operacao Impossivel, tente novamente: ");
                    break;
                }

                if (numItens >= max) {

                    printf("Colecao cheia, remova algum jogador ou tente outra operacao\n");
                    break;
                } else {
                    elem = (Jogador *)malloc(sizeof(Jogador));

                    /* Loop para insercao dos jogadores na colecao */
                    char *nome = (char *)malloc(30 * sizeof(char));
                    printf("Digite o nome do jogador: ");
                    scanf("%s", nome);
                    strcpy(elem->nome, nome);

                    while (strlen(elem->nome) > 30) {
                        printf("Nome com mais de 30 caracteres, tente novamente: ");
                        scanf("%s", elem->nome);
                    }

                    printf("Digite a idade do jogador: ");
                    scanf("%i", &elem->idade);

                    while (elem->idade <= 0) {
                        printf("Idade errada, tente novamente: ");
                        scanf("%i", &elem->idade);
                    }

                    printf("Digite a altura em metros do jogador: ");
                    scanf("%f", &elem->altura);

                    while (elem->altura < 0) {
                        printf("Altura negativa, tente novamente: ");
                        scanf("%f", &elem->altura);
                    }
                    printf("\n-----------------\n");

                    int retorno = colInsert(gCol, (void *)elem);

                    if (retorno == false) {
                        printf("Insercao falhou");
                        break;
                    }

                    else {
                        printf("\nInsercao feita com sucesso :)\n");
                        numItens++;
                    }
                }
                break;

            case 3: // Listar a colecao
                if (gCol == NULL) {
                    printf("Aloque primeiro a colecao\n");
                    break;
                }

                if (numItens == 0) {
                    printf("Colecao vazia!\n");
                    break;
                }

                jog = colGetFirst(gCol);
                for (int i = 0; i < numItens; i++) {
                    printf("Jogador %s, indice [%d], idade %d, altura %.2f\n", jog->nome, i,
                           jog->idade, jog->altura);
                    jog = colGetNext(gCol);
                }
                break;

            case 4: // Pesquisar na Colecao

                if (gCol == NULL) {
                    printf("Aloque primeiro a colecao\n");
                    break;
                }

                if (numItens == 0) {
                    printf("colecao vazia!");
                    break;
                }
                l = true;
                printf("Tipo de pesquisa: \n");
                printf("1) Nome:\n");
                printf("2) Idade:\n");
                printf("3) Altura:\n");
                scanf("%i", &num);

                while (l == true) {
                    if (num == 1) {
                        printf("Digite o nome do jogador: ");
                        char *nome = (char *)malloc(sizeof(char));
                        scanf("%s", nome);

                        jog = colQueryTeste(gCol, (void *)nome, cmpNome);
                        l = false;
                        break;
                    }
                    if (num == 2) {
                        printf("Digite a idade do jogador");
                        int idade;
                        scanf("%i", &idade);

                        jog = colQueryTeste(gCol, (void *)&idade, cmpIdade);
                        l = false;
                        break;
                    }
                    if (num == 3) {
                        printf("Digite a altura do jogador");
                        float altura;
                        scanf("%f", &altura);

                        jog = colQueryTeste(gCol, (void *)&altura, cmpAltura);
                        l = false;
                        break;
                    }

                    else {
                        printf("NUMERO ERRADO, TENTE NOVAMENTE");
                        scanf("%i", &num);
                    }

                } // fim WHILE

                if (jog != NULL) {
                    printf("Nome: %s\n", jog->nome);
                    printf("Idade: %d\n", jog->idade);
                    printf("Altura: %.2f\n", jog->altura);

                } else {
                    printf("elemento nao esta na Colecao!\n");
                    break;
                }
                break;

            case 5: // Remover item da Colecao
                if (gCol == NULL) {
                    printf("Aloque primeiro a colecao\n");
                    break;
                }
                if (numItens == 0) {
                    printf("Colecao vazia\n");
                    break;
                }
                jog = (Jogador *)malloc(sizeof(Jogador));

                printf("Tipo de Remocao: \n");
                printf("1) Nome:\n");
                printf("2) Idade:\n");
                printf("3) Altura:\n");
                scanf("%i", &num);

                if (num == 1) {
                    printf("Digite o nome do jogador: ");
                    char *nome = (char *)malloc(sizeof(char));
                    scanf("%s", nome);

                    jog = colQueryTeste(gCol, (void *)nome, cmpNome);
                    if(jog != NULL) {
                        colRemove(gCol, jog);
                        numItens--;
                        printf("Removido");
                        break;
                    } else {
                        printf("O Elemento não está na Colecao");
                        break;
                    }

                }
                if (num == 2) {
                    printf("Digite a idade do jogador: ");
                    int idade;
                    scanf("%i", &idade);

                    jog = colQueryTeste(gCol, (void *)&idade, cmpIdade);
                    if(jog != NULL) {
                        colRemove(gCol, jog);
                        numItens--;
                        printf("Removido");
                        break;
                    } else {
                        printf("O Elemento não está na Colecao");
                        break;
                    }
                }
                if (num == 3) {
                    printf("Digite a altura do jogador: ");
                    float altura;
                    scanf("%f", &altura);

                    jog = colQueryTeste(gCol, (void *)&altura, cmpAltura);
                    if(jog != NULL) {
                        colRemove(gCol, jog);
                        numItens--;
                        printf("Removido");
                        break;
                    } else {
                        printf("O Elemento não está na Colecao");
                        break;
                    }
                }

            case 6: // Destruir colecao
                if (criado == false) {
                    printf("Impossivel realizar operacao, tente novamente");
                    break;
                }
                if (colDestroy(gCol) == false) {
                    printf("Impossivel realizar operacao");
                    break;
                } else {
                    printf("TAD destruido");
                    numItens = 0;
                    criado = false;
                    break;
                }

            case 7: // Esvaziar o Colecao
                if (gCol == NULL) {
                    printf("Aloque primeiro a colecao\n");
                    break;
                }

                if (criado == false) {
                    printf("Impossivel realizar operacao, tente novamente");
                    break;
                }

                if (numItens == 0) {
                    printf("Colecao esta vazia!");

                    break;
                }
                colEsvazia(gCol);
                numItens = 0;
                printf("Colecao esvaziada com sucesso");
                break;

            case 8: // Fechando o programa
                printf("Fechando o programa...");
                loop = 0;
                break;

            default:
                printf("SELECIONE UM NUMERO ENTRE 1 E 8");
        }
    }

    printf("\n-----------------");
    return 0;
}