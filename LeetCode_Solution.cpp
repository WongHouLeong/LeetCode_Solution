#include<iostream>
#include<vector>
#include <map> 
#include <string>
using namespace std;
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		map<int, string> map;
	
		int minlen = 201;
		string minstr;
		for (auto str : strs)
		{
			if (minlen > str.length())
			{
				minlen = str.length();
				minstr = str;
			}
		}
		map.insert(pair<int, string >( minstr.length(), minstr));
		int arrylen = strs.size();
		int len = minlen;
		for (auto str : strs)
		{
			string tmp;
			for (int i = 0; i < minlen; i++)
			{
				if ((str[i] == minstr[i]) && (str != minstr))
				{
					tmp = tmp + str[i];
				}
			}
			map.insert(pair<int, string >( tmp.length()-1,tmp));
			if (len > tmp.length() - 1)
				len = tmp.length() - 1;
		}
		string ret = map.find(len)->second;
		if (ret.length() == minlen && arrylen == 1)
			return minstr;
		else if(ret.length() == minlen)
			return "";
		else
		return map.find(len)->second;
	}
};


int main() {
	Solution s;
	vector<string> strs = { "ab","a" };

	cout << s.longestCommonPrefix(strs);
	return 0;
}
