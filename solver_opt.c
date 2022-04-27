/*
 * Tema 2 ASC
 * 2022 Spring
 */
#include "utils.h"



/*
 * Add your optimized implementation here
 */
double* my_solver(int N, double *A, double* B) {
	printf("OPT SOLVER\n");
	register int i, j, k;
	double *C = (double *)calloc(N * N, sizeof(double));
	double *X = (double *)calloc(N * N, sizeof(double));
	double *At = (double *)calloc(N * N, sizeof(double));
	double *Bt = (double *)calloc(N * N, sizeof(double));

	if (C == NULL || X == NULL || At == NULL || Bt == NULL)
		exit(-1);

	// se calculeaza transpusa lui B
	for (i = 0; i < N; i++) {
		register double *pB = &B[i * N];
		register double *pBt = &Bt[i];

		for (j = 0; j < N; j++) {
			*pBt = *pB;

			pBt += N;
			pB++;
		}
	}

	// se calculeaza transpusa lui A
	for (i = 0; i < N; i++) {
		register double *pAt = &At[i * N];
		for (j = 0; j <= i; j++) {
			pAt[j] = A[j * N + i];
		}
	}

	// C = Bt * B
	for (i = 0; i < N; i++) {

		register double *orig_pBt = &Bt[i * N];

		for (k = 0; k < N; k++) {

			register double sum = 0;

			register double *pBt = orig_pBt;
			register double  *pB = &B[k];

			for (j = 0; j < N; j++) {
				sum += *pBt * *pB;
				pBt++;
				pB += N;
			}

			C[i * N + k] += sum;
		}
	}

	// X = A * At
	for (i = 0; i < N; i++) {

		register double *orig_pa = &A[i * N + i];

		for (j = 0; j < N; j++) {

			register double sum = 0;

			register double *pA = orig_pa;
			register double *pAt = &At[j + i * N];

			for (k = i; k < N; k++) {
				sum += *pA * *pAt;
				pA++;
				pAt += N;
			}

			X[i * N + j] = sum;
		}
	}

	// C += B * X
	for (i = 0; i < N; i++) {

		register double *orig_pB = &B[i * N];

		for (j = 0; j < N; j++) {

			register double sum = 0;

			register double *pB = orig_pB;
			register double *pX = &X[j];

			for (k = 0; k < N; k++) {
				sum += *pB * *pX;
				pB++;
				pX += N;
			}

			C[i * N + j] += sum;
		}
	}

	return C;
}
