/* 2017-2 Data Structure
 * Baekjoon Problem 10845 : Queue
 * Written by Choe Hyeong Jin, Dept. of CSE, Univ. of Seoul
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;
typedef struct QueueNode {
	element data;
	struct QueueNode *link;
} QueueNode;

typedef struct LinkedQueueType {
	QueueNode *front;
	QueueNode *rear;
	int size;
} LinkedQueueType;

QueueNode *new_queue_node(element x){
	QueueNode *qn = (QueueNode *)malloc(sizeof(QueueNode));
	qn->data = x;
	qn->link = NULL;
	return qn;
}

LinkedQueueType *new_linked_queue_type(){
	LinkedQueueType *q = (LinkedQueueType *)malloc(sizeof(LinkedQueueType));
	q->front = NULL;
	q->rear = NULL;
 	q->size = 0;
	return q;
}

int queue_empty(LinkedQueueType *q){
	if(q->front == NULL && q->rear == NULL){
		return 1;
	}
	else return 0;
}

int queue_size(LinkedQueueType *q){
	return q->size;
}

void queue_push(LinkedQueueType *q, QueueNode *qn){
	if(q->front == NULL){
		q->front = qn;
		q->rear = qn;
	}
	else{
		q->rear->link = qn;
		q->rear = qn;
	}
	(q->size)++;
}

void queue_pop(LinkedQueueType *q){
	if(queue_empty(q)){
		perror("Queue is empty!");
	}
	else{
		QueueNode *tmp = q->front;
		if(q->front != q->rear){
			q->front = q->front->link;
		}
		else{
			q->front = NULL;
			q->rear = NULL;
		}
		(q->size)--;
		free(tmp);
	}
}

element queue_front(LinkedQueueType *q){
	if(queue_empty(q)){
		perror("Queue is empty!");
		return -1;
	}
	else{
		return q->front->data;
	}
}

element queue_rear(LinkedQueueType *q){
	if(queue_empty(q)){
		perror("Queue is empty!");
		return -1;
	}
	else{
		return q->rear->data;
	}
}

int main(void){
	int N, i;
	element x;
	char cmd[6];
	
	LinkedQueueType *q = new_linked_queue_type();
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%s",cmd);
		if(!strcmp(cmd, "push")){
			scanf("%d", &x);
			queue_push(q, new_queue_node(x));
		}
		else if(!strcmp(cmd, "pop")){
			if(queue_empty(q)){
				printf("-1\n");
			}
			else{
				printf("%d\n",queue_front(q));
				queue_pop(q);
			}
		}
		else if(!strcmp(cmd, "size")){
			printf("%d\n",q->size);
		}
		else if(!strcmp(cmd, "empty")){
			printf("%d\n",queue_empty(q));
		}
		else if(!strcmp(cmd, "front")){
		  if(queue_empty(q)){
		    printf("-1\n");
		  }
			else printf("%d\n",queue_front(q));
		}
		else if(!strcmp(cmd, "back")){
			if(queue_empty(q)){
			  printf("-1\n");
			}
			else printf("%d\n",queue_rear(q));
		}
	}
	return 0;
}
