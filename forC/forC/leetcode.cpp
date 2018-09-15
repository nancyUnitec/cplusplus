#include "stdafx.h"

#include <iostream>
#include <string>

#include<vector>
#include<algorithm>
using namespace std;

#include "forCPP.h"
#include "leetcode.h"
#include "playground.h"

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


	/*
	*/
	int size = 5;
	int* arr = (int*)malloc(size * sizeof(int));

	int* fix = (int*)malloc(size * sizeof(int));
	
	//int* nums = (int*)c;
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 6;
	//removeDuplicates(arr, 3);
	int num = 7;
	int pos = 2;
	int returnSize = 0;
	
	//int solutionSize = 0;
	//int* solution = &solutionSize;
//	insertAtPosition(num, arr, size, pos);
	//int**res = permute(arr, 3, solution);

	//int** block = (int**)malloc(sizeof(int*));
	//int solNum = outputP(arr, fix, 0, size-1, size-1, &block);
	/*
	for(int i = 0; i < solNum; i++ )
	{
		printf(" solution %d is :", i);
		int *solution = block[i];
		for (int j = 0; j < size - 1; j++)
			printf(" %d ", solution[j]);
		printf("\n");
	}
	*/

	//block = yx_permute(arr, 4, &returnSize);

	
	//string s = "pnsdfsdfsfsalinda";
	//string t = "na";
	
	//string set = minWindow(s, t);

	/*
	Interval a = Interval(1, 3);
	Interval b = Interval(2, 6);

	vector<Interval> vi;
	vi.push_back(a);
	vi.push_back(b);

	vector<Interval> vo;
	//vector<Interval> merge(vector<Interval>& intervals) {
	vo = mergeIntervals(vi);
	*/

	/*
	int arr1[] = {1, 2, 3};
	int arr2[] = {4, 5, 6};
	int arr3[] = {7, 8, 9};
													   
	vector<int> iv1(arr1, arr1 + 3);
	vector<int> iv2(arr2, arr2 + 3);
	vector<int> iv3(arr3, arr3 + 3);
	for (auto x : iv1)//输出应该是va里面的值
		cout << x << " ";

	vector<vector<int> > matrix;
	matrix.push_back(iv1);
	matrix.push_back(iv2);
	matrix.push_back(iv3);

	rotate(matrix);

	string str = "12";
	//int r = my_numDecodings_1(str);

	int r = uniquePaths(3, 2);
	*/

	//restoreIpAddresses("25525511135");

	//int data[15] = { 2,1,-1,-1,3,-1,-1 };
	int data[15] = { 5,1,-1,-1,4,3,-1,-1,6,-1,-1 };

	TreeNode* tree;
	treeNodeConstructor(tree, data);
    bool res = isValidBST(tree);
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

void swapPos(int *numbers, int pos1, int pos2)
{
	printf("swap pos1 = %d, pos2 = %d \n ", pos1,pos2);
	int temp = numbers[pos1];
	numbers[pos1] = numbers[pos2];
	numbers[pos2] = temp;
}

void outputP(int* nums,/*int *fixedArr,*/ /*int fixedPos,*/ int fixedSize, int arrSize, int ***block, int* return_Size)
{
	//static int solutionNum = 0;
	for (int n = 0; n < arrSize; n++)
		printf(" %d ", nums[n]);
	printf("pppppp start arr size = %d, return_Size = %d \n ", arrSize, *return_Size);
	//if (fixedPos < arrSize-1) {
	if (arrSize > 1) {
		for (int n=0; n<arrSize; n++)
		{ 
			swapPos(nums,0,n);
			//fixedArr[fixedPos] = nu8ms[0];
			outputP(nums+1/*,fixedArr, fixedPos+1*/, fixedSize, arrSize-1,block, return_Size);
			swapPos(nums,n,0);
		}
		
	}
	else
	{
		//fixedArr[fixedPos] = nums[0];
		for (int n = 0; n < fixedSize; n++)
			printf(" %d ", nums[n]);
		//printf(" %d ", nums[arrSize-1]);
		printf("end arrSize = %d \n\n ", arrSize);
		//if (arrSize == fixedSize)
		{
			printf("before *return_Size = %d \n ", *return_Size);
			(*return_Size)++;
			printf("after *return_Size = %d \n ", *return_Size);
			int solNum = *return_Size;
			*block = (int**)realloc(*block, sizeof(int*)*(*return_Size + 1));
			int **block_content = *block;
			block_content[(*return_Size)-1] = (int*)malloc(fixedSize*sizeof(int));
			memcpy(block_content[(*return_Size)-1], nums, fixedSize * sizeof(int));
		
			//solutionNum++;
		}
	}
	//return solutionNum;
	return;
}

//this solution is ok on vs2017, but fail on leetcode web page.... 5555555~~~
//cost me the whole night...
int** yx_permute(int* nums, int numsSize, int* returnSize) {
	if (numsSize == 0)
		return NULL;
	if (numsSize == 1)
		return &nums;

	int** block = (int**)malloc(sizeof(int*));

	int* fix = (int*)malloc(numsSize * sizeof(int));
	outputP(nums, /*fix, 0,*/ numsSize, numsSize, &block, returnSize);
	//*returnSize = solNum;

	return block;
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

/*longestPalindrome accepted solution 1
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

*/

int expandAroundCenter(char*s, int *left, int *right)
{
	int L = *left;
	int R = *right;
	while (L >= 0 && (s[R] != '\0'))
	{
		if (s[L] == s[R]) {
			*left = L;
			L--;
			*right = R;
			R++;
		}
		else
		{
			return R - L - 1;
		}

	}
	return R - L - 1;
}

char* longestPalindrome(char* s) {

	if (!s)
		return s;

	if (strlen(s) <= 1)
		return s;

	int len1 = 0;
	int len2 = 0;
	int maxlen = 0;
	int left = -1;
	int right = -1;

	int L1, L2; int R1, R2;
	int *left1 = &L1;
	int *right1 = &R1;
	int *left2 = &L2;
	int *right2 = &R2;

	int i = 0;

	for (i = 0; i < strlen(s); i++)
	{
		*left1 = i;
		*right1 = i;
		len1 = expandAroundCenter(s, left1, right1);
		*left2 = i;
		*right2 = i + 1;
		len2 = expandAroundCenter(s, left2, right2);

		if (maxlen < len1) {
			maxlen = len1;
			left = *left1;	
		}
		if (maxlen < len2) {
			maxlen = len2;
			left = *left2;
		}

	}

	char *res = (char*)malloc(maxlen + 1);
	res[maxlen] = '\0';
	strncpy(res, s + left, maxlen);

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

void printMap(vector<int> map)
{
	for (int i = 0; i < map.size(); i++)
	{
		if (map[i] != 0)
		{
			cout << " map["<<i<<"] = " << map[i] ;
			printf("i-> %c \n", i);
		}
	}
	cout << " \n ";
}

string minWindow(string s, string t) {
	vector<int> map(128, 0);//{0,0,...,0} 128 zero
	for (auto c : t) map[c]++; //for each item c in t
	printMap(map);
	int counter = t.size(), begin = 0, end = 0, d = INT_MAX, head = 0;
	while (end<s.size()) {
		printf("1111111 begin = %d, s[begin] = %c ,end = %d, s[end] = %c \n", begin, s[begin], end, s[end]);
		//printf("1111111 end = %d, s[end] = %c , map[s[end]] = %d \n",end, s[end], map[s[end]]);
		if (map[s[end++]]-->0) counter--; //in t
		//printf("2222222 end = %d, s[end] = %c , map[s[end]] = %d, counter = %d \n", end,s[end], map[s[end]], counter);

										  //printf("2222222 begin = %d, s[begin] = %c ,end = %d, s[end] = %c \n", begin, s[begin], end, s[end]);
		printf("11111111 counter = %d \n", counter);
		printMap(map);
		while (counter == 0) { //valid
			if (end - begin<d)  d = end - (head = begin);
			printf("222222 begin = %d, s[begin] = %c ,end = %d, s[end] = %c \n", begin,s[begin], end, s[end]);
			if (map[s[begin++]]++ == 0)//the left set does not contain s[begin]
			{ 
				counter++;  //make it invalid
			}
			printf("22222222 counter = %d \n", counter);
			printMap(map);
		}
	}
	return d == INT_MAX ? "" : s.substr(head, d);
}

/*
vector<Interval> mergeIntervals(vector<Interval>& intervals) {
	if (intervals.empty()) return vector<Interval>{};
	vector<Interval> res;
	sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {return a.start < b.start; });
	res.push_back(intervals[0]);
	for (int i = 1; i < intervals.size(); i++) {
		if (res.back().end < intervals[i].start) res.push_back(intervals[i]);
		else
			res.back().end = max(res.back().end, intervals[i].end);
	}
	return res;
}
*/

/*
* clockwise rotate
* first reverse up to down, then swap the symmetry
* 1 2 3     7 8 9     7 4 1
* 4 5 6  => 4 5 6  => 8 5 2
* 7 8 9     1 2 3     9 6 3
*/
void rotate(vector<vector<int> > &matrix) {
	//first reverse
	reverse(matrix.begin(), matrix.end());
	for (int i = 0; i < matrix.size(); ++i) {
		for (int j = i + 1; j < matrix[i].size(); ++j)
			//then swap
			swap(matrix[i][j], matrix[j][i]);
	}
}

// travel all the words combinations to maintain a window
// there are wl(word len) times travel
// each time, n/wl words, mostly 2 times travel for each word
// one left side of the window, the other right side of the window
// so, time complexity O(wl * 2 * N/wl) = O(2N)
/*
vector<int> findSubstring(string S, vector<string> &L) {
	vector<int> ans;       int n = S.size(), cnt = L.size();
	if (n <= 0 || cnt <= 0) return ans;

	// init word occurence
	unordered_map<string, int> dict;
	for (int i = 0; i < cnt; ++i) dict[L[i]]++;

	// travel all sub string combinations
	int wl = L[0].size();
	for (int i = 0; i < wl; ++i) {
		int left = i, count = 0; unordered_map<string, int> tdict;
		for (int j = i; j <= n - wl; j += wl) {
			string str = S.substr(j, wl);
			// a valid word, accumulate results
			if (dict.count(str)) {
				tdict[str]++;
				if (tdict[str] <= dict[str])
					count++;
				else {
					// a more word, advance the window left side possiablly
					while (tdict[str] > dict[str]) {
						string str1 = S.substr(left, wl);
						tdict[str1]--;
						if (tdict[str1] < dict[str1]) count--;
						left += wl;
					}
				}
				// come to a result
				if (count == cnt) {
					ans.push_back(left);
					// advance one word
					tdict[S.substr(left, wl)]--;    count--;     left += wl;
				}
			}
			// not a valid word, reset all vars
			else {
				tdict.clear();   count = 0;   left = j + wl;
			}
		}
	}
	return ans;
}
*/

//my solution, for s = "12", it gives a result of 2 in vs2010
//however, in leetcode webpage, it output 0?????

int my_getWays(string s,/*char* s */ int len, int *ways);

int my_numDecodings(string s/*char* s */)
{
	const char* pchar = s.data();//strlen is for char* only
	//so you have to get char* by data()
	//u can also get char* by const char *pchar = s.c_str()
	int slen = strlen(pchar);
	int *ways = (int *)malloc(slen * sizeof(int));
	//memset(ways, 0, slen * sizeof(int));
	for (int i = 0; i< slen; i++)
		ways[i] = -1;
	return my_getWays(s,slen,ways);
}

int my_getWays(string s, int len, int *ways )
{
	cout << s << endl;
	int r = 0;
	if (ways[len] > -1)
		return ways[len];
	if (len == 1)
		r = 1;
	else if (len == 2)
	{
		if (s[0] == '1')
		{
			if (s[1] == '0')
				r = 1;
			else
			{
				cout << "len == 2" << endl;
				r = 2;

			}
		}
		else if (s[0] == '2' && s[1]<'7'&& s[1]>'0') //this is redundant.
		{
			r = 2;//the condition of len>2 and len=2 can be put together. 
		}
		else
		{ 
			r = 1;
		}
	}
	else
	{
		r = my_getWays(s.substr(1), len - 1, ways);//substr will cause compile error on leetcode
		//you should instead use pos to control.
		if( s[0]=='1' ||(s[0] == '2' && s[1]<'7'))
			r += my_getWays(s.substr(2), len - 2, ways);
	}

	ways[len] = r;
		return r;
}

int my_getWays_1(string &s, int pos, vector<int> &ways);
//improved version
int my_getWays_1(string &s, int pos, vector<int> &ways)
{
	int len = s.length();
	//cout << s << endl;
	int r = 0;
	if (ways[pos] > -1)
		return ways[pos];

	if (s[pos] == '0')
		return 0;

	if (pos >= len - 1)
		r = 1;
	else
	{
		r = my_getWays_1(s, pos + 1, ways);
		if (s[pos] == '1' || (s[pos] == '2' && s[pos + 1]<'7'))
			r += my_getWays_1(s, pos + 2, ways);
	}

	ways[pos] = r;
	return r;
}


int numDecodings(string s)
{
	int slen = s.length();  //use length() instead of convert to char*
	vector<int> memo(slen + 1, -1);//use vector to avoid malloc and memset
	return my_getWays_1(s, 0, memo);
}
//haha I'm so proud of this solution
//as my runtime beats 100% of c submissions
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
int getLenth(struct ListNode* head, struct ListNode** tail)
{
	int len = 0;
	while (head)
	{
		len++;
		*tail = head;
		head = head->next;
	}
	return len;

}

struct ListNode* rotateRight(struct ListNode* head, int k) {

	struct ListNode dmNode1;
	struct ListNode *p = &dmNode1;
	struct ListNode dmNode2;
	struct ListNode *tail = &dmNode2;
	dmNode1.next = head;

	int l = getLenth(head, &tail);
	if (l<2 || k == 0)
		return head;


	k = k%l;

	p->next = head;
	for (int i = 0; i<l - k; i++)
	{
		p = p->next;
	}
	tail->next = dmNode1.next;
	dmNode1.next = p->next;
	p->next = NULL;

	return dmNode1.next;
}

//this algorithm fail, because u can't use ! in program
//the result over flow
int uniquePaths0(int m, int n) {
	/*n -= 1;
	m -= 1;
	n += m;
	cout << n << " " << m;
	*/
	int nn = n - 1;
	int mm = m - 1;
	nn += mm;
	int child = 1;
	int par = 1;
	for (int k = nn; k>nn - mm; k--)
	{
		child *= k;
	}
	for (int i = mm; i>0; i--)
	{
		par *= i;
		cout <<"par = "<< par << endl ;
	}
	int r = child / par;

	return r;
}

int uniquePaths(int m, int n) {
	if (m == 0 || n == 0)
		return 0;
	if (m == 1 || n == 1)
		return 1;

	int nn = m-1 + n-1;
	int r = compose(nn, m-1);
	return r;

}

int compose(int nn, int m) {
	int r = 0;
	if (nn == m) {
		return 1;
	}
	if (m == 0) {
		return 1;
	}
	r = compose(nn - 1, m); //m exists in end nn-1
	r += compose(nn - 1, m - 1);
	return r;
}

bool isValidIPPart(string ipStr)
{
	if (ipStr == "")
		return false;

	if (ipStr[0] != '0' && atoi(ipStr.c_str()) <= 255)
		return true;
	else
		return false;
}

void findDotPos(int dotIndex, string s, int *dotPosSet, int Pos, vector<string> &res, string cur)
{
	string lastIP = "";
	if (dotIndex == 0)
	{
		//int partLen = Pos - dotPosSet[dotIndex - 1] + 1;
		lastIP = s.substr(0, Pos+1);
	}
	else if (dotIndex>0)
	{
		int partLen = Pos - (dotPosSet[dotIndex-1]+1) + 1;
		lastIP = s.substr(dotPosSet[dotIndex-1]+1, partLen);
	}
	cout << "dotIndex = " << dotIndex << " lastIP = " << lastIP << " cur = " << cur << endl;
	if (dotIndex == 3)
	{
		if (isValidIPPart(lastIP))
		{
			string complete = cur + lastIP;
			//dotPosSet[dotIndex] = Pos;
			//string ipStr = ""; 
			//for(int j = 0;j<4;j++){
			/*
			ipStr += s.substr(0,dotPosSet[0]+1)+"."+
			s.substr(dotPosSet[0]+1,dotPosSet[1]-dotPosSet[0])+"."+
			s.substr(dotPosSet[1]+1,dotPosSet[2]-dotPosSet[1])+"."+
			s.substr(dotPosSet[2]+1,s.length()-dotPosSet[2]);
			*/
			if(complete.length() == s.length()+3)
				res.push_back(complete);

				//}    
            
		}
		//else
		//{
		//cur = "";
		return;
		//}
	}
	else
	{
		if (isValidIPPart(lastIP) || dotIndex == -1)
		{
			int lastDotPos = -1;
			string lastValid = cur;
			if (isValidIPPart(lastIP))
			{
				lastDotPos = Pos;
				lastValid += lastIP + ".";
				dotPosSet[dotIndex] = Pos;
			}
			
			for(int i = 1; i <= 3; i++)
			{
				if((lastDotPos + i)<s.length())
					findDotPos(dotIndex + 1, s, dotPosSet, lastDotPos + i, res, lastValid);
			}
		}
		else
		{
			return;
		}

	}
}

vector<string> restoreIpAddresses(string s) {
	vector<string> res;
	int dotPosSet[4];
	string cur = "";
	findDotPos(-1, s, dotPosSet, 0, res, cur);
	return res;
}

int int_index = 0;  //全局索引变量

//二叉树构造器,按先序遍历顺序构造二叉树
//无左子树或右子树用'#'表示
void treeNodeConstructor(struct TreeNode* &root, int data[]) {
	int e = data[int_index++];
	if (e == -1) {
		root = NULL;
	}
	else {
		root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
		root->val = e;
		treeNodeConstructor(root->left, data);  //递归构建左子树
		treeNodeConstructor(root->right, data);  //递归构建右子树
	}
}

//this solution has a  ---conflicting types for 'check1'----error 
//in leetcode C language text page
//I don't konw why
//but as for C++ page, it is accepted, though the performance is quite bad
//only beats 1 percent of cpp submissions
bool isValidBST(struct TreeNode* root) {
	struct TreeNode* node = NULL;
	struct TreeNode** prev = &node;

	return(check1(root, prev));
}

bool check1(struct TreeNode* root, struct TreeNode** prev)
{
	if (root)
	{
		cout << root->val << " ";
		if (!check1(root->left, prev))
			return false;
		if (*prev)
		{
			if ((*prev)->val >= root->val)
			{
				cout<<"prev = "<< (*prev)->val <<endl;
				cout<<"root = "<< root->val <<endl;

				return false;
			}
		}
		*prev = root;
		return(check1(root->right, prev));
	}
	else
	{
		return true;
	}
}

/*
*/
// int findSubstring(string s) {

// 	vector<int> map(128, 0);
// 	int counter; // check whether the substring is valid
// 	int begin = 0, end = 0; //two pointers, one point to tail and one  head
// 	int d; //the length of substring

// 	for () { /* initialize the hash map here */ }

// 	while (end<s.size()) {
// 		if (map[s[end++]]-- ? ) {  /* modify counter here */ }
// 		while (/* counter condition */) {

// 			/* update d here if finding minimum*/

// 			//increase begin to make it invalid/valid again
// 			if (map[s[begin++]]++ ? ) { /*modify counter here*/ }
// 		}

// 		/* update d here if finding maximum*/
// 	}
// 	return d;
// }

//this soution also beat 100%
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
	int* ways = (int*)malloc(obstacleGridRowSize * sizeof(int));
	//memset(ways, '\0', obstacleGridRowSize * sizeof(int));

	for (int i = 0; i<obstacleGridRowSize; i++)
	{

		if (obstacleGrid[i][0]>0)
			ways[i] = 0;
		else
		{
			if (i == 0)
				ways[i] = 1;
			else
				ways[i] = ways[i - 1];
		}


	}

	for (int j = 1; j<obstacleGridColSize; j++)
	{

		for (int i = 0; i<obstacleGridRowSize; i++)
		{
			if (obstacleGrid[i][j]>0)
				ways[i] = 0;
			else
			{
				if (i == 0)
					ways[i] = ways[i];
				else
					ways[i] += ways[i - 1];
			}

		}
	}

	return ways[obstacleGridRowSize - 1];

}
