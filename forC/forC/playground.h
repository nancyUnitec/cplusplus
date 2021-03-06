#pragma once

#include "stdafx.h"

#include <iostream>
#include <string>

#include<vector>
using namespace std;

int runPlayground();


struct ListNode* addTwoNumbers_180630(struct ListNode* l1, struct ListNode* l2);

int lengthOfLongestSubstring_180701(char* s);

int reverse_180706(int x);

bool isPalindrome(char* s);

bool isLetter(char c);

bool isLetter_180708(char c);

void sortIntervals(Interval_c intervals[], int intervalSize);

struct Interval_c* merge(struct Interval_c* intervals, int intervalsSize, int* returnSize);
