/*
 * Tema 2 ASC
 * 2022 Spring
 */
#include "utils.h"

#include "cblas.h"

/*
 * Add your BLAS implementation here
 */
double* my_solver(int N, double *A, double *B) {
	printf("BLAS SOLVER\n");

	double *X = (double*)calloc(N * N, sizeof(double));
	double *C = (double*)calloc(N * N, sizeof(double));

	if (X == NULL || C == NULL)
		exit(-1);

	// X = At * A
	cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasTrans, N, N, N, 1.0, A, N, A, N, 0.0, X, N);


	// C += B * X
	cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, N, N, N, 1.0, B, N, X, N, 0.0, C, N);


	// C+= Bt * B
	cblas_dgemm(CblasRowMajor, CblasTrans, CblasNoTrans, N, N, N, 1.0, B, N, B, N, 1.0, C, N);

	free(X);

	return C;
}
