#include <stdio.h>
#include <locale.h>

//Busca Bin�ria
int buscaBinaria(int array[], int tamanho, int chave) {
    int inicio = 0;
    int fim = tamanho - 1;
    int meio;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;

        //Verifica se a chave est� no meio do array
        if (array[meio] == chave)
            return meio;

        // e a chave � maior, ignore a metade esquerda
        if (array[meio] < chave)
            inicio = meio + 1;

        //Se a chave � menor, ignore a metade direita
        else
            fim = meio - 1;
    }

    //Caso n�o encontre, retorna -1
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
        printf("Elemento [%d] �ndice [%d]: ", i + 1,i);
        scanf("%d", &array[i]);
    }

    printf("Digite o n�mero a ser buscado: ");
    scanf("%d", &chave);

    int indice = buscaBinaria(array, tamanho, chave);

    if (indice != -1)
        printf("Elemento %d encontrado no �ndice %d.\n", chave, indice);
    else
        printf("Elemento %d n�o encontrado no array.\n", chave);

    return 0;
}

