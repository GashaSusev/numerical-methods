#include <iostream>
#include <iomanip>
#include <stdlib.h>
int counter = 0;

const int N = 20;

double long eps = 0.001;

void consoleOut(long double A[N][N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cout << std::setw(8) << A[i][j];
		}
		std::cout << std::endl << std::endl;
	}
}

bool check(long double x[N], long double p[N]){
	double norm = 0;
	for (int i = 0;i<N;i++){
		norm += (x[i] - p[i]) * (x[i] - p[i]);
	}
	return (sqrt(norm) > eps);
}

int main() {
	long double A[N][N];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			A[i][j] = rand() % 100;
		}
	}

	for (int i = 0; i < N; i++) {
		long double sum = 0;
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			sum += A[i][j];
		}
		A[i][i] = sum + rand() % 100;
	}

	consoleOut(A);

	std::cout << std::endl << std::endl;

	long double temp[N];
	for (int i = 0; i < N; i++) {
		temp[i] = i + 1;
	}

	long double B[N];
	for (int i = 0; i < N; i++) {
		B[i] = 0;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
				B[i] += A[i][j] * temp[j];
		}
	}

	for (int i = 0; i < N; i++) {
		std::cout << std::setw(9) << B[i];
	}


	long double P[N];
	long double X[N];

	for (int i = 0; i < N; i++) {
		X[i] = 0;
	}

	while (check(X, P)){
		for (int i = 0; i < N; i++) {
			P[i] = X[i];

		}
		for (int i = 0; i < N; i++){
			long double var = 0;
			for (int j = 0; j < N; j++) {
				if (j != i) {
					var += (A[i][j] * X[j]);
					counter+=2;
				}
			}
			X[i] = (B[i] - var) / A[i][i];
			counter+=2;
		}
	}

	std::cout << std::endl << std::endl;

	for (int i = 0; i < N; i++) {
		std::cout << std::setw(12) << std::setprecision(std::numeric_limits<long double>::digits10 + 1) << X[i];
		std::cout << std::endl << std::endl;
	}

	for (int i = 0; i < N; i++) {
		std::cout << std::setw(12) << std::setprecision(std::numeric_limits<long double>::digits10 + 1) << X[i] - temp[i];
		std::cout << std::endl << std::endl;
	}
	std::cout << counter;
	return 0;
}
