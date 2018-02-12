#include "stdafx.h"

#include <iostream>
#include <string>
using namespace std;

#include "forCPP.h"
#include "leetcode.h"

int testLeetCode()
{
	/*
	int arr[3] = { 1,1,2 };
	//int* nums = (int*)malloc(3 * sizeof(int));
	arr[0] = 1;
	arr[1] = 1;
	arr[2] = 2;
	removeDuplicates(arr, 3);
	*/

	/*
	char *s = "aaa";
	char *p = "a*a";

	bool res = isMatch(s, p);

	*/
	
	/*
	struct ListNode n1, n2, n3, n4;
	n1.val = 1; n1.next = &n2;
	n2.val = 2; n2.next = &n3;
	n3.val = 3; n3.next = &n4;
	n4.val = 4; n4.next = NULL;

	struct ListNode* res = swapPairs(&n1);

	*/
	
	/*
	char* s = "odd";
	char* t = "egg";
	bool res = isIsomorphic(s, t);
    */

	/*
	char* s = "abcda";

	char* p = longestPalindrome(s);
	*/
	/*
	double x = 34.00515;
	int n = -3;
	double res = myPow(x, n);

	*/

	int size = 5;
	int* arr = (int*)malloc(size * sizeof(int));
	//int* nums = (int*)c;
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 6;
	//removeDuplicates(arr, 3);
	int num = 7;
	int pos = 2;
	
	int solutionSize = 0;
	int* solution = &solutionSize;
//	insertAtPosition(num, arr, size, pos);
	int**res = permute(arr, 3, solution);

	return 0;
}


void swap(int* p, int* q)
{
	int t = *p; *p = *q; *q = t;
}
void search(int* nums, int size, int*** arr, int* returnSize, int begin, int end)
{
	printf("\n search  %d,  %d \n", begin, end);
	if (begin == end)
	{
		(*returnSize)++;
		printf("\n realloc return size = %d \n", *returnSize);
		*arr = (int**)realloc(*arr, sizeof(int*)*(*returnSize));
		(*arr)[*returnSize - 1] = (int*)malloc(sizeof(int)*size);
		for (int i = 0; i < size; i++)
		{
			printf("*arr[%d][%d] = num[%d] = %d \n", *returnSize - 1, i, i,nums[i]);
			(*arr)[*returnSize - 1][i] = nums[i];
		}
			
		return;
	}
	for (int i = begin; i <= end; i++)
	{
		swap(nums + begin, nums + i); //try to use each element as the head;
		printf("swap : %d, %d \n", begin, i);
		search(nums, size, arr, returnSize, begin + 1, end);
		swap(nums + begin, nums + i);
		printf("swap : %d, %d \n", begin, i);
	}
}

//AC - 4ms;
int** permute(int* nums, int size, int* returnSize)
{
	*returnSize = 0;
	int** arr = (int**)malloc(sizeof(int*));
	search(nums, size, &arr, returnSize, 0, size - 1);
	return arr;
}




/*
int** permute(int* nums, int numsSize, int* returnSize) {
int** res = permute(nums, numsSize - 1, returnSize);
for (int i = 0; i < *returnSize; i++)
{
int *sub = res[i];
for (int j = 0; j <= numsSize; j++)
{
insertAtPosition(sub, numsSize - 1, j);
}
}

}
*/

int* insertAtPosition(int num, int* queue, int qSize, int position)
{
	int temp = queue[position];
	int buf = 0;
	if (position < qSize - 1)
		buf = queue[position + 1];
	queue[position] = num;

	for (int index = position + 1; index < qSize; index++)
	{
		queue[index] = temp;
		temp = buf;
		
		if (position < qSize - 1)
			int buf = queue[position + 1];
	}
	for (int i = 0; i < qSize; i++)
		printf(" %d ", queue[i]);

	return queue;
}

/////////////////run time error solution////////////////////
//this solution is run time error
//because if x is very small, x^n will be very small, close to zero
//then 1/x will throw a divide 0 exception
/*
double stage(double x, int num) {
if (num == 0) return 1;
if (num == 1) return x;
double pow = 0.0;
if (num % 2 == 0)
{
pow = stage(x, num / 2);
return pow*pow;
}
else
{
pow = stage(x, (num - 1) / 2);
return pow*pow*x;
}
}

double myPow(double x, int n) {
if (n == 0)
return 1;

if (n<0)
return 1 / stage(x, -n);
else
return stage(x, n);
}
*/

////////////////accept solution///////////////////////////
double myPow(double x, int num) {
	if (x == 0) return 0;
	if (num == 0) return 1;
	if (num == 1) return x;
	if (num == -1) return 1 / x;
	double pow = 0.0;
	if (num % 2 == 0)
	{
		pow = myPow(x, num / 2);
		pow = pow*pow;
	}
	else
	{
		pow = myPow(x, (num - 1) / 2);
		pow = pow*pow*x;
	}
	return pow;
}

int removeDuplicates(int* nums, int numsSize)
{
	int i = 0;
	int count = 0;
	int position = 0;
	if (nums == NULL)
		count = 0;
	else if (numsSize == 0)
		count = 0;
	else
	{
		count = 1;
		while (position < numsSize)
		{
			while (nums[position] == nums[i])
			{
				position++;
			}

			if (position < numsSize)
			{
				nums[i + 1] = nums[position];
				count++;
				i++;
				//position++;
			}
		}
		//count = i+1;
	}




	return count;

}

bool match(char a, char b)
{
	return (a == b) || ((b == '.') && (a != '\0'));
}

bool isMatch(char* s, char* p) {
	bool res = false;
	bool temp = true;
	int i = 0;
	int j = 0;

	while ((s[i] != '\0') || (p[j] != '\0'))
	{
		printf("wwwww i = %d, j = %d \n", i, j);
		//printf(" s = %s, p = %s \n",s,p);
		printf("wwwww s[i]= %c, p[j] = %c \n", s[i], p[j]);
		printf("wwwww s+i= 0x%x, p+j = 0x%x \n", s + i, p + j);
		printf("wwwww *(s+i)= %c, *(p+j) = %c \n", *(s + i), *(p + j));

		temp = match(s[i], p[j]);
		if (temp)
		{
			i++;
			j++;
		}
		else
		{
			if (p[j] == '*')
			{
				if (match(s[i], p[j - 1]))
					i++;
				else
					j++;
			}

			else if (p[j + 1] == '*')
				j += 2;
			else
				break;
		}

	}


	printf(" i = %d, j = %d \n", i, j);
	printf(" s = %s, p = %s \n", s, p);
	printf(" s[i]= %c, p[j] = %c \n", s[i], p[j]);
	printf(" s+i= 0x%x, p+j = 0x%x \n", s + i, p + j);

	if (s[i] == '\0')
	{

		if ((p[j] == '\0')
			//||((p[j+1]=='*')&&(p[j+2]=='\0'))||
			|| (match(s[i - 1], p[j + 1]) && (p[j] == '*'))
			|| (match(s[i - 1], p[j]) && (p[j - 1] == '*'))
			)

			res = true;


	}

	return res;

}

bool isIsomorphic(char* s, char* t) {
	/*
	int m1[256] = { 0 };
	int m2[256] = { 0 };

	int i = 0;

	while (s[i] && t[i])
	{
	if ((m1[s[i]]) == 0 && (m2[t[i]]) == 0)
	{
	m1[s[i]] = i + 1;
	m2[t[i]] = i + 1;
	}
	else {
	if (m1[s[i]] != m2[t[i]])
	return false;
	}
	i++;
	}

	if (s[i] || t[i])
	return false;

	return true;

	*/
	
	char m[256] = { '\0' };
    int i = 0;

	while (s[i] && t[i])
	{
		if ((m[s[i]]) == 0 )
		{
			m[s[i]] = t[i];
		}
		else {
			if (m[s[i]] != t[i])
				return false;
		}
		i++;
	}

	if (s[i] || t[i])
		return false;

	return true;

}


int expandAroundCenter(char*s, int left, int right)
{
	int L = left;
	int R = right;
	while (L >= 0 && (s[R] != '\0'))
	{
		if (s[L] == s[R]) {
			L--;
			R++;
		}
		else
		{
			return R - L - 2;
		}

	}
	return R - L - 2;
}

char* longestPalindrome(char* s) {
	if (!s)
		return s;

	if (strlen(s) <= 1)
		return s;

	int len1 = 0;
	int len2 = 0;
	int maxlen = 0;
	int cen1 = -1;
	int cen2 = -1;

	int left;
	int right;
	int i = 0;

	for (i = 0; i < strlen(s); i++)
	{
		len1 = expandAroundCenter(s, i, i);
		len2 = expandAroundCenter(s, i, i + 1);

		if (maxlen < len1) {
			maxlen = len1;
			cen1 = i;
			cen2 = -1;
		}
		if (maxlen < len2) {
			maxlen = len2;
			cen2 = i;
			cen1 = -1;
		}

	}
	if (cen1 != -1)
	{
		left = cen1 - maxlen / 2;
		right = cen1 + maxlen / 2;

	}
	else if(cen2 != -1 )
	{
		left = cen2 - (maxlen - 1) / 2;
		right = cen2 + 1 + (maxlen - 1) / 2;

	}
	else
	{
		left = 0;
		right = 0;
	}
	char *res = (char*)malloc(maxlen + 2);
	res[maxlen+1] = '\0';
	strncpy(res, s+left, maxlen+1);

	return res;
}

/*
struct ListNode* swap(struct ListNode* n1,struct ListNode* n2)
{
struct ListNode* tmp = n2-> next;
n1->next = tmp;
n2->next = n1;

return n1;
}

*/

/*
struct ListNode* swapPairs(struct ListNode* head) {

if (!head)
return NULL;

else if (!(head->next))
return head;

else
{
//struct ListNode* new = (struct ListNode*)malloc(sizeof(struct ListNode));
//new ->next = head->next;
struct ListNode* new;
struct ListNode* tail;
//struct ListNode* tmp;

struct ListNode* i = head;
struct ListNode* j = head->next;
new = j;

while (i&&j)
{
//tail = swap(i,j);
//tmp = j-> next;
i->next = j->next;
j->next = i;
tail = i;

if (i->next)
{
i = i->next;
j = i->next;

if (j)
{
tail->next = j;
}

}
else
break;

}

return new;

}

}


*/

struct ListNode* swapPairs(struct ListNode* head) {

	if (!head)
		return NULL;

	else if (!(head->next))
		return head;

	else
	{
		struct ListNode* newHead = swapPairs(head->next->next);
		struct ListNode* tmp = head->next;
		head->next = newHead;
		tmp->next = head;
		return tmp;

	}

}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    
	// acceptted 1
    // if(head == NULL)
    //     return NULL;
    // else if(head->next == NULL)
    //     return NULL;
    
    // struct ListNode* first = head;
    // struct ListNode* second = head;
    // struct ListNode* prev;
    // int count = 0;
    // while(first)
    // {
    //     count++;
    //     first = first->next;
    // }
    // int pos = count - n;
    // int index = 0;
    
    // if(index < pos)
    // {
    //     while(index < pos)
    //     {
    //         prev = second;
    //         second = second->next;
    //         index++;
    //     }
    //     prev->next = second->next;

    // }
    // else
    // {
    //     head = head->next;
    // }
       
    // return head;


	// acceptted 2
	if(head == NULL)
        return NULL;
    else if(head->next == NULL)
        return NULL;
    
    struct ListNode* first = head;
    struct ListNode* second = head;
    struct ListNode* prev = head;
    int gap = 0;
    while(gap<n)
    {
        gap++;
        first = first->next;
    }
    //int pos = count - n;
    //int index = 0;
    
    while(first)
    {
        prev = second; 
        first = first->next;  //what you want is to link prev with prev->next-next, so the second is redundant.
        second = second->next;
    }    
    
    if(second == head)  //if you use a dummy node point to the head, u can omit this step.
        head = head->next;
    else 
        prev->next = second->next;

    return head;
}
