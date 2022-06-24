#include <iostream>
using namespace std;
#include <vector>


int combinationSum4(vector<int>& nums, int target) {
    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    for (int j = 0; j <= target; j++) // bag volume
    {
        for (int i = 0; i < nums.size(); i++) // object
        {
            if (j >= nums[i] && dp[j] < INT_MAX - dp[j - nums[i]])
            {
                dp[j] += dp[j - nums[i]];
            }
        }
    }
    return dp.back();
}


//int main()
//{
//
//    system("pause");
//    return 0;
//}