#include "stdafx.h"

#include <iostream>
#include <string>

#include<vector>
#include<algorithm>
using namespace std;

#include "forCPP.h"
#include "mysort.h"


//#define RecType struct interval

/*
void InsertSort( R[], int n)
{
int i, j, k;
RecType temp;

for (i = 1; i<n; i++)
{
temp = R[i];
j = i - 1;

while (j >= 0 && temp.key<R[j].key)

{

R[j + 1] = R[j];

j--;

}

R[j + 1] = temp;

printf("   i=%d   ", i);

for (k = 0; k<n; k++)

printf("%3d", R[k].key);

printf("\n");

}

*/


int index = 0;  //全局索引变量

//二叉树构造器,按先序遍历顺序构造二叉树
//无左子树或右子树用'#'表示
void treeNodeConstructor(Tree &root, Element data[]){
	Element e = data[index++];
	if(e == '#'){
		root = NULL;
	}else{
		root = (Node *)malloc(sizeof(Node));
		root->data = e;
		treeNodeConstructor(root->lchild, data);  //递归构建左子树
		treeNodeConstructor(root->rchild, data);  //递归构建右子树
	}
}

void visit(Tree root){
	if(root)
		printf("%c", root->data);
	return;
}

void preOrderTraversal(Tree root)
{
	if (root)
	{
		visit(root);
		preOrderTraversal(root->lchild);
		preOrderTraversal(root->rchild);
	}
	return;
}


void inOrderTraversal(Tree root)
{
	if (root)
	{
		inOrderTraversal(root->lchild);
		visit(root);
		inOrderTraversal(root->rchild);
	}
	return;
}


void postOrderTraversal(Tree root)
{
	if (root)
	{
		postOrderTraversal(root->lchild);
		postOrderTraversal(root->rchild);
		visit(root);
	}
	return;
}




/*
//深度优先遍历
void depthFirstSearch(Tree root){
stack<Node *> nodeStack;  //使用C++的STL标准模板库
nodeStack.push(root);
Node *node;
while(!nodeStack.empty()){
node = nodeStack.top();
printf(format, node->data);  //遍历根结点
nodeStack.pop();
if(node->rchild){
nodeStack.push(node->rchild);  //先将右子树压栈
}
if(node->lchild){
nodeStack.push(node->lchild);  //再将左子树压栈
}
}
}

//广度优先遍历
void breadthFirstSearch(Tree root){
queue<Node *> nodeQueue;  //使用C++的STL标准模板库
nodeQueue.push(root);
Node *node;
while(!nodeQueue.empty()){
node = nodeQueue.front();
nodeQueue.pop();
printf(format, node->data);
if(node->lchild){
nodeQueue.push(node->lchild);  
}
if(node->rchild){
nodeQueue.push(node->rchild);  
}
}
}


}
*/


