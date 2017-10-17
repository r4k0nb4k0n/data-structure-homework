/* alternate Chap 3 P.18
 * 2017-2 Data Structure
 * Written by Choe Hyeong Jin, Dept. of Computer Science and Engineering, Univ. of Seoul
 */

#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
  element data;
  struct ListNode *link;
} ListNode;

ListNode *alternate(ListNode *p, ListNode *q){
  ListNode *p_now = p; ListNode *q_now = q;
  ListNode *ret = (ListNode *)malloc(sizeof(ListNode));
  ListNode *tmp = ret; // 리턴할 리스트의 시작주소 유지하기 위해 따로 복사
  int sw = 1; // p, q 전환 스위치. p일 때는 1, q일 때는 -1. 시작은 p부터 하기 위해 1로 초기화.
  int xor_sw = 1; // xor 연산 처음 참일 때만 조건문이 참이 되도록 1로 초기화.
  while( !((p_now == NULL) && (q_now == NULL)) ){
    if(sw == 1){ // p일 때
      tmp->data = p_now->data; // p의 현재 노드 값 복사.
      p_now = p_now->link; // p의 다음 노드로 포인터 이동.
    }
    else{ // q일 때
      tmp->data = q_now->data; // q의 현재 노드 값 복사.
      q_now = q_now->link; // q의 다음 노드로 포인터 이동.
    }
    // p 또는 q의 다음 노드가 존재할 때만 스위치 전환.
    // p 또는 q의 다음 노드가 존재하지 않으면 (NULL) 스위치 전환하지 않음.
    if( ((p_now != NULL) && (q_now != NULL)) ) sw = sw * (-1);
    // p 또는 q의 다음 노드가 둘 중 하나만 존재하고, 이 조건을 처음 만족한다면 스위치를 한번 더 전환하고 해당 조건문이 참이 되지 않도록 xor_sw에 0 저장.
    if( (((p_now != NULL) ^ (q_now != NULL)) == 1) && (xor_sw == 1) ) { sw = sw * (-1); xor_sw = 0; }
    // p와 q의 다음 노드가 존재하지 않으면, 즉 p와 q의 모든 노드를 다 탐색했다면
    if( ((p_now == NULL) && (q_now == NULL)) ) tmp->link = NULL; // 리턴할 리스트의 끝의 link에 NULL값 넣기.
    else{ // 아직 p와 q의 모든 노드를 다 탐색하지 않았고, 탐색할 노드들이 남았다면
      tmp->link = (ListNode *)malloc(sizeof(ListNode)); // 리턴할 리스트의 끝에 새 리스트 노드 생성.
      tmp = tmp->link; // 리턴할 리스트 다음 노드로 포인터 이동.
    }
  }
  return ret;
}

void print_list(ListNode *head){
  ListNode *p = head;
  while( p != NULL ){
    printf("%d->", p->data);
    p = p->link;
  }
  printf("NULL\n");
}

int main(){
  ListNode *p1 = (ListNode *)malloc(sizeof(ListNode));
  ListNode *p2 = (ListNode *)malloc(sizeof(ListNode));
  ListNode *p3 = (ListNode *)malloc(sizeof(ListNode));
  ListNode *p4 = (ListNode *)malloc(sizeof(ListNode));
  ListNode *p5 = (ListNode *)malloc(sizeof(ListNode));
  p1->data = 10; p1->link = p2;
  p2->data = 20; p2->link = p3;
  p3->data = 30; p3->link = p4;
  p4->data = 30; p4->link = p5;
  p5->data = 30; p5->link = NULL;
  ListNode *q1 = (ListNode *)malloc(sizeof(ListNode));
  ListNode *q2 = (ListNode *)malloc(sizeof(ListNode));
  ListNode *q3 = (ListNode *)malloc(sizeof(ListNode));
  q1->data = 100; q1->link = q2;
  q2->data = 200; q2->link = q3;
  q3->data = 300; q3->link = NULL;
  print_list(p1);
  print_list(q1);
  ListNode *r = alternate(p1, q1);
  print_list(r);
  return 0;
}