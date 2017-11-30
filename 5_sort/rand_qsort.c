/* 2017-2 Data Structure
 * Written by Choe Hyeong Jin, Dept. of CSE, Univ. of Seoul
 * 프로그램 과제
 * 난수 생성 함수를 이용하여 1~10000 사이의 정수를 50개 생성하여
 * 1차원 배열에 저장한 후, 퀵 정렬 알고리즘으로 오름차순 정렬하는
 * 프로그램을 작성하시오.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10000
#define SIZE 50

void swap(int* a, int* b){
	int tmp = *a;
	*a = *b; *b = tmp;
}

int partition(int P[], int left, int right){
	int low = left, high = right+1;
	int pivot = P[left]; 					// 피봇 설정
	do{
		do{ 								// 왼쪽 리스트에서 피봇보다 큰 레코드 선택
			low++;
		} while(low<=right && P[low] < pivot);
		do{ 								// 오른쪽 리스트에서 피봇보다 작은 레코드 선택
			high--;
		} while(high>=left && P[high] > pivot);
		if(low<high) swap(&P[low], &P[high]); // 선택된 두 레코드 교환
	} while(low<high); 						// 인덱스 low, high가 엇갈리지 않는 한 반복
	swap(&P[left], &P[high]); 				// 인덱스 high가 가리키는 레코드와 피봇 교환
	return high; 							// 피봇의 최종 위치 리턴
}

void quick_sort(int data[], int left, int right){
	if(left<right){ 						// 인덱스 left, right가 엇갈리지 않을 때
		int q=partition(data, left, right); // 분할
		quick_sort(data, left, q-1); 		// 왼쪽 리스트에 퀵소트 재귀호출
		quick_sort(data, q+1, right); 		// 오른쪽 리스트에 퀵소트 재귀호출
	}
}

void print_array(int* array, int size){
	int i;
	for(i=0;i<size;i++){
		if(i!=0 && i%10==0) printf("\n");
		printf("%4d ", array[i]);
	}
	printf("\n");
}

int main(){
	int i=0;
	int* data = (int*)malloc(sizeof(int)*SIZE); // SIZE 크기의 int 배열 동적 할당
	
	srand(time(NULL)); 							// seed값 사용.
	while(i < SIZE)
		data[i++] = (1 + rand()) % (MAX + 1); 	// 1~MAX 사이의 정수를 SIZE개 생성
	
	printf("Before quick_sort()...\n");
	print_array(data, SIZE);
	
	quick_sort(data, 0, SIZE-1); 					// quick_sort() 호출

	printf("After quick_sort()...\n");
	print_array(data, SIZE);

	return 0;	
}
