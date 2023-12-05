#include <stdio.h>
#include <stdlib.h>  // Adicionando a biblioteca necessária para a função exit()

// Função para calcular a determinante de uma matriz 2x2
double det(double a, double b, double c, double d) {
    double determinant = a * d - b * c;
    if (determinant == 0) {
        // Adicione aqui a lógica para lidar com determinante zero
        printf("A determinante é zero. O sistema pode ter infinitas soluções ou nenhuma solução única.\n");
        // Você pode retornar um valor especial ou sair do programa, dependendo da sua lógica
        exit(1);  // Termina o programa com código de erro 1
    }
    return determinant;
}

int main() {
    // Matrizes e vetores
    double A[2][2];
    double B[2];
    double C[2];

    // Receber os valores da matriz A do usuário
    printf("Insira as variáveis do problema modelado:\n");
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            printf("A[%d][%d]: ", i, j);
            // Verificar se as entradas foram lidas com sucesso
            if (scanf("%lf", &A[i][j]) != 1) {
                printf("Erro ao ler entrada para A[%d][%d]\n", i, j);
                return 1; // Termina o programa com código de erro 1
            }
        }
    }

    // Receber os valores da matriz B do usuário
    printf("Insira os valores referentes às restrições das respectivas variáveis:\n");
    for (int i = 0; i < 2; ++i) {
        printf("B[%d]: ", i);
        // Verificar se as entradas foram lidas com sucesso
        if (scanf("%lf", &B[i]) != 1) {
            printf("Erro ao ler entrada para B[%d]\n", i);
            return 1; // Termina o programa com código de erro 1
        }
    }

    // Receber os valores da matriz C do usuário
    printf("Insira os valores de venda das respectivas variáveis:\n");
    for (int i = 0; i < 2; ++i) {
        printf("C[%d]: ", i);
        // Verificar se as entradas foram lidas com sucesso
        if (scanf("%lf", &C[i]) != 1) {
            printf("Erro ao ler entrada para C[%d]\n", i);
            return 1; // Termina o programa com código de erro 1
        }
    }

    // Matrizes A_x e A_y
    double Ax[2][2], Ay[2][2];
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            Ax[i][j] = A[i][j];
            Ay[i][j] = A[i][j];
        }
    }

    // Substituir a primeira coluna de Ax por B
    for (int i = 0; i < 2; ++i) {
        Ax[i][0] = B[i];
    }

    // Substituir a segunda coluna de Ay por B
    for (int i = 0; i < 2; ++i) {
        Ay[i][1] = B[i];
    }

    // Calcular as determinantes
    double det_A = det(A[0][0], A[0][1], A[1][0], A[1][1]);
    double det_Ax = det(Ax[0][0], Ax[0][1], Ax[1][0], Ax[1][1]);
    double det_Ay = det(Ay[0][0], Ay[0][1], Ay[1][0], Ay[1][1]);

    // Calcular os valores de x e y
    double x = det_Ax / det_A;
    double y = det_Ay / det_A;

    // Imprimir resultados
    printf("\nMatriz de valores iniciais:\n");
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            printf("%f ", A[i][j]);
        }
        printf("\n");
    }
    printf("\nMatriz de lucro respectivamente:\n");
    for (int i = 0; i < 2; ++i) {
        printf("%f\n", C[i]);
    }
    printf("\nMatriz de restrições:\n");
    for (int i = 0; i < 2; ++i) {
        printf("%f\n", B[i]);
    }
    printf("\nValor de X: %f e Valor de Y: %f\n", x, y);

    // Calcular e imprimir o lucro máximo
    double soma = (C[0] * x) + (C[1] * y);
    double i = soma;
    if (soma == i) {
        soma = (C[0] * y) + (C[1] * x);
        if (soma > i) {
            printf("Lucro máximo de: %f\n", soma);
        } else {
            printf("Lucro máximo de: %f\n", i);
        }
    }

    return 0;
}