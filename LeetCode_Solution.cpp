#include<iostream>
#include<vector>
#include <map> 
using namespace std;
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		size_t size = nums.size();
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (j == i)
					break;
				if (nums[i] + nums[j] == target)
				{
					return { i,j };
				}
			}
		}
		return {};
	}
};

class SolutionSmart {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            static map<int, int> mapIndex;
            const size_t size = nums.size();
            int nCount = 0;
            bool bMapped = false;
            mapIndex.clear();
            for (const auto& num : nums)
            {
                const auto& itFind = mapIndex.find(target - num);
                if (itFind != mapIndex.end())
                {
                    return vector<int>{nCount, itFind->second};
                }

                if (target - num != num)
                {
                    mapIndex[num] = nCount;
                }
                else if (!bMapped)
                {
                    mapIndex[num] = nCount;
                    bMapped = true;
                }

                nCount++;
            }

            return vector<int>();
        }
    };

int main() {
	SolutionSmart s;
	vector<int> a = { 1,2,3 };
	vector<int> z= s.twoSum(a, 5);
	return 0;
}
