#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define SIZE 10
typedef int element;
typedef struct TreeNode { // 트리 노드
	element data;
	struct TreeNode *left, *right;
} TreeNode;
TreeNode *n[SIZE]; // 트리 노드들의 주소들을 저장할 포인터 배열
typedef struct Queue { // 배열 큐
	TreeNode *data;
	int front, rear;
	int maxsize;
	int size;
} Queue;

void queue_init(Queue *q, int sz); int queue_size(Queue *q); int queue_front(Queue *q);
int queue_empty(Queue *q); int queue_full(Queue *q);
void queue_enqueue(Queue *q, element val); void queue_dequeue(Queue *q);
TreeNode *tree_init(void){ // 과제에 주어진 트리대로 초기화 후 해당 트리의 루트 노드 주소 리턴
	int i;
	for(i=0;i<SIZE;i++) n[i] = (TreeNode *)malloc(sizeof(TreeNode));
	*(n[0]) = (TreeNode){ 8, n[1], n[2] };
	*(n[1]) = { 5, n[3], n[4] };
	*(n[2]) = { 4, NULL, n[5] };
	*(n[3]) = { 9, NULL, NULL };
	*(n[4]) = { 7, n[6], n[7] };
	*(n[5]) = { 11, n[8], NULL };
	*(n[6]) = { 1, NULL, NULL };
	*(n[7]) = { 12, n[9], NULL };
	*(n[8]) = { 3, NULL, NULL };
	*(n[9]) = { 2, NULL, NULL };
	return n[0]; // 트리의 루트 노드 주소 리턴
}
void tree_deinit(void){
	int i;
	for(i=0;i<SIZE;i++) free(n[i]);
}
TreeNode *max(TreeNode *root);
TreeNode *min(TreeNode *root);
void level_traversal(TreeNode *root);

int main(void){
	TreeNode *root = tree_init(); // 트리 초기화
	printf("Max element of the tree is %d\n", max(root)->data);
	printf("Min element of the tree is %d\n", min(root)->data);
	printf("Level Traversal of the tree => "); level_traversal(root);
	tree_deinit();	
	return 0;
}

void queue_init(Queue *q,int sz) {
    q->maxsize = sz;
    q->front = 0;
    q->rear = 0;
    q->size = 0;
    q->data = (element *)malloc(q->maxsize * sizeof(element));
}
int queue_size(Queue *q) {
    return q->size;
}
int queue_empty(Queue *q) {
    return queue_size(q) == 0;
}
int queue_full(Queue *q) {
    return q->size == q->maxsize;
}
void queue_enqueue(Queue *q, element val) {
    assert(!queue_full(q));
    q->data[q->rear] = val;
    q->rear = (q->rear + 1) % q->maxsize;
    q->size++;
}
void queue_dequeue(Queue *q) {
    assert(!queue_empty(q));
    q->front = (q->front + 1) % q->maxsize;
    q->size--;
}
element queue_front(Queue *q) {
    assert(!queue_empty(q));
    return q->data[q->front];
}

TreeNode *max(TreeNode *root){
	TreeNode *ret = root;
	Queue q; queue_init(&q, SIZE);
	queue_push(&q, *root);
	while(queue_size(&q)){
		TreeNode *now = queue_front(&q);
		queue_pop(&q);
		ret = ( (ret->data) < (now->data) ) ? now : ret; // 최대값 갖는 노드의 주소 갱신
		if(now->left != NULL) queue_push(&q, now->left);
		if(now->right != NULL) queue_push(&q, now->right);
	}
	return ret;
}

TreeNode *min(TreeNode *root){
	TreeNode *ret = NULL;
	Queue q; queue_init(&q, SIZE);
	queue_push(&q, *root);
	while(queue_size(&q)){
		TreeNode *now = queue_front(&q);
		queue_pop(&q);
		ret = ( (ret->data) > (now->data) ) ? now : ret; // 최소값 갖는 노드의 주소 갱신
		if(now->left != NULL) queue_push(&q, now->left);
		if(now->right != NULL) queue_push(&q, now->right);
	}
	return ret;
}

void level_traversal(TreeNode *root){
	Queue q; queue_init(&q, SIZE);
	queue_push(&q, *root);
	while(queue_size(&q)){
		TreeNode *now = queue_front(&q);
		queue_pop(&q);
		printf("%d ", now->data);
		if(now->left != NULL) queue_push(&q, now->left);
		if(now->right != NULL) queue_push(&q, now->right);
	}	
}
