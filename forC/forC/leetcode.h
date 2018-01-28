#pragma once

#include "stdafx.h"

#include <iostream>
#include <string>
using namespace std;

int testLeetCode();
int removeDuplicates(int* nums, int numsSize);

bool match(char a, char b);
bool isMatch(char* s, char* p);

struct ListNode* swapPairs(struct ListNode* head);

//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};


