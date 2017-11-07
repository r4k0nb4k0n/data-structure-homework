#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
typedef int element;
typedef struct TreeNode {
	element data;
	struct TreeNode *left, *right;
} TreeNode;
TreeNode *n[SIZE];

TreeNode *init(void){
	
}
TreeNode max(TreeNode *root);
TreeNode min(TreeNode *root);
TreeNode level_traversal(TreeNode *root);

int main(void){
	TreeNode *n[SIZE], ;
	int i;

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

