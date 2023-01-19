#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h> 

#define _CRT_SECURE_NO_WARNINGS
/*원시 데이터값들로 구성된 배열 X의 i-번째 누적평균(prefix average)이란 X의 i-번째에 
이르기까지의 (i + 1)개 원소들의 평균이다 즉. ,
A[i] = (X[0] + X[1] + … + X[i])/(i + 1)
누적평균은 경제 통계 , 분야에서 오르내림 변동을 순화시킴으로써 대략적 추세를 얻어내기 위해 
사용된다 일례로 . 부동산 주, 식 펀, 드 등에도 자주 활용된다 이..  문제는 배열 X의 누적평균(prefix 
average) 배열 A를 구하는 프로그램을 구현하고 테스트하는데 관한 것이다.*/

int main() { //prefixAverages1
	int n;
	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);
	int sum = 0;

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int j = 0; j < i+1; j++) {
			sum = arr[j] + sum;
		}
		arr[i] = sum / (i + 1);
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}

	free(arr);
}
//테스트값 6  // 1 3 2 10 6 8
