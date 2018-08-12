#pragma once

#include "stdafx.h"

#include <iostream>
#include <string>

#include<vector>
using namespace std;

int testLeetCode();

double stage(double x, int num);
double myPow(double x, int n);
int removeDuplicates(int* nums, int numsSize);

bool match(char a, char b);
bool isMatch(char* s, char* p);
bool isIsomorphic(char* s, char* t);

struct ListNode* swapPairs(struct ListNode* head);

int expandAroundCenter(char*s, int left, int right);
char* longestPalindrome(char* s);

int* insertAtPosition(int num, int* queue, int qSize, int position);
int** permute(int* nums, int size, int* returnSize);

void outputP(int* nums, /*int *fixedArr, int fixedPos, */int fixedSize, int arrSize, int ***block, int* return_Size);

int** yx_permute(int* nums, int numsSize, int* returnSize);

string minWindow(string s, string t);

void rotate(vector<vector<int> > &matrix);

int my_numDecodings(string s);

int uniquePaths(int m, int n);
int compose(int nn, int m);

int my_numDecodings_1(string s);

struct Interval_cplusplus {
	int start;
	int end;
	Interval_cplusplus() : start(0), end(0) {}
	Interval_cplusplus(int s, int e) : start(s), end(e) {}
};

struct Interval_c {
	int start;
	int end;
};

vector<Interval_cplusplus> mergeIntervals(vector<Interval_cplusplus>& intervals);
//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

vector<string> restoreIpAddresses(string s);



