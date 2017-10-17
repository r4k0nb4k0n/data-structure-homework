/* Sum of Simple Linked List values Chap 3 P.14
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

// function that returns the sum of all values in simple linked list.
int sum_of_list(ListNode *head){
  int sum = 0;
  ListNode *p;
  p = head;
  while( p != NULL ){
    sum = sum + p->data;
    p = p->link; // move pointer to next node.
  }
  return sum;
}

// TEST
int main(){
  ListNode *p1 = (ListNode *)malloc(sizeof(ListNode));
  ListNode *p2 = (ListNode *)malloc(sizeof(ListNode));
  ListNode *p3 = (ListNode *)malloc(sizeof(ListNode));
  p1->data = 10; p1->link = p2;
  p2->data = 20; p2->link = p3;
  p3->data = 30; p3->link = NULL;
  printf("Sum of Simple Linked List = %d\n", sum_of_list(p1));
  return 0;
}
