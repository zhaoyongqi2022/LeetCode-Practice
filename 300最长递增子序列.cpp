#include <iostream>
using namespace std;
#include <vector>

int lengthOfLIS(vector<int>& nums) {
    vector<int> dp(nums.size(), 1);
    int res = 0;

    for (int i = 1; i < nums.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        cout << "dp[i]: " << dp[i] << "    " << "res: " << res << endl;
        if (dp[i] > res)
        {
            res = dp[i];
        }
    }
    return res;
}

//int main()
//{
//    int a[6] = { 4, 10, 4, 3, 8, 9 };
//    vector<int> nums = { 4, 10, 4, 3, 8, 9 };
//
//    int res = lengthOfLIS(nums);
//
//    system("pause");
//    return 0;
//}