#include <stdio.h>

int main() {
    int size_of_array, sum = 0;
    scanf("%d", &size_of_array);
    int array[size_of_array];

    for (int i = 0; i < size_of_array; i++) {
        scanf("%d", &array[i]);
        sum = sum + array[i];
    }
    
    printf("%d", sum);
}