#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENT 11 // 힙의 최대 크기(10개 + 1)

typedef struct {
	int key;
} element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType* h) {
	h->heap_size = 0;
}

void insert_max_heap(HeapType* h, element item) {
	int i;
	i = ++(h->heap_size);

	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

void print_heap(HeapType* h) { // 현재 히프 배열을 보여줄 함수
	printf(" (현재 힙 배열): ");
	for (int i = 1; i <= h->heap_size; i++) {
		printf("%d ", h->heap[i].key);
	}
	printf("\n");
}

int main() {
	int num = 0;
	srand(time(NULL));

	HeapType* heap = create();

	int random_numbers[10]; // 난수 10개를 저장할 배열
	int is_generated = 0; // 난수 생성 여부 확인용 플래그 (0: 미생성, 1: 생성됨)

	while (1) {
		printf("메뉴를 선택해 주세요!\n");
		printf("1. 난수 10개 생성 (1 ~ 100)\n");
		printf("2. 생성 난수를 삽입 후 배열로 출력\n");
		printf("3. 프로그램 종료\n");
		printf("입력란>> ");
		scanf("%d", &num);

		switch (num) {
		case 1: // 난수 10개 생성하기 - 1번
			printf("난수를 10개 생성합니다(1 ~ 100)\n");
			for (int i = 0; i < 10; i++) {
				random_numbers[i] = (rand() % 100) + 1;
				printf("%d ", random_numbers[i]);
			}
			printf("\n");
			is_generated = 1;
			break;
			 
		case 2: // 1번에서 생성된 난수를 배열에 순차적으로 삽입
			if (is_generated == 0) {
				printf("오류! 먼저 1번 메뉴에서 난수를 생성해주세요!\n");
				break;
			}

			printf("Max Heap 구성 시작합니다.");
			init(heap); // 히프 초기화

			for (int i = 0; i < 10; i++) {
				element item;
				item.key = random_numbers[i];

				printf("%d 삽입", item.key); // 현재 어떤 숫자가 힙에 삽입되는지 알려줌
				insert_max_heap(heap, item); //max_heap구조로 item을 heap에 삽입
				print_heap(heap); 
				
			}
			printf("Max Heap 구성 완료!\n");
			break;

		case 3:
			printf("프로그램을 종료합니다.\n");
			return 0;

		default:
			printf("1,2,3번 중에 골라주세요!\n");
			break;
		}
		printf("\n");
	}
}
