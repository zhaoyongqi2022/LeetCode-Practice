#include <iostream>
using namespace std;
#include <vector>

int findLengthOfLCIS(vector<int>& nums) {
    if (nums.size() == 1)
    {
        return 1;
    }
    vector<int> dp(nums.size(), 1);
    int res = 0; //��ʼ��Ϊ0����1������ν

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] > nums[i - 1])
        {
            dp[i] = dp[i - 1] + 1;
        }

        if (dp[i] > res) //��һ���ǳ������
        {
            res = dp[i];
        }
    }

    return res;
}