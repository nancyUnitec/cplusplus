#pragma once

#include "stdafx.h"

#include <iostream>
#include <string>
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

//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};


