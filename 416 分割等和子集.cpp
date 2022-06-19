#include <iostream>
using namespace std;
#include <vector>

bool canPartition(vector<int> nums)
{
	int sum = 0;
	for (auto itNums = nums.begin(); itNums != nums.end(); itNums++)
	{
		sum += (*itNums);
	}

	if (sum % 2 == 1)
	{
		return false;
	}

	int bagWeight = sum / 2;
	vector<int> dp(bagWeight + 1, 0);
	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = bagWeight; j >= nums[i]; j--)
		{
			dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
		}
	}

	if (dp.back() == bagWeight)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//int main()
//{
//
//	vector<int> nums = { 1,5,11,5 };
//	bool res = canPartition(nums);
//	cout << res << endl;
//
//	system("pause");
//	return 0;
//}