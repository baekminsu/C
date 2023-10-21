#include <stdio.h>
#include <stdlib.h> 
#define _crt_secure_no_warnings
#pragma warning(disable:4996)

int findElement(int a, int b, int YN, char* input) {
	int mid;
	int k = 0, i = 0;
	while (1) {
		mid = (a + b) / 2;
		if (a == b) {
			k = mid;
			break;
		}

		if (input[i] == 'Y') {
			a = mid + 1;
		}
		else {
			b = mid;
		}
		i++;
	}
	return k;
}


int main() {

	int a, b, YN;
	char* input;
	scanf("%d %d %d", &a, &b, &YN);
	input = (char*)malloc(sizeof(char) * (YN+1));
	scanf("%s", input);
	int result;

	result = findElement(a, b, YN, input);

	printf("%d", result);
	free(input);

	return 0;
}
