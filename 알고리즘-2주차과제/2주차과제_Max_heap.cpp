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
		printf("�޴��� ������ �ּ���!\n");
		printf("1. ���� 10�� ���� (1 ~ 100)\n");
		printf("2. ���� ������ ���� �� �迭�� ���\n");
		printf("3. ���α׷� ����\n");
		scanf("%d", &num);

		switch (num) {
		case 1:
			printf("������ 10�� �����մϴ�(1 ~ 100)\n");
			randNum();
			break;
			
		case 2:
			break;

		case 3:
			printf("���α׷��� �����մϴ�.\n");
			return 0;

		default :
			printf("1,2,3�� �߿� ����ּ���!\n");
			break;
		}
		printf("\n");
	}
}