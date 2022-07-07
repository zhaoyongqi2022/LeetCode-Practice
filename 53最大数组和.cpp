#include <iostream>
using namespace std;
#include <vector>

int maxSubArray2(vector<int>& nums) {
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];

    int res = dp[0];

    for (int i = 1; i < nums.size(); i++)
    {
        dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        if (dp[i] > res)
        {
            res = dp[i];
        }
    }
    return res;
}

//int main()
//{
//    vector<int> nums = { -1, -2 };
//    int res = maxSubArray2(nums);
//
//    system("pause");
//    return 0;
//}