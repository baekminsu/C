#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define N 8
#define _crt_secure_no_warnings
#pragma warning(disable:4996)  

int main() {

	//int N;
	int col;
	double matrix[8][8];
	//printf("input N number: ");
	//scanf("%d", &N);
	printf("input 1.DCT 2.DST :");
	scanf("%d", &col);
	double alpha;
	double u = 0;
	// matrix[i*N+j]
	if (col == 1) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i == 0) {
					alpha = 1.0 / sqrt(N);
				}
				else {
					alpha = sqrt(2.0 / N);
				}
				matrix[i][j] = alpha * cos((((2 * j) + 1) * (u * 3.141592)) / (N * 2));
			}
			u += 1.0;
		}
	}
	else if (col == 2) {
		alpha = 2.0 / sqrt((2 * N) + 1);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {

				matrix[i][j] = alpha * sin(  (  (j + 1) * ( ( (u*2)+1 ) * 3.141592   )) /  ((N * 2) +1) );
			}
			u += 1.0;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf(" %.4f", matrix[i][j]);
		}
		printf("\n");
	}

	return 0;
}
