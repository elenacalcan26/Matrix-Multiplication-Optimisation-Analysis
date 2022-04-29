/*
 * Tema 2 ASC
 * 2022 Spring
 */
#include "utils.h"

/*
 * Add your unoptimized implementation here
 */
double* my_solver(int N, double *A, double* B) {
	printf("NEOPT SOLVER\n");
	int i, j, k;
	double *C = (double *)calloc(N * N, sizeof(double));
	double *X = (double *)calloc(N * N, sizeof(double));
	double *At = (double *)calloc(N * N, sizeof(double));
	double *Bt = (double *)calloc(N * N, sizeof(double));

	if (C == NULL || X == NULL || At == NULL || Bt == NULL)
		exit(-1);


	// transpusa matrice B
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			Bt[j * N + i] = B[i* N + j];

		}
	}

	// transpusa matrice superior triunghiulara A
	for (i = 0; i < N; i++) {
		for (j = i; j < N; j++) {
			At[j * N + i] = A[i * N + j];
		}
	}

	// se calculeaza C = Bt * B
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			for (k = 0; k < N; k++) {
				C[i * N + j] = Bt[i * N + k] * B[k * N + j];
			}
		}
	}

	// X = A * At
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			for (k = i; k < N; k++) {
				X[i * N + j] += A[i * N + k] * At[k * N + j];
			}
		}
	}

	// C += B * X
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			for (k = 0; k < N; k++) {
				C[i * N + j] += B[i * N + k] * X[k * N + j];
			}
		}
	}

	free(At);
	free(Bt);
	free(X);

	return C;
}
