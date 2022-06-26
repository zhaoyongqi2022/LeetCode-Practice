#include <iostream>
using namespace std;
#include <vector>

int robRange(vector<int>& nums, int start, int end)
{
    vector<int> dp(nums.size(), 0);
    dp[start] = nums[start];
    dp[start + 1] = max(nums[start], nums[start + 1]);

    for (int i = start + 2; i <= end; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }
    return dp[end];
}

int rob2(vector<int>& nums) {
    if (nums.size() == 1)
    {
        return nums[0];
    }
    else if (nums.size() == 2)
    {
        return max(nums[0], nums[1]);
    }
    //有首无尾
    int res1 = robRange(nums, 0, nums.size() - 2);
    // 无首有尾
    int res2 = robRange(nums, 1, nums.size() - 1);

    return max(res1, res2);
}

//int main()
//{
//    int a[4] = { 1,2, 3, 1 };
//    vector<int> nums(a, a + 4);
//
//    int res = rob2(nums);
//
//    system("pause");
//    return 0;
//}