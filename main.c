#include <stdio.h>
#include <locale.h>

int buscaBinaria(int array[], int tamanho, int chave) {
    int inicio = 0;
    int fim = tamanho - 1;
    int meio;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;

        if (array[meio] == chave)
            return meio;

        if (array[meio] < chave)
            inicio = meio + 1;

        else
            fim = meio - 1;
    }

    return -1;
}

int main() {
	setlocale(LC_ALL,"portuguese");
    int tamanho, chave, i;

    printf("Digite o tamanho do array: ");
    scanf("%d", &tamanho);

    int array[tamanho];

    printf("Digite os elementos do array (em ordem crescente):\n");
    for (i = 0; i < tamanho; i++) {
        printf("Elemento [%d] Índice [%d]: ", i + 1,i);
        scanf("%d", &array[i]);
    }

    printf("Digite o número a ser buscado: ");
    scanf("%d", &chave);

    int indice = buscaBinaria(array, tamanho, chave);

    if (indice != -1)
        printf("Elemento %d encontrado no índice %d.\n", chave, indice);
    else
        printf("Elemento %d não encontrado no array.\n", chave);

    return 0;
}

