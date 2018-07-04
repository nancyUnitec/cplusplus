#include "stdafx.h"

#include <iostream>
#include <string>

#include<vector>
#include<algorithm>
using namespace std;

#include "forCPP.h"
#include "leetcode.h"
#include "playground.h"


int runPlayground()
{
	//struct ListNode node1, node2;
	//addTwoNumbers_180630(&node1,&node2);

	//char* s = "abcabcbb";
	//char* s = "c";
	char* s = "aab";
	int res = lengthOfLongestSubstring_180701(s);

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