#include <stdio.h>
#include "recursao.h"

int main() {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    printf("MDC = ");
    printf("%d\n", mdc(mdc(x, y), z));
    // Calcule o MDC entre os três valores
    printf("MMC = %d\n",mmc(mmc(x, y), z));
    // Calcule o MMC entre os três valores
    return 0;
}