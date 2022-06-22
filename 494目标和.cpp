#include <iostream>
using namespace std;
#include <vector>

int findTargetSumWay(vector<int>& nums, int& target)
{
	int sum = 0;
	for (auto itNums = nums.begin(); itNums != nums.end(); itNums++)
	{
		sum += (*itNums);
	}

	if ((sum + target) % 2 == 1) return 0;
	if (abs(target) > sum) return 0;
	int bagSize = (sum + target) / 2;

	vector<int> dp(bagSize + 1, 0);
	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = bagSize; j >= nums[i]; j--)
		{
			dp[j] += dp[j - nums[i]];
		}
	}

	return dp.back();
}

//int main()
//{
//	int num[5] = { 1,1,1,1,1, };
//	vector<int> nums(num[0], num[0] + 5);
//	int target = 3;
//	int res = findTargetSumWay(nums, target);
//	cout << res << endl;
//
//	system("pause");
//	return 0;
//}