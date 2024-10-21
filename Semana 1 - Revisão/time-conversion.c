#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* timeConversion(char time_12h[]) {
    int hour_24h;
    char* time_24h = (char*) malloc(11 * sizeof(char));

    // converte a hora para inteiro
    int hour_12h = (time_12h[0] - '0') * 10 + (time_12h[1] - '0');

    // converte as horas para o sistema de horario de 24 hors
    if (time_12h[8] == 'P') { 
        if (hour_12h != 12) {  
            hour_24h = hour_12h + 12;
        } else {  
            hour_24h = 12;
        }
    } else {  
        if (hour_12h == 12) {  
            hour_24h = 0;
        } else {  
            hour_24h = hour_12h;
        }
    }

    // retorna a string com o novo horario
    sprintf(time_24h, "%.2d", hour_24h); 
    strncat(time_24h, &time_12h[2], 6);  

    return time_24h;
}

int main() {
    // declara strings
    char time_12h[11];
    char* time_24h;

    // le e converte horarios
    fgets(time_12h, 11, stdin);
    time_24h = timeConversion(time_12h);
    puts(time_24h);

    // libera a memoria alocada
    free(time_24h);

    return 0;
}
