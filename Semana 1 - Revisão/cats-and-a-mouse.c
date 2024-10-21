#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* catAndMouse(int cat_A_position, int cat_B_position, int mouse_C_position) {
    // string para guardar o resultado
    char* query_result = (char*) malloc(15 * sizeof(char));

    // encontra o resultado da query
    if (abs(cat_A_position - mouse_C_position) < abs(cat_B_position - mouse_C_position)) {
        strcpy(query_result, "Cat A");
    }

    if (abs(cat_B_position - mouse_C_position) < abs(cat_A_position - mouse_C_position)) {
        strcpy(query_result, "Cat B");
    }

    if (abs(cat_A_position - mouse_C_position) == abs(cat_B_position - mouse_C_position)) {
        strcpy(query_result, "Mouse C");
    }

    return query_result;
}

int main() {
    // verifica o numero de queries
    int num__queries;
    scanf("%d", &num__queries);

    for (int counter1 = 0; counter1 < num__queries; counter1++) {
        char* query_result = (char*) malloc(15 * sizeof(char));

        // le posicoes
        int cat_A_position, cat_B_position, mouse_C_position;
        scanf("%d %d %d\n", &cat_A_position, &cat_B_position, &mouse_C_position);

        strcpy(query_result, catAndMouse(cat_A_position, cat_B_position, mouse_C_position));
        printf("%s\n", query_result);

        free(query_result);
    }

    return 0;
}