#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

/*N3차원 벡터를 저장할 구조체를 선언 후 두개의 3차원 벡터(V1, V2)를 
입력 받으시오. 두 벡터의 원소별로 곱한 값을 새로운 3차원 벡터 (V3)에 입력 후 이를 출력하는 
프로그램을 작성하시오. 그다음 두 벡터의 내적을 출력하시오.*/

struct vector {
	int x;
	int y;
	int z;
};

int main() {

	struct vector s1;
	struct vector s2;

	scanf("%d %d %d", &s1.x, &s1.y ,& s1.z);
	scanf("%d %d %d", &s2.x, &s2.y ,& s2.z);

	printf("%d %d %d\n", s1.x * s2.x, s1.y * s2.y, s1.z * s2.z);
	printf("%d", (s1.x * s2.x) + (s1.y * s2.y) + (s1.z * s2.z));

	return 0;
}
