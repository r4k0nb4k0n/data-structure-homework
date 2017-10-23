/* Sum of Polynomials Chap 3 P.23
 * 2017-2 Data Structure
 * Written by Choe Hyeong Jin, Dept. of Computer Science and Engineering, Univ. of Seoul
 */

#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct PolyNode {
  element coef;
  element expo;
  struct PolyNode *link;
} PolyNode;

PolyNode *add_polynomial(PolyNode *p, PolyNode *q){ // 두 다항식의 합 리턴하는 함수
  PolyNode *p_now = p; PolyNode *q_now = q;
  PolyNode *ret = (PolyNode *)malloc(sizeof(PolyNode));
  PolyNode *tmp = ret; // 리턴할 리스트의 시작주소 유지하기 위해 따로 복사
  while( !((p_now == NULL) && (q_now == NULL)) ){
    // 리스트 q만 끝에 도달했거나, 리스트 p와 q 현재 노드 존재하고 p의 현재 항의 차수가 q의 현재 항의 차수보다 크다면
    if( ( p_now != NULL && q_now == NULL ) || ( (p_now != NULL && q_now != NULL) && (p_now->expo > q_now->expo) ) ){
      tmp->coef = p_now->coef; tmp->expo = p_now->expo; // p의 현재 항 계수와 차수 복사
      p_now = p_now->link; // 리스트 p 다음 노드로 포인터 이동
    }
    // 리스트 p만 끝에 도달했거나, 리스트 p와 q 현재 노드 존재하고 p의 현재 항의 차수가 q의 현재 항의 차수보다 작다면
    else if( ( p_now == NULL && q_now != NULL ) || ( (p_now != NULL && q_now != NULL) && (p_now->expo < q_now->expo) ) ){
      tmp->coef = q_now->coef; tmp->expo = q_now->expo; // q의 현재 항 계수와 차수 복사
      q_now = q_now->link; // 리스트 q 다음 노드로 포인터 이동
    }
    // 리스트 p와 q 현재 노드 존재하고 p의 현재 항의 차수와 q의 현재 항의 차수가 서로 같다면
    else if( (p_now != NULL && q_now != NULL) && (p_now->expo == q_now->expo) ){
      tmp->coef = p_now->coef + q_now->coef; // p와 q의 현재 항의 계수의 합 저장
      tmp->expo = p_now->expo; // 현재 항의 차수가 서로 같으므로 p 또는 q 둘 중 하나의 차수만 저장
      p_now = p_now->link; // 리스트 p 다음 노드로 포인터 이동
      q_now = q_now->link; // 리스트 q 다음 노드로 포인터 이동
    }
    if( p_now == NULL && q_now == NULL ){ // 리스트 p와 q 둘다 끝에 도달했다면
      tmp->link = NULL; // 리턴할 리스트 끝의 link에 NULL값 넣기
    }
    else{ // 리스트 p 또는 q에 탐색할 노드가 남아있다면
      tmp->link = (PolyNode *)malloc(sizeof(PolyNode)); // 리턴할 리스트 끝에 새 리스트 노드 생성
      tmp = tmp->link; // 리턴할 리스트 다음 노드로 포인터 이동.
    }
  }
  return ret;
}

void print_polynomial(PolyNode *head){ // 다항식 출력하는 함수
  PolyNode *p = head;
  while( p != NULL ){
    if( p->expo == 0 ){ // 현재 항이 상수라면
      printf("%+d", p->coef);
    }
    else if( p->coef == 0 ){ // 현재 항의 계수가 0이라면
      // Do nothing...
    }
    else{
      printf("%+dx^(%d)", p->coef, p->expo);
    }
    p = p->link; // 다음 노드로 포인터 이동
  }
}

int main(){
  //A(x)=3x^(6)+7x^(3)-2x^(2)-9, B(x)=-2x^(6)-4x^(4)+6x^(2)+6x^(1)+1
  PolyNode *a1 = (PolyNode *)malloc(sizeof(PolyNode));
  PolyNode *a2 = (PolyNode *)malloc(sizeof(PolyNode));
  PolyNode *a3 = (PolyNode *)malloc(sizeof(PolyNode));
  PolyNode *a4 = (PolyNode *)malloc(sizeof(PolyNode));
  a1->coef = 3; a1->expo = 6; a1->link = a2;
  a2->coef = 7; a2->expo = 3; a2->link = a3;
  a3->coef = -2; a3->expo = 2; a3->link = a4;
  a4->coef = -9; a4->expo = 0; a4->link = NULL;
  PolyNode *b1 = (PolyNode *)malloc(sizeof(PolyNode));
  PolyNode *b2 = (PolyNode *)malloc(sizeof(PolyNode));
  PolyNode *b3 = (PolyNode *)malloc(sizeof(PolyNode));
  PolyNode *b4 = (PolyNode *)malloc(sizeof(PolyNode));
  PolyNode *b5 = (PolyNode *)malloc(sizeof(PolyNode));
  b1->coef = -2; b1->expo = 6; b1->link = b2;
  b2->coef = -4; b2->expo = 4; b2->link = b3;
  b3->coef = 6; b3->expo = 2; b3->link = b4;
  b4->coef = 6; b4->expo = 1; b4->link = b5;
  b5->coef = 1; b5->expo = 0; b5->link = NULL;
  printf("A(x) = "); print_polynomial(a1); printf("\n");
  printf("B(x) = "); print_polynomial(b1); printf("\n");
  PolyNode *c = add_polynomial(a1, b1);
  printf("C(x) = A(x) + B(x) = "); print_polynomial(c); printf("\n");
  return 0;
}
