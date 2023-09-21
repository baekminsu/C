#include <stdio.h>

int main() {
	int A[10][10];
	int B[10][10];
	int result[10][10];
	int n;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			scanf("%d", &n);
			A[i][j] = n;
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			scanf("%d", &n);
			B[i][j] = n;
		}
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			result[i][j] = 0;
		}
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j ++ ) {
			for (int k = 0; k < 10; k++) {
				result[i][j] += A[i][k] * B[k][j];
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}
	
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			result[i][j] = 0;
		}
	}


	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				result[i][j] += B[i][k] * A[k][j];
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}
	
	
	return 0;
}
/*
1 0 0 0 0 0 0 0 0 0
0 1 0 0 0 0 0 0 0 0
0 0 1 0 0 0 0 0 0 0
0 0 0 1 0 0 0 0 0 0
0 0 0 0 1 0 0 0 0 0
0 0 0 0 0 1 0 0 0 0
0 0 0 0 0 0 1 0 0 0
0 0 0 0 0 0 0 1 0 0
0 0 0 0 0 0 0 0 1 0
0 0 0 0 0 0 0 0 0 1
5 7 1 2 3 7 2 4 6 1
2 7 0 0 0 0 0 0 0 8
3 0 9 0 0 0 0 0 0 7
4 0 0 4 0 0 0 0 0 6
5 0 0 0 3 0 0 0 0 5
6 0 0 0 0 2 0 0 0 4
3 0 0 0 0 0 7 0 0 3
4 0 0 0 0 0 0 9 0 2
5 0 0 0 0 0 0 0 6 1
7 1 2 4 5 6 7 3 6 7
*/
