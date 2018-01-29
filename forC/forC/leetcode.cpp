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
	
	
	struct ListNode n1, n2, n3, n4;
	n1.val = 1; n1.next = &n2;
	n2.val = 2; n2.next = &n3;
	n3.val = 3; n3.next = &n4;
	n4.val = 4; n4.next = NULL;
	
	struct ListNode* res = swapPairs(&n1);

	return 0;
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
