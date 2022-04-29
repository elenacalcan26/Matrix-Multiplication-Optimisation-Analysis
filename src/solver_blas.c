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

	double *C = (double*)calloc(N * N, sizeof(double));

	if (C == NULL)
		exit(-1);

	// X = A * At, dar aici de fapt se salveaza in A
	cblas_dtrmm(CblasRowMajor, CblasRight, CblasUpper, CblasTrans, CblasNonUnit, N, N, 1.0, A, N, A, N);

	// C = Bt * B
	cblas_dgemm(CblasRowMajor, CblasTrans, CblasNoTrans, N, N, N, 1.0, B, N, B, N, 0.0, C, N);


	// C += B * X
	cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, N, N, N, 1.0, B, N, A, N, 1.0, C, N);

	return C;
}
