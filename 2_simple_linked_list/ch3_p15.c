/* Count of specified value in Simple Linked List values Chap 3 P.15
 * 2017-2 Data Structure
 * Written by Choe Hyeong Jin, Dept. of Computer Science and Engineering, Univ. of Seoul
 */
 
#include <stdio.h>
#include <stdlib.h>

// Implementation of simple linked list.
typedef int element;
typedef struct ListNode {
  element data;
  struct ListNode *link;
} ListNode;

// function which counts the number of specified-value node in simple linked list.
int count_of_value_in_list(ListNode *head, int x){
  ListNode *p;
  int cnt = 0;
  p = head;
  while( p != NULL ){
    if( p->data == x ) cnt++;
    p = p->link;
  }
  return cnt;
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
  printf("Count of specified value in Simple Linked List = %d\n", count_of_value_in_list(p1, 30));
  return 0;
}