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

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> mergeIntervals(vector<Interval>& intervals);
//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};



