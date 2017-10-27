/* 2017-2 Data Structure
 * Baekjoon Problem 10866 : Deque
 * Written by Choe Hyeong Jin, Dept. of CSE, Univ. of Seoul
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;
typedef struct DequeNode {
	element data;
	struct DequeNode *flink;
	struct DequeNode *rlink;
} DequeNode;

typedef struct LinkedDequeType {
	DequeNode *front;
	DequeNode *rear;
	int size;
} LinkedDequeType;

DequeNode *new_deque_node(element x){
	DequeNode *dqn = (DequeNode *)malloc(sizeof(DequeNode));
	dqn->data = x;
	dqn->flink = NULL;
	dqn->rlink = NULL;
	return dqn;
}

LinkedDequeType *new_linked_deque_type(){
	LinkedDequeType *dq = (LinkedDequeType *)malloc(sizeof(LinkedDequeType));
	dq->front = NULL;
	dq->rear = NULL;
	dq->size = 0;
	return dq;
}

int deque_empty(LinkedDequeType *dq){
	if(dq->front == NULL && dq->rear == NULL){
		return 1;
	}
	else return 0;
}

int deque_size(LinkedDequeType *dq){
	return dq->size;
}

element deque_front(LinkedDequeType *dq){
	if(deque_empty(dq)){
		return -1;
	}
	else{
		return dq->front->data;
	}
}

element deque_back(LinkedDequeType *dq){
	if(deque_empty(dq)){
		return -1;
	}
	else{
		return dq->rear->data;
	}
}

void deque_push_front(LinkedDequeType *dq, DequeNode *dqn){
	if(deque_empty(dq)){
		dq->front = dqn;
		dq->rear = dqn;
	}
	else{
		dqn->rlink = dq->front;
		dq->front->flink = dqn;
		dq->front = dqn;
	}
	dq->size++;
}

void deque_push_back(LinkedDequeType *dq, DequeNode *dqn){
	if(deque_empty(dq)){
		dq->front = dqn;
		dq->rear = dqn;
	}
	else{
		dqn->flink = dq->rear;
		dq->rear->rlink = dqn;
		dq->rear = dqn;
	}
	dq->size++;
}

void deque_pop_front(LinkedDequeType *dq){
	if(dq->front == dq->rear){
		free(dq->front);
		dq->front = NULL;
		dq->rear = NULL;
	}
	else{
		DequeNode *tmp = dq->front;
		dq->front = dq->front->rlink;
		free(tmp);
	}
	dq->size--;
}

void deque_pop_back(LinkedDequeType *dq){
	if(dq->front == dq->rear){
		free(dq->front);
		dq->front = NULL;
		dq->rear = NULL;
	}
	else{
		DequeNode *tmp = dq->rear;
		dq->rear = dq->rear->flink;
		free(tmp);
	}
	dq->size--;
}

int main(){
	int N, i;
	element x;
	char cmd[11];
	LinkedDequeType *dq = new_linked_deque_type();
	scanf("%d", &N);

	for(i=0;i<N;i++){
		scanf("%s",cmd);
		if(!strcmp(cmd, "push_front")){
			scanf("%d",&x);
			deque_push_front(dq, new_deque_node(x));
		}
		else if(!strcmp(cmd, "push_back")){
			scanf("%d",&x);
			deque_push_back(dq, new_deque_node(x));
		}
		else if(!strcmp(cmd, "pop_front")){
			if(deque_empty(dq)){
				printf("-1\n");
			}
			else{
				printf("%d\n",deque_front(dq));
				deque_pop_front(dq);
			}
		}
		else if(!strcmp(cmd, "pop_back")){
			if(deque_empty(dq)){
				printf("-1\n");
			}
			else{
				printf("%d\n",deque_back(dq));
				deque_pop_back(dq);
			}
		}
		else if(!strcmp(cmd, "size")){
			printf("%d\n",dq->size);
		}
		else if(!strcmp(cmd, "empty")){
			printf("%d\n",deque_empty(dq));
		}
		else if(!strcmp(cmd, "front")){
			printf("%d\n",deque_front(dq));
		}
		else if(!strcmp(cmd, "back")){
			printf("%d\n",deque_back(dq));
		}
	}
	return 0;
}
