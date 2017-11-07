#include <stdio.h>
#include <stdlib.h>
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
	for(i=0;i<SIZE;i++) n[i] = (TreeNode *)malloc(sizeof(TreeNode));
	*(n[0]) = { 8, n[1], n[2] };
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
TreeNode *max(TreeNode *root);
TreeNode *min(TreeNode *root);
void level_traversal(TreeNode *root);

int main(void){
	TreeNode *root = tree_init(); // 트리 초기화
	printf("Max element of the tree is %d\n", max(root)->data);
	printf("Min element of the tree is %d\n", min(root)->data);
	printf("Level Traversal of the tree => "); level_traversal(root);
	return 0;
}

TreeNode *max(TreeNode *root){
	
}

TreeNode *min(TreeNode *root){

}

void level_traversal(TreeNode *root){
	TreeNode *current = root;
	Queue q; queue_init(&q, SIZE);
	queue_push(&q, *current);
	
}
