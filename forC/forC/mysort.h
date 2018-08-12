#pragma once

using namespace std;

#define Element char


typedef struct Node {
	Element data;
	struct Node *lchild;
	struct Node *rchild;
} *Tree;

/*
struct Node {
	Element data;
	struct Node *lchild;
	struct Node *rchild;
}
*/

void visit(Tree root);

void preOrderTraversal(Tree root);
void inOrderTraversal(Tree root);
void postOrderTraversal(Tree root);



void treeNodeConstructor(Tree &root, Element data[]);
