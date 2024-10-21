#include <stdio.h>
#include <stdlib.h>

double* plusMinus(int array[], int size_of_array) {
    int num_positives = 0, num_negatives = 0, num_zeros = 0;
    double percent_positives, percent_negatives, percent_zeros;
    double* percentages = (double*) malloc(3 * sizeof(double));

    // encontra a quantidade de números positivos, negativos e nulos no array
    for (int counter1 = 0; counter1 < size_of_array; counter1++) {
        if (array[counter1] > 0) {
            num_positives++;
        } else if (array[counter1] < 0) {
            num_negatives++;
        } else {
            num_zeros++;
        }
    }

    // calcula a porcentagem de números positivos, negativos e nulos no array em relação ao total
    percent_positives = (double) num_positives / size_of_array;
    percent_negatives = (double) num_negatives / size_of_array;
    percent_zeros = (double) num_zeros / size_of_array;

    percentages[0] = percent_positives;
    percentages[1] = percent_negatives;
    percentages[2] = percent_zeros;

    // retorna as porcentagens
    return percentages;
}

int main() {
    int size_of_array;
    int *array;
    scanf("%d", &size_of_array);
    array = (int *) malloc(size_of_array * sizeof(int));

    // le os numeros do array
    for (int i = 0; i < size_of_array; i++) {
        scanf("%d", &array[i]);
    }

    // aplica a função plusMinus no array
    double* percentages = plusMinus(array, size_of_array);

    // mostra as porcentagens
    for (int counter2 = 0; counter2 < 3; counter2++) {
        printf("%.6lf\n", percentages[counter2]);
    }

    // libera a memoria
    free(array);
    free(percentages);

    return 0;
}