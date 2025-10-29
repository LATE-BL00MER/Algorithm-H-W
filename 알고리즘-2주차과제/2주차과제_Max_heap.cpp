#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randNum() {
	for (int i = 0; i < 10; i++) {
		int randNumber = (rand() % 100) + 1;
		printf("%d ", randNumber);
	}
	printf("\n");
}

int main() {
	int num = 0;
	srand(time(NULL));

	while (1) {
		printf("메뉴를 선택해 주세요!\n");
		printf("1. 난수 10개 생성 (1 ~ 100)\n");
		printf("2. 생성 난수를 삽입 후 배열로 출력\n");
		printf("3. 프로그램 종료\n");
		scanf("%d", &num);

		switch (num) {
		case 1:
			printf("난수를 10개 생성합니다(1 ~ 100)\n");
			randNum();
			break;
			
		case 2:
			break;

		case 3:
			printf("프로그램을 종료합니다.\n");
			return 0;

		default :
			printf("1,2,3번 중에 골라주세요!\n");
			break;
		}
		printf("\n");
	}
}