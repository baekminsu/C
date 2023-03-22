#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

/*
사용자로부터 정수 한 개를 입력받는다. 이것을 N 이라고 하자. N은 홀
수라고 가정한다. 정수 N개를 저장할 수 있는 메모리를 동적 할당한 후에, 이 메모리에 0부터
N-1 까지 정수를 저장한다 (0 1 2 ... N-1). 이 배열의 중간에 위치한 값을 제외한 나머지 값들을
순서대로, M (N-1)개 새로 동적할당된 메모리에 대입한 후 출력한다.
*/

int main() {

	int N;
	int* arr;
	int i = 1;
	int j = 1;
	scanf("%d", &N);

	arr = (int*)malloc(sizeof(int) * N);

	arr[0] = 0;

	while (1) {  
		if (i >= N) {
			break;
		}
		arr[j] = i;
		if ((N / 2) == i) {
			i++;
			continue;
		}	
			j++;
			i++;
	}

	for (int k = 0; k < N-1; k++) {
		printf(" %d", arr[k]);
	}


	free(arr);

	return 0;
}
