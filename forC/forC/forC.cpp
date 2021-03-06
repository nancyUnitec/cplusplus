﻿// forC.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<string.h> 

#include<stdio.h> 
#include<conio.h> 

#include "forCPP.h"
#include "leetcode.h"
#include "playground.h"
#include "lintCode.h"

#include "mysort.h"



void test(char **p);
void showTheSizeOfBlock();
void switchChars(char *str, int step);
void memcpyChars(char *str, int step);

void *getInstance(int userInput);

void testInput();




void nzp(int v);
int testPassByArrayElement();

float aver(float a[5]);
int testPassByArrayName();

int test2DimArray();
//int op2DimArray(int **);
int op2DimArray(int p[][4]);


int solution(int n);

void preVSfollow();

bool isPalindrome(int x);
int reverse(int x);
int removeDuplicates(int* nums, int numsSize);

int main()
{
	printf("hello, vc++");

	//char str3[10];
	//str3 = "it315.org";   //error:expression must be a modifiable lvalue
		
	char *pstr;
	
	char *pchar = NULL;
	char **pp = &pchar;

    test(pp);

	char *p12 = NULL;
	int s12 = sizeof(p12);

	char *p121 = new char[100];
	int s121 = sizeof(p121);

	//showTheSizeOfBlock();

	char *swc = "abcde";
	switchChars(swc, 2);

	char *mcc = "abcdefghi";
	memcpyChars(mcc, 2);

	//withCC base;
	//base.showCallOrder();

	subCC sub;
	sub.showCallOrder();


	void *testVirtual = NULL;
	
	//testVirtual = getInstance(input);
	//testVirtual->showCallOrder();

	//swapCharByArray();
	//testInput();

	

	//testMalloc();

	//testNew();

	//testPassByArrayElement();
	//testPassByArrayName();

	test2DimArray();

	//solution(10);
	//preVSfollow();

	//isPalindrome(10001);

	/*
	reverse(9);
	reverse(931);
	reverse(460);
    */

	testLeetCode();

	//runPlayground();

	//testLintCode();

	//Element data[15] = { 'A', 'B', 'D', '#', '#', 'E', '#', '#', 'C', 'F','#', '#', 'G', '#', '#' };
	//Tree tree;
	//treeNodeConstructor(tree, data);
	/* the tree's shape is like this:
	    A
	   /  \
	  B    C
	 / \   / \
	D   E  F  G
	
	*/

	//preOrderTraversal(tree);  // ABDECFG
	//inOrderTraversal(tree); //DBEAFCG
	//postOrderTraversal(tree);  //DEBFGCA

	return 0;
}




#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void print_array(int *a, int n)
{
	int i;

	for (i = n - 1; i >= 0; --i) {
		printf("%d", a[i]);
	}
	printf("\n");
}

int solution(int n)
{
	int *curr, *tmp;
	int tmp_len;
	int *p;
	int carry = 0;
	int i, j;
	int size = n;
	int count = 0;

	curr = (int *)malloc(sizeof(int) * size);
	if (!curr) {
		printf("Out of memory.\n");
		return -1;
	}

	tmp = (int *)malloc(sizeof(int) * size);
	if (!tmp) {
		free(curr);
		printf("Out of memory.\n");
		return -1;
	}

	for (i = 0; i < size; ++i) {
		curr[i] = -1;
		tmp[i] = -1;
	}

	tmp_len = 0;
	for (i = 0; i < n; ++i) {
		printf("i = %d \n\n", i);
		carry = 0;
		curr[0] = 1;

		for (j = 1; j < tmp_len; ++j) {
			printf("111111  j = %d \n", j);
			printf("curr[%d] = %d \n", j, curr[j]);
			printf("tmp[%d] = %d \n", j, tmp[j]);
			printf("tmp[%d] = %d \n", j-1, tmp[j-1]);
			printf("carry = %d \n", carry);
			curr[j] = tmp[j] + tmp[j - 1] + carry;

			carry = curr[j] / 10;
			curr[j] = curr[j] % 10;
		}

		if (i > 0) {
			printf("222222 j = %d \n", j);
			printf("curr[%d] = %d \n", j, curr[j]);
			printf("tmp[%d] = %d \n", j, tmp[j]);
			printf("tmp[%d] = %d \n", j - 1, tmp[j - 1]);
			printf("carry = %d \n", carry);
			curr[j] = tmp[j - 1] + carry;
			if (curr[j] >= 10) {
				curr[j] = curr[j] % 10;
				curr[++j] = 1;
			}
			tmp_len = ++j;
		}
		else {
			tmp_len = 1;
		}

		p = tmp;
		tmp = curr;
		curr = p;
	}

	for (i = 0; i < size; ++i) {
		printf("%d", tmp[i]);
		if (tmp[i] == 1) {
			++count;
		}
	}
	printf("\ncount = %d.\n", count);

	free(tmp);
	free(curr);
	return 0;
}

/*
int main(void)
{
solution(1000);
return 0;
}
*/

void preVSfollow()
{
	int i,j;
	int N = 10;
	for (i = 0; i < N; i++)
	{
		printf("\n inside i = %d", i);
	}
	printf("\n outside i = %d", i);

	for (j = 0; j < N; ++j)
	{
		printf("\n inside j = %d", j);
	}
	printf("\n outside j = %d", j);

}



void Hannoi(int n, char source, char dest, char temp)
{
	if (n > 1)
    {
		Hannoi(n - 1, source , temp, dest);
		printf("\n %c --- %c",source, dest);
		Hannoi(n - 1, temp, dest, source);
    }
	else
	{
		printf("\n %c --- %c", source, dest);
	}
}

void test(char **p)
{
	*p = new char[100];
}

void showTheSizeOfBlock()
{
	unsigned char *p1;
	unsigned long *p2;

	p1 = (unsigned char *)0x801000;
	p2 = (unsigned long *)0x810000;

	unsigned char *pa1 = p1 + 5;
	unsigned long *pa2 = p2 + 1;

	printf("pa2 = %d", (int)pa2);
}

#define MAX_LEN 100

void switchChars(char *str, int step)
{
	int len = strlen(str);
	char dest[MAX_LEN];
	memset(dest, 0, len+1);
	printf("len = %d", len);

	strcpy(dest, str + len - step);
	strcpy(dest + step, str);
	
	memset(dest+len, 0, 1);


	printf("res = %s", dest);
}

void *getInstance(int userInput)
{
	void *p;
	if (userInput == 0)
		p = new withCC;
	else
		p = new subCC;

	return p;
}

void memcpyChars(char *str, int step)
{
	int len = strlen(str);
	char dest[MAX_LEN];
	memset(dest, 0, len + 1);
	printf("len = %d", len);

	//strcpy(dest, str + len - step);
	//strcpy(dest + step, str);

	memcpy(dest, str + len - step, step);
	memcpy(dest + step, str, len-step);
	
	memset(dest + len, 0, 1);

	printf("res = %s", dest);
}





void testInput()
{
	int inputNum;
	printf("Please input a number: ");
	scanf("%d", &inputNum);
	printf("\n the input is %d", inputNum);

	char inputStr[20];
	printf("\n\n Please input a string: ");
	//if the user input a string which is too long, 
	//this may cause crash, echo:
	//Run-Time Check Failure #2 - Stack around the variable 'inputNum' was corrupted.
    scanf("%s", inputStr);
	printf("the input is %s", inputStr);
}
typedef struct {
	char* name;
	int data;
}yxStruct;

void testMalloc() {
	//malloc for str
	yxStruct yx;
	yx.name = "love";
	printf("\n before, yx.name = %s", yx.name);
	int len = strlen(yx.name);
	char * dest = (char*)malloc(len + 1);
	yx.name = dest;
	printf("\n after, yx.name = %s", yx.name);
	int *myArray = (int*)malloc(sizeof(int) * 10);
	yx.data = *myArray;
	printf("\n after, yx.data = %d", yx.data);

	yxStruct *yxcopy = (yxStruct*)malloc(sizeof(yxStruct));
	//the following printf statement will cause read overflow exception
	//as the there is no "\0" in the block, so the pc can't know where to stop.
	//printf("\n before yxcopy.name = %s, yxcopy.data = %d", yxcopy->name, yxcopy->data);
	yxcopy->name = "yx";
	printf("\n before yxcopy.name = %s, yxcopy.data = %d", yxcopy->name, yxcopy->data);

	yxStruct *yxArray = (yxStruct *)malloc(sizeof(yxStruct)*10);
	memset(yxArray, '\0', sizeof(yxStruct)*10);
	memcpy(yxcopy, yxArray, sizeof(yxStruct));
	printf("\n after yxcopy.name = %s, yxcopy.data = %d", yxcopy->data, yxcopy->data);

	free(dest);
	dest = NULL;
	free(yxArray);
	yxArray = NULL;
}

void testNew()
{
	const int NUM = 3;

	T* p1 = new T[NUM];
	cout << hex << p1 << endl;
    delete[] p1;
	//delete p1;   //without "[]",the program will throw a exception when execute this

	T* p2 = new T[NUM];
	cout << p2 << endl;
	delete[] p2;
}

void myGetReverse(char sour[], int len)
{
	static int i = 0;
	static char rev[100];
	
	if(sour)
	{
		printf("\n myGetReverse len = %d", len);
		printf("\n myGetReverse i = %d", i);

		if(len>=1)
		{
			rev[i] = sour[len - 1];//get the last char and store it in rev[i]
			i++;
			myGetReverse(sour, len - 1);
			
		}
	}

	return;
}

char* getReverse(char str[]) {
	
	static int i = 0;//this has a defect: it can only reverse one string in  
	//the application's life circle 
	static int times = 0;
	static char rev[100];

	times++;
	printf("\n getReverse enter %d", times);


	if (*str) {
		getReverse(str + 1);//go on checking if it is the rare of the string
		rev[i++] = *str;//meet rear
	}

	printf("\n return %d", times);

	return rev;
}

int testPassByArrayElement()
{
	int a[5], i;
	printf("input 5 numbers\n");
	for (i = 0; i<5; i++) {
		scanf("%d", &a[i]);
		nzp(a[i]);
	}
	return 0;
}

void nzp(int v) {
	if (v>0)
		printf("%d ", v);
	else
		printf("%d ", 0);
}

int testPassByArrayName()
{
	float sco[5], av;
	int i;
	printf("\ninput 5 scores:\n");
	for (i = 0; i<5; i++)
		scanf("%f", &sco[i]);
	av = aver(sco);//pass by array name
	printf("average score is %5.2f", av);
	//by breaking here we can see  that every element in sco has been changed.
	return 0;
}

float aver(float a[5]) {
	int i;
	float av, s = a[0];
	for (i = 1; i < 5; i++)
	{
		s = s + a[i];
		a[i] = s;
		printf("\n a[%d] change to %5.2f",i, a[i]);
	}
		
	av = s / 5;
	return av;
}

int test2DimArray()
{
	int a[3][4];
	//op2DimArray((int**)a);

	int b[2][4] = { 1,2,3,4,5,6,7,8 };
	printf("the address of 2 dim array b is %d \n",(int)b);
	printf("the address b[0] is %d \n", (int)(b[0]));
	printf("the address b[1] is %d \n", (int)(b[1]));
	printf("the address b[0]+1 is %d \n", (int)(b[0]+1));
	printf("the address *(b+0)+1  is %d \n", (int)(*(b + 0) + 1));

	op2DimArray(a);
	return 0;
}

//int op2DimArray(int **)   //this is build ok
int op2DimArray(int p[][4])
{
	return 0;
}

/*
void swapCharByArray()
{
char iStr[20];
printf("Please enter the 1st string");
get_s(iStr);

printf("The 1st string is %s", iStr);
}
*/

bool isPalindrome(int x) {

	int* bit = (int*)malloc(1000*sizeof(int));
	int count = 0;
	int m = 0;
	int origin = x;
	bool res = false;

	//memset(bit, '\0', 1000 * sizeof(int));

	for (int index = 0; index < 1000; index++)
	{
		bit[index] = -1;
	}

	while (x>0)
	{
		m = x % 10;
		bit[count] = m;
		count++;

		x = x / 10;

		printf("x=%d \n", x);
	}

	int i = 0;
	int y = 0;

	while (bit[i] > -1)
	{
		printf("bit[%d]=%d \n", i,bit[i]);
		i++;
	}

	for (int j = 0; j < i; j++)
	{
		printf("before y=%d bit[%d] = %d \n", y, j, bit[j]);
		y = y * 10 + bit[j];
		printf("y[%d]=%d \n", j, y);
	}

	if (y == origin)
		res = true;

	free(bit);
	bit = NULL;

	return res;

}

int reverse(int x) {
	int res = 0;
	
	int *p = (int*)malloc(10 * sizeof(int));
	//assert(p);

	int i = 0;
	int j = 0;
	int highest = 0;
	int num = 0;

	for (int index = 0; index < 10; index++)
	{
		p[index] = 0;
	}

	if (x == 0)
	{

	}
	else 
	{
		while (x)
		{
			num = x % 10;
			p[i] = num;
			x /= 10;
			i++;
		}
		highest = i-1;
		//j = highest;
		res = p[0];
		j = 1;
		
		while (j<=highest)
		{
			res = res * 10 + p[j];
			j++;
		}
		
	}

	free(p);
	p = NULL;
	return res;
}

