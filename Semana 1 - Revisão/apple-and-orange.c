#include <stdio.h>
#include <stdlib.h>

int* countApplesAndOranges(int house_starting_point, int house_ending_point, int apple_tree_location, int orange_tree_location, int apples_distances[], int oranges_distances[], int total_apples, int total_oranges) {
    // vetor para armazenar numeros de frutas caidas na casa (maca pos 0, laranja pos 1)
    int *fruits_in_range = (int*) malloc(2 * sizeof(int));

    // declaracao de variaveis
    int num_apples_in_range = 0, num_oranges_in_range = 0;
    
    // conta a quantidade de macas caidas na casa
    for (int counter1 = 0; counter1 < total_apples; counter1++) {
        if (apples_distances[counter1] + apple_tree_location <= house_ending_point && apples_distances[counter1] + apple_tree_location >= house_starting_point) {
            num_apples_in_range++;
        }
    }

    // conta a quantidade de laranjas caidas na casa
    for (int counter2 = 0; counter2 < total_oranges; counter2++) {
        if (oranges_distances[counter2] + orange_tree_location <= house_ending_point && oranges_distances[counter2] + orange_tree_location >= house_starting_point) {
            num_oranges_in_range++;
        }
    }

    // retorna o vetor com o numero de macas e laranjas caidas na casa
    fruits_in_range[0] = num_apples_in_range;
    fruits_in_range[1] = num_oranges_in_range;
    return fruits_in_range;
    free(fruits_in_range);
}

int main() {
    // declaracao e leitura de variaveis
    int house_starting_point, house_ending_point, apple_tree_location, orange_tree_location, total_apples, total_oranges;
    
    scanf("%d %d\n%d %d\n%d %d\n", &house_starting_point, &house_ending_point, &apple_tree_location, &orange_tree_location, &total_apples, &total_oranges);

    // declara e le os vetores com distancias de macas e laranjas
    int *apples_distances = (int*) malloc(total_apples * sizeof(int));
    int *oranges_distances = (int*) malloc(total_oranges * sizeof(int));

    for (int counter1 = 0; counter1 < total_apples; counter1++) {
        scanf("%d", &apples_distances[counter1]);
    }

    for (int counter2 = 0; counter2 < total_oranges; counter2++) {
        scanf("%d", &oranges_distances[counter2]);
    }

    // calcula quantas frutas cairam na casa
    int *fruits_in_range = (int*) malloc(2 * sizeof(int));
    fruits_in_range = countApplesAndOranges(house_starting_point, house_ending_point, apple_tree_location, orange_tree_location, apples_distances, oranges_distances, total_apples, total_oranges);

    // mostra os resultados
    for (int counter3 = 0; counter3 < 2; counter3++) {
        printf("%d\n", fruits_in_range[counter3]);
    }

    // libera a memoria
    free(apples_distances);
    free(oranges_distances);
    free(fruits_in_range);

    return 0;
}