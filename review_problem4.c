#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*사용자로부터 공백을 포함하지 않는 문자열을 하나 입력 받아 예제와 같이 왼쪽으로 
한 칸씩 shift하여 출력하는 프로그램을 작성 하시오.*/

int main() {

	char arr[100];
	char temp;
	int i, j;
	int k = 1;

	scanf("%s", arr);
	
	for (i = 0; i < strlen(arr); i++) {
		k = 1;
		j = 0;
		temp = arr[j];
		for (j = 0; j < strlen(arr); j++) {
			if (k == strlen(arr)) {
				break;
			}
			arr[j] = arr[k];
			k++;
		}
		arr[strlen(arr) - 1] = temp;

		printf("%s\n", arr);
	}



	return 0;
}
