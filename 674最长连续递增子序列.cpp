#include <iostream>
using namespace std;
#include <vector>

int findLengthOfLCIS(vector<int>& nums) {
    if (nums.size() == 1)
    {
        return 1;
    }
    vector<int> dp(nums.size(), 1);
    int res = 0; //初始化为0或者1都无所谓

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] > nums[i - 1])
        {
            dp[i] = dp[i - 1] + 1;
        }

        if (dp[i] > res) //这一步非常不理解
        {
            res = dp[i];
        }
    }

    return res;
}