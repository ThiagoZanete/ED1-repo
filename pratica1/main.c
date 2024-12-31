#include <stdio.h>

void readMatrix(double matrix[12][12]);
double sumMatrix(double matrix[12][12]);

int main()
{
    double s = 0.0, M[12][12];
    char T;

    // Leitura do Char
    scanf("%c", &T);
    // Leitura da Matriz e Cálculos
    readMatrix(M);
    s = sumMatrix(M);

    // Impressão dos resultados
    if(T == 'S'){
        printf("%.1lf\n", s);
    }else{
        printf("%.1lf\n", s / 30);
    }
    return 0;
}

void readMatrix(double matrix[12][12]) {
    // preencher aqui
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 12; j++){
            scanf("%lf", &matrix[i][j]);
        }
    }
}

double sumMatrix(double matrix[12][12]) {
    double resultado = 0;
    int inicial = 1;
    for(int i = 11; i > 6; i--){
        for(int j = inicial; j <= 11 - inicial; j++){
                resultado += matrix[i][j];
        }
        inicial++;
    }
    // preencher aqui

    return resultado;
}