#include "stdafx.h"

#include <iostream>
#include <string>

#include<vector>
#include<algorithm>
using namespace std;

#include "forCPP.h"
#include "lintcode.h"


int testLintCode()
{
	//int res = numWays(3, 2);

//	string input = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";
	               //"dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext"
	string input = "dir\n        file.txt";

	int res = lengthLongestPath(input);

	return res;
}


/**
* @param digits: a number represented as an array of digits
* @return: the result
*/
vector<int> plusOne(vector<int> &digits) {

	// write your code here
	int digit_len = digits.size();
	int i = digit_len - 1;
	while (i >= 0)
	{
		if (digits[i]<9) {
			digits[i] += 1;
			return digits;
		}
		else {
			digits[i] = 0;
			i--;
		}

	}
	vector<int> res;
	//if(i == -1)
	{
		//res[0]=1;
		res.push_back(1);
		for (int index = 0; index < digit_len; index++)
			res.push_back(0);

	}
	return res;

}

int numWays(int n, int k) {
	int ways_cur = 0;
	int same = 0;
	int diff = 0;

	if (k == 1 && n>2)
		return 0;

	for (int i = 0; i <= n; i++)
	{

		if (i <= 1)
		{
			ways_cur = k;
		}
		else if (i == 2) {
			ways_cur = k*k;
			same = k*(k - 1);
		}
		else
		{
			diff = ways_cur * (k - 1);
			ways_cur = same + diff;
			same = diff;
		}
	}

	return ways_cur;

}


int lengthLongestPath(string &input) {
	// write your code here
	int start = 0; int end = 0;
	int pos = 0;
	int level = 0;
	int last_level = 0;
	int cur_path = 0;
	//int cur = 0;
	int longest = 0;
	string cur_sub_path = "";
	int folder_path = 0;
	vector<string> folder_paths;
	vector<int> folders;
	int len = input.length();
	while (pos < len) {

		if (input[pos] == '\0')
			break;

		start = pos;
		while (input[pos] != '\n')
		{
			//if (input[pos] == ' ')
			//	start = pos+1;

			if (pos == len)
				break;
			pos++;
		}
		end = pos - 1;
		cur_sub_path = input.substr(start, end - start + 1);
		//cur_sub_path = end - start + 1;
		//level++;
		//if (cur_sub_path.find(".")>0)
		string::size_type idx = cur_sub_path.find(".");
		if (idx != string::npos)
		{
			cur_path = folder_path + cur_sub_path.length();
			if (cur_path > longest)
				longest = cur_path;
		}
		else
		{
			if (level < folders.size())
			{
				folder_paths[level] = cur_sub_path;
				folders[level] = cur_sub_path.length();
				folder_path = 0;
				for (int i = 0; i <= level; i++)
					folder_path += (folders[i] + 1);
			}
			else
			{
				folder_paths.push_back(cur_sub_path);
				folders.push_back(cur_sub_path.length());
				folder_path += (cur_sub_path.length() + 1);
			}

		}
		level = 0;
		if (input[pos] == '\n')
		{
			pos++;
			int space = 0;
			while (input[pos] == ' ')
			{
				pos++;
				space++;
			}
			level += space / 4;
			while (input[pos] == '\t')
			{
				level += 1;
				pos += 1;
			}
			//if (pos == (len - 1))
			//	break;
		}
	}

	return longest;

}
