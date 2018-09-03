#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:

	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int> > vctRs;
		//ordered seq
		sort(nums.begin(), nums.end());

		for (int i = 0; i<nums.size() - 2; i++)
		{
			int sum = 0 - nums[i];

			int l = i + 1;
			int r = vctRs.size() - 1;
			while (l< r)
			{
				if (nums[l] + nums[r] + nums[i] == 0)
				{
					vector<int> v;
					v.push_back(nums[i]);
					v.push_back(nums[l]);
					v.push_back(nums[r]);
					vctRs.push_back(v);

					while (l < r && nums[l] == nums[l + 1])
						l++;
					while (l < r && nums[r] == nums[r - 1])
						r--;
				}
				else if (nums[l] + nums[r] < sum)
					l++;
				else
					r--;
			}
			while (i<nums.size() - 2 && nums[i + 1] == nums[i])
			{
				i++;
			}

		}

		return vctRs;
	}
};
int main(int argc, char** argv )
{
	Solution s;

	vector<int > nums;
	nums.push_back(1);
	nums.push_back(0);
	nums.push_back(-1);
	nums.push_back(-1);
	nums.push_back(2);
	nums.push_back(4);
	s.threeSum(nums);
	return 0;
}