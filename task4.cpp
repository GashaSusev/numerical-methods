#include <iostream>
#include <iomanip>
#include <ctime>
int counter = 0;
void consoleOut(long double A[8][8]) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			std::cout << std::setw(9) << A[i][j];
		}
		std::cout << std::endl << std::endl;
	}
}
const int N = 8;
void progonka(long double matrix[N][N], long double result[N]) {
	double long p[N + 1];
	double long q[N + 1];
	p[0] = 0; q[0] = 0;
	for (int i = 0; i < N; i++) {
		double long a = matrix[i][i - 1];
		double long b = matrix[i][i];
		double long c = matrix[i][i + 1];
		double long s = (b + a * p[i]);
		p[i + 1] = -c / s;
		q[i + 1] = (-a * q[i] + result[i]) / s;
		counter += 6;
	} p[8] = 0;
	double long X[8];
	for (int i = N - 1; i >= 0; i--) {
		X[i] = p[i + 1] * X[i + 1] + q[i + 1];
		counter += 2;
	}
	for (auto now : X) {
		std::cout << std::setw(8) << now << " ";
	}
	std::cout << std::endl;
}
int main() {
	time(NULL);
	srand(687677);
	long double A[8][8];
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			A[i][j] = 0;
		}
	}
	A[0][1] = rand() % 100;
	A[0][0] = A[0][1] + rand() % 100;
	for (int i = 1; i < 7; i++) {
		A[i][i - 1] = rand() % 100;
		A[i][i + 1] = rand() % 100;
		A[i][i] = A[i][i - 1] + A[i][i - 1] + rand() % 100;
	}
	A[7][6] = rand() % 100;
	A[7][7] = A[7][6] + rand() % 100;
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
		std::cout << std::setw(6) << B[i];
	}
	std::cout << std::endl << std::endl;
	progonka(A, B);
	std::cout << std::endl << std::endl;
	std::cout << counter;
	return 0;
}
