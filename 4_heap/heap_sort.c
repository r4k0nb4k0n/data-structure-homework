/* 2017-2 Data Structure
 * Ascending sort using Heap Sort
 * Written by Choe Hyeong Jin, Dept. of CSE, Univ. of Seoul
 */

#include <stdio.h>

void swap(int* u, int* v){
  int tmp = *u;
  *u = *v; *v = tmp;
}

// 루트가 노드 i인 서브트리를 최대 힙으로 만드는 함수
void max_heapify(int arr[], int n, int i){
  int biggest = i; // biggest를 root로 초기화
  int left = 2 * i + 1; // left child (i>=0)
  int right = 2 * i + 2; // right child (i>=0)
  
  // 만약 left child가 root보다 더 크다면
  if(left < n && arr[left] > arr[biggest])
    biggest = left; // biggest를 left로
  // 만약 right child가 root보다 더 크다면
  if(right < n && arr[right] > arr[biggest])
    biggest = right; // biggest를 right로
  // 만약 biggest가 root가 아니라면
  if(biggest != i){
    swap(&arr[i], &arr[biggest]);
    // 재귀적으로 서브트리를 힙으로 만든다.
    max_heapify(arr, n, biggest);
  }
}

// 최대 힙 생성 (재배열)
void build_max_heap(int arr[], int n){
  for(int i=n/2-1; i>=0; i--)
    max_heapify(arr, n, i);
}
 
// 힙 소트를 하는 주 함수
void heap_sort(int arr[], int n){
  // 최대 힙 생성 (재배열)
  build_max_heap(arr, n);
  // 힙에서 노드 하나씩 추출
  for(int i=n-1;i>=0;i--){
    // 현재 root(현재 힙에서 가장 큰 값의 노드)를 끝으로 옮김
    swap(&arr[0], &arr[i]);
    // 감소된 힙을 다시 최대 힙으로 재배열
    max_heapify(arr, i, 0);
  }
}

void print_array(int arr[], int n){
  for(int i=0;i<n;++i)
    printf("%d ", arr[i]);
  printf("\n");
}

int main(){
  // 배열 초기화
  int arr[] = {30, 10, 69, 2, 16, 8, 31, 22};
  // 배열 사이즈 저장
  int n = sizeof(arr) / sizeof(arr[0]);
  
  printf("Before heap_sort()...\n");
  print_array(arr, n);
  
  heap_sort(arr, n);

  printf("After heap_sort()...\n");
  print_array(arr, n);

  return 0;
}
