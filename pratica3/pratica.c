#include "carro.h"
#include "stdio.h"

int main() {
    int n, ano, lugares;
    char c, nome[21];
    scanf("%d\n", &n);
    scanf("%c", &c);//C contar, I imprimir
    
    if (c == 'C')
        scanf("%d %d", &ano, &lugares);//se for contar tem que ler ano e lugares
    else
        scanf("%s", nome);//se for i ler o nome do funcionário
    
    Carro* carros = CarroAloca(n);
    le(carros, n);
    if (c == 'C'){
        printf("%d\n", conta(carros, n, ano, lugares));
    }else
        imprime(carros, n, nome);
    CarroDesaloca(&carros, n);
    return 0;
}