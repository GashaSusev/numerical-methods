#include <iostream> 
#include <iomanip> 
#include <ctime> 
int counter = 0;
void consoleOut(long double A[8][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            std::cout << std::setw(12) << A[i][j];
        }
        std::cout << std::endl << std::endl;
    }
}
const int N = 8;
void gauss(long double matrix[N][N], long double result[N]) {
    long double X[N];
    for (int k = 0; k < N - 1; k++) {
        for (int i = k + 1; i < N; i++) {
            double long u = matrix[i][k] / matrix[k][k];
            matrix[i][k] = 0;
            for (int j = k + 1; j < N; j++) {
                counter++;
                matrix[i][j] = matrix[i][j] - u * matrix[k][j];
            }
            result[i] = result[i] - u * result[k]; counter++;
        }
    }
    consoleOut(matrix);
    std::cout << std::endl;
    X[N - 1] = result[N - 1] / matrix[N - 1][N - 1];
    for (int i = N - 1; i >= 0; i--) {
        double long s = 0;
        for (int j = i + 1; j < N; j++) {
            s = s + matrix[i][j] * X[j];
            counter++;
        } counter++;
        X[i] = (result[i] - s) / matrix[i][i];
    }
    for (int i = 0; i < 8; i++) {
        std::cout << std::setw(9) << X[i];
    }
}

int main() {
    time(NULL);
    srand(687678567);
    long double A[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            A[i][j] = rand() % 1000;
        }
    }
    consoleOut(A);
    std::cout << std::endl << std::endl;
    long double X[8];
    for (int i = 0; i < 8; i++) {
        X[i] = i + 1;
    }
    long double B[8];
    for (int i = 0; i < 8; i++) {
        B[i] = 0;
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            B[i] += A[i][j] * X[j];
        }
    }
    for (int i = 0; i < 8; i++) {
        std::cout << std::setw(9) << B[i];
    }
    std::cout << std::endl << std::endl; gauss(A, B);
    std::cout << std::endl << std::endl;
    std::cout << counter; return 0;
}
