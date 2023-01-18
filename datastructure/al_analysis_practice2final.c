#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h> 

#define _CRT_SECURE_NO_WARNINGS
/*n × n 비트 행렬 A의 각 행은 1과 0으로만 구성되며, A의 어느 행에서나 1들은 해당 행의 
0들보다 앞서 나온다고 가정하자 행렬 A를 입력받아 가장 , 많은 1을 포함하는 행을 찾는
프로그램을 작성하시오  찾는프로그램 실행시간은 O(n)-시간 */

int mostones(int (*a)[100], int n) { //row 는 행 // column 열
	int i = 0, j = 0;
	int row = 0;
	
	while ((i < n) && (j < n)) {
		if (a[i][j] == 0) {
			i++;
		}
		else {
			row = i;
			j++;
		}
	}
	return row;
}

int main() { 
	int arr[100][100] = { 0, };
	int n;
	int i,j;
	int* p = arr;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	printf("%d", mostones(p, n));
	

	return 0;
}
