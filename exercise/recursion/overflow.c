#include <stdio.h>

void rekursiv(int zaehler) {
    printf("Rekursionstiefe: %d\n", zaehler);
    rekursiv(zaehler + 1);
}

int main() {
    rekursiv(1);
    return 0;
}
