#include<iostream>
#include<vector>
#include <map> 
using namespace std;
class Solution {
public:
	int romanToInt(string s) {
		map<char, int> map = { {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000} };
		size_t len = s.length();
		int sum = 0;
		int tmp = 0;
		for (int i = 1; i < len + 1; i++) //ѭ����1��ʼ
		{
			tmp = map.find(s[i - 1])->second;//����һλ����ֵ
			if (i == len) //�ж�һ���Ƿ�Խ�磬�Ǿ�ֱ�Ӽ���ĩλ������ѭ��
			{
				sum = sum + map.find(s[i - 1])->second;
				return sum;
			}
			if (tmp - map.find(s[i])->second >= 0)//���ǰһλ�����ڴ��ڻ���ڣ�ֱ�Ӽ���ǰλ
				sum += tmp;
			else
			{
				sum += map.find(s[i])->second - tmp;//���ǰһλ������С����������ټ��ܣ���һλ��
				i++;
			}

		}
		return sum;
	}
};

class SolutionSmart {
public:
	int romanToInt(string s) {
		string roman = "IVXLCDM";
		int intnum[] = { 1, 5, 10, 50, 100, 500, 1000 };
		int result = 0, temp1;
		string::iterator its = s.begin();

		while (next(its) != s.end()) {
			temp1 = intnum[roman.find(*its)];
			if (temp1 < intnum[roman.find(*next(its))])
				result -= temp1;
			else
				result += temp1;
			its++;
		}
		result += intnum[roman.find(*its)];
		return result;
	}
};

int main() {
	SolutionSmart s;
	int c = s.romanToInt("MCMXCIV");
	int d = s.romanToInt("IV");
	int e = s.romanToInt("IX");
	return 0;
}
