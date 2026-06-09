#include <stdio.h>

#define MAX 100

// ===============================
// Função para listar elementos
// ===============================
void listar(int v[], int quantidade) {
    int i;

    if (quantidade == 0) {
        printf("Lista vazia!\n");
        return;
    }

    for (i = 0; i < quantidade; i++) {
        printf("%d ", v[i]);
    }

    printf("\n");
}

// ===============================
// Busca sequencial
// ===============================
int buscar(int v[], int quantidade, int valor) {
    int i;

    for (i = 0; i < quantidade; i++) {
        if (v[i] == valor) {
            return 1;
        }
    }

    return 0;
}

// ===============================
// Inserir sem repetir
// ===============================
void inserirSemRepetir(int v[], int valor, int *pos, int max) {

    if (*pos >= max) {
        printf("Erro: lista cheia!\n");
        return;
    }

    if (buscar(v, *pos, valor)) {
        printf("Erro: valor repetido!\n");
        return;
    }

    v[*pos] = valor;
    (*pos)++;
}

// ===============================
// Intercalar listas
// ===============================
void intercalar(
    int v1[], int q1,
    int v2[], int q2,
    int v3[], int *q3
) {
    int i = 0, j = 0;

    *q3 = 0;

    while (i < q1 || j < q2) {

        if (i < q1) {
            v3[*q3] = v1[i];
            (*q3)++;
            i++;
        }

        if (j < q2) {
            v3[*q3] = v2[j];
            (*q3)++;
            j++;
        }
    }
}

// ===============================
// Interseção
// ===============================
void intersecao(
    int v1[], int q1,
    int v2[], int q2,
    int v3[], int *q3
) {
    int i;

    *q3 = 0;

    for (i = 0; i < q1; i++) {

        if (buscar(v2, q2, v1[i])) {

            if (!buscar(v3, *q3, v1[i])) {
                v3[*q3] = v1[i];
                (*q3)++;
            }
        }
    }
}

// ===============================
// União
// ===============================
void uniao(
    int v1[], int q1,
    int v2[], int q2,
    int v3[], int *q3
) {
    int i;

    *q3 = 0;

    // Copia lista 1
    for (i = 0; i < q1; i++) {
        inserirSemRepetir(v3, v1[i], q3, MAX);
    }

    // Copia lista 2 sem repetir
    for (i = 0; i < q2; i++) {
        inserirSemRepetir(v3, v2[i], q3, MAX);
    }
}

// ===============================
// Remover pelo índice
// ===============================
void removerPeloIndice(
    int v[],
    int *quantidade,
    int indice
) {
    int i;

    for (i = indice; i < *quantidade - 1; i++) {
        v[i] = v[i + 1];
    }

    (*quantidade)--;
}

// ===============================
// Main
// ===============================
int main() {

    int lista1[MAX];
    int lista2[MAX];

    int intercalada[MAX];
    int intersec[MAX];
    int uniaoLista[MAX];

    int q1 = 0;
    int q2 = 0;
    int qInter = 0;
    int qIntersec = 0;
    int qUniao = 0;

    int valor;
    int i;
    int indice;

    // ===========================
    // Criando lista 1
    // ===========================
    printf("Digite 5 valores para lista 1:\n");

    for (i = 0; i < 5; i++) {
        scanf("%d", &valor);
        inserirSemRepetir(lista1, valor, &q1, MAX);
    }

    // ===========================
    // Criando lista 2
    // ===========================
    printf("Digite 5 valores para lista 2:\n");

    for (i = 0; i < 5; i++) {
        scanf("%d", &valor);
        inserirSemRepetir(lista2, valor, &q2, MAX);
    }

    // ===========================
    // Mostrar listas
    // ===========================
    printf("\nLista 1:\n");
    listar(lista1, q1);

    printf("Lista 2:\n");
    listar(lista2, q2);

    // ===========================
    // Intercalação
    // ===========================
    intercalar(
        lista1, q1,
        lista2, q2,
        intercalada, &qInter
    );

    printf("\nLista Intercalada:\n");
    listar(intercalada, qInter);

    // ===========================
    // Interseção
    // ===========================
    intersecao(
        lista1, q1,
        lista2, q2,
        intersec, &qIntersec
    );

    printf("\nInterseção:\n");
    listar(intersec, qIntersec);

    // ===========================
    // União
    // ===========================
    uniao(
        lista1, q1,
        lista2, q2,
        uniaoLista, &qUniao
    );

    printf("\nUnião:\n");
    listar(uniaoLista, qUniao);

    // ===========================
    // Remoção por índice
    // ===========================
    printf("\nDigite o indice para remover da uniao: ");
    scanf("%d", &indice);

    if (indice < 0 || indice >= qUniao) {

        printf("Erro: indice invalido!\n");

    } else {

        removerPeloIndice(
            uniaoLista,
            &qUniao,
            indice
        );

        printf("\nLista apos remocao:\n");
        listar(uniaoLista, qUniao);
    }

    return 0;
} 


