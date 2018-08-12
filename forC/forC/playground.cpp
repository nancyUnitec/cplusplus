#include "stdafx.h"

#include <iostream>
#include <string>

#include<vector>
#include<algorithm>
using namespace std;

#include "forCPP.h"
#include "leetcode.h"
#include "playground.h"

//typedef Interval Interval_c;

int runPlayground()
{
	//struct ListNode node1, node2;
	//addTwoNumbers_180630(&node1,&node2);

	//char* s = "abcabcbb";
	//char* s = "c";
	//char* s = "aab";
	//int res = lengthOfLongestSubstring_180701(s);

	//int res = reverse_180706(123);

	//bool res = isPalindrome("haha");

	struct Interval_c intervals[5];
	intervals[0].start = 0; intervals[0].end = 20;
	intervals[1].start = 4; intervals[1].end = 21;
	intervals[2].start = 2; intervals[2].end = 22;
	intervals[3].start = 3; intervals[3].end = 23;
	intervals[4].start = 6; intervals[4].end = 24;
	
	sortIntervals(intervals, 5);
	struct Interval_c* res;

	int returnSize = 0;
	res = merge(intervals, 5, &returnSize);

	return 0;
}


struct ListNode* addTwoNumbers_180630(struct ListNode* l1, struct ListNode* l2) {
	printf("pppppppppppplayground \n");
	return NULL;
}

int lengthOfLongestSubstring_180701(char* s) {
	int i = 0; int j = 0; int start = 0; int end = 0;
	int slen = strlen(s);
	int dict[128];
	memset(dict, '\0', 128 * sizeof(int));
	char curr = '\0';
	while (i<(slen - (end - start)))
	{
		//check substring s[i:j]
		while (j<slen)
		{
			curr = s[j];
			if (dict[curr] > 0)
			{
				//mutate start and end
				if ((j - i)>(end - start))
				{
					start = i;
					end = j;
				}
				while (s[i] != curr)
					i++;
				i++;
				j = i;
				break;
			}
			else
				dict[curr]++;
			j++;
		}

		if (j >= (slen - 1))
		{
			if ((j - i)>(end - start))
			{
				start = i;
				end = j;
			}
			break;
		}

		memset(dict, '\0', 128 * sizeof(int));
	}

	if (i == 0)
		return slen;
	else
		return end - start;
}


int reverse_before_201807(int x) {
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
		highest = i - 1;
		//j = highest;
		res = p[0];
		j = 1;

		while (j <= highest)
		{
			res = res * 10 + p[j];
			j++;
		}

	}

	free(p);
	p = NULL;
	return res;
}


int reverse_180706(int x) {
	long long res = 0;
	int num = 0;

	if (x == 0)
	{

	}
	else
	{
		while (x)
		{
			res = res * 10;
			num = x % 10;
			x /= 10;
			res += num;
			if (res<INT_MIN || res>INT_MAX)
			{
				res = 0;
				break;
			}
		}
	}

	return res;
}

//leetcode no 125 problem, the code is ok in vs 2010,but fail on leetcode webpage
bool isPalindrome_180708(char* s) {
	bool res = true;
	//if (strlen(pchar) <= 1) //for char*

	int i = 0;
	int j = strlen(s) - 1;
	while (i<j)
	{
		if (s[i] == s[j])
		{
			i++;
			j--;
		}
		else
		{
			if (isLetter_180708(s[i]) && isLetter_180708(s[j]))
			{
				res = false;
				break;
			}
			else
			{
				if (isLetter_180708(s[i]))
				{
					j--;
				}
				else
				{
					i++;
				}
			}
		}
	}

	return res;
}

bool isLetter_180708(char c)
{
	//     if( (c>='a' && c<='z') || (c>='A' && c<='Z'))
	//      return true;//返回1表示是字母
	//    return 0;//返回0表示不是字母
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

//this 180709 soulution beat 100% of c submissions
bool isPalindrome_180709(char* s) {
	bool res = true;
	//if (strlen(pchar) <= 1) //for char*

	int i = 0;
	int j = strlen(s) - 1;
	while (i<j)
	{
		if (tolower(s[i]) == tolower(s[j]))
		{
			i++;
			j--;
		}
		else
		{
			if (isalnum(s[i]) && isalnum(s[j]))
			{
				res = false;
				break;
			}
			else
			{
				if (isalnum(s[i]))
				{
					j--;
				}
				else
				{
					i++;
				}
			}
		}
	}

	return res;
}

/*
void sortIntervals(Interval_c intervals[], int intervalSize)
{
	int i, j, k;
	Interval_c temp;

	for (i = 1; i<intervalSize; i++)
	{
		temp = intervals[i];
		j = i - 1;
		while (j >= 0 && temp.start<intervals[j].start)
		{
			intervals[j + 1] = intervals[j];
			j--;
		}
		intervals[j + 1] = temp;
		printf("   i=%d   ", i);

		for (k = 0; k<intervalSize; k++)
			printf("%3d", intervals[k].start);

		printf("\n");
	}
}

struct Interval_c* merge(struct Interval_c* intervals, int intervalsSize, int* returnSize) {

	struct Interval_c currentInterval;
	//currentInterval = (struct Interval_c *)malloc(sizeof(struct Interval_c)) ;
	struct Interval_c* res;
	*returnSize = 0;
	if(intervalsSize == 0)
		return NULL;
	else
	{
		currentInterval.start = intervals[0].start;
		currentInterval.end = intervals[0].end;
		res = (struct Interval_c *)malloc(sizeof(struct Interval_c));
		memcpy(res, &currentInterval, sizeof(struct Interval_c));

		*returnSize = 1;
	}
	for (int index = 1; index < intervalsSize; index++)
	{
		if (currentInterval.end >= intervals[index].start)
		{
			if (currentInterval.end < intervals[index].end)
			{
				currentInterval.end = intervals[index].end;
				res[*returnSize - 1].end = intervals[index].end;
			}
		}
		else
		{
			currentInterval.start = intervals[index].start;
			currentInterval.end = intervals[index].end;
			*returnSize += 1;
			res = (struct Interval_c *)realloc(res, sizeof(int*)*(*returnSize));
			res[*returnSize - 1].start = currentInterval.start;
			res[*returnSize - 1].end = currentInterval.end;
		}
	}
	return res;
}
*/



void sortIntervals(struct Interval_c intervals[], int intervalSize)
{
	int i, j, k;
	struct Interval_c temp;

	for (i = 1; i<intervalSize; i++)
	{
		temp = intervals[i];
		j = i - 1;
		while (j >= 0 && temp.start<intervals[j].start)
		{
			intervals[j + 1] = intervals[j];
			j--;
		}
		intervals[j + 1] = temp;
	}
}

struct Interval_c* merge(struct Interval_c* intervals, int intervalsSize, int* returnSize) {

	struct Interval_c currentInterval;
	//currentInterval = (struct Interval_c *)malloc(sizeof(struct Interval_c)) ;
	struct Interval_c* res;
	*returnSize = 0;
	if (intervalsSize == 0)
		return NULL;
	else
	{
		sortIntervals(intervals, intervalsSize);
		currentInterval.start = intervals[0].start;
		currentInterval.end = intervals[0].end;
		res = (struct Interval_c *)malloc(sizeof(struct Interval_c));
		memcpy(res, &currentInterval, sizeof(struct Interval_c));

		*returnSize = 1;
	}
	for (int index = 1; index < intervalsSize; index++)
	{
		if (currentInterval.end >= intervals[index].start)
		{
			if (currentInterval.end < intervals[index].end)
			{
				currentInterval.end = intervals[index].end;
				res[*returnSize - 1].end = intervals[index].end;
			}
		}
		else
		{
			currentInterval.start = intervals[index].start;
			currentInterval.end = intervals[index].end;
			*returnSize += 1;
			res = (struct Interval_c *)realloc(res, sizeof(int*)*(*returnSize));
			res[*returnSize - 1].start = currentInterval.start;
			res[*returnSize - 1].end = currentInterval.end;
		}
	}
	return res;
}
