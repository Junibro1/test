#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

typedef struct Node {
	int data;
	struct Node* left;
	struct Node* right;
}node;

void create(node* Tree, int Parent_data, int Left_data, int Right_data);
void PreOrder(node* root, int Parent_data, int Left_data, int Right_data);
void explore(node* root, char* Direction);
void delete(node* root);

int main(void) {
	node* root = (node*)malloc(sizeof(node));
	if (root == NULL) return -1;

	int n, m, p, l, r;// 노드의 개수, 탐색의 개수, 부모, 왼쪽자식, 오른쪽 자식

	scanf("%d", &n);
	scanf("%d %d %d", &p, &l, &r);
	root->data = p;
	PreOrder(root, p, l, r);
	for (int i = 0; i < n - 1; i++) {
		scanf("%d %d %d", &p, &l, &r);
		PreOrder(root, p, l, r);
	}
	char dir[100];


	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%s", dir);
		printf(" %d", root->data);
		explore(root, dir);
	}

	delete(root);

	return 0;
}

void create(node* Tree, int Parent_data, int Left_data, int Right_data) {
	Tree->data = Parent_data;

	if (Left_data != 0) {
		node* tmp_l = (node*)malloc(sizeof(node));

		Tree->left = tmp_l;
		tmp_l->data = Left_data;
		tmp_l->left = NULL;
		tmp_l->right = NULL;
	}
	else
		Tree->left = NULL;
	if (Right_data != 0) {
		node* tmp_r = (node*)malloc(sizeof(node));

		Tree->right = tmp_r;
		tmp_r->data = Right_data;
		tmp_r->left = NULL;
		tmp_r->right = NULL;
	}
	else
		Tree->right = NULL;
}
void PreOrder(node* root, int Parent_data, int Left_data, int Right_data) {
	if (root != NULL) {
		if (root->data == Parent_data) {
			create(root, Parent_data, Left_data, Right_data);
			return;
		}
		PreOrder(root->left, Parent_data, Left_data, Right_data);
		PreOrder(root->right, Parent_data, Left_data, Right_data);
	}
}
void explore(node* root, char* Direction) {
	if (Direction[0] == 'L') {
		printf(" %d", root->left->data);
		explore(root->left, Direction + 1);
	}
	if (Direction[0] == 'R') {
		printf(" %d", root->right->data);
		explore(root->right, Direction + 1);
	}
	printf("\n");
}
void delete(node* root) {
	if (root != NULL) {
		delete(root->left);
		delete(root->right);
		free(root);
	}
}

/*
9
5 3 9
3 8 15
8 0 2
2 0 0
15 0 0
9 7 10
7 12 0
12 0 0
10 0 0
3
RLL
LL
LR
*/