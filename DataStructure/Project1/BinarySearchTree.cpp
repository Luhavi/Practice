#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	Node * Left;
	Node * Right;
	int Data;

}Node;

Node * createNode(int data) {
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->Left = NULL;
	newNode->Right = NULL;
	newNode->Data = data;
	return newNode;
}

Node * searchNode(Node * Tree, int findData) {
	//tree가 비어있다면
	if (Tree == NULL) {
		return NULL;
	}

	if (Tree->Data == findData) {
		return Tree;
	}
	else if (Tree->Data > findData) {
		searchNode(Tree->Left, findData);
	}
	else {
		searchNode(Tree->Right, findData);
	}

}

void insertNode(Node * Tree, Node * newNode) {
	if (newNode->Data > Tree->Data) {
		if (Tree->Right != NULL) {
			insertNode(Tree->Right, newNode);
		}
		else {
			Tree->Right = newNode;
		}
	}
	else if (newNode->Data < Tree->Data) {
		if (Tree->Left != NULL) {
			insertNode(Tree->Left, newNode);
		}
		else {
			Tree->Left = newNode;
		}
	}
}

Node * findMinNode(Node*Tree) {
	if (Tree == NULL) {
		return NULL;
	}
	if (Tree->Left != NULL) {
		return findMinNode(Tree->Left);
	}
	else {
		return Tree;
	}
}

Node * removeNode(Node * Tree, int data) {
	Node * tempNode;
	if (Tree == NULL) {
		printf("해당하는 노드를 찾을 수 없습니다.\n");
	}
	else if (Tree->Data > data) {
		Tree->Left = removeNode(Tree->Left, data);
	}
	else if (Tree->Data < data) {
		Tree->Right = removeNode(Tree->Right, data);
	}
	else {
		if (Tree->Left != NULL && Tree->Right != NULL) {
			tempNode = findMinNode(Tree->Right);
			Tree->Data = tempNode->Data;
			Tree->Right = removeNode(Tree->Right, tempNode->Data);
		}
		else {
			tempNode = Tree;
			if (Tree->Left == NULL) {
				Tree = Tree->Right;
			}
			else if (Tree->Right == NULL) {
				Tree = Tree->Left;
				free(tempNode);
			}
		}
	}
	return Tree;
}

void printTree(Node * Tree) {
	if (Tree == NULL) {
		return;
	}
	printTree(Tree->Left);
	printf("%d \t", Tree->Data);
	printTree(Tree->Right);
}

int main() {
	Node * Tree = createNode(10);
	Node * findNode;
	int input;

	insertNode(Tree, createNode(5));
	insertNode(Tree, createNode(1));
	insertNode(Tree, createNode(6));
	insertNode(Tree, createNode(17));
	insertNode(Tree, createNode(14));
	insertNode(Tree, createNode(21));

	while (true)
	{
		scanf_s("%d", &input);
		findNode = searchNode(Tree, input);

		if (findNode != NULL) {
			printf("해당 노드를 찾았습니다! 노드를 제거합니다. 노드의 위치는 %#x 입니다. \n",findNode);
			removeNode(Tree, input);
			printf("현재 트리 출력: ");
			printTree(Tree);
			printf("\n");
		}
		else {
			printf("노드를 찾을 수 없었습니다");
		}
	}
	return 0;
}