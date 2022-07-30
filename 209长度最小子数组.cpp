#include <iostream>
using namespace std;
#include <vector>

// 超时算法
int minSubArrayLen(int target, vector<int>& nums) {
    int minLen = INT_MAX;
    
    for (int i = 0; i < nums.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < nums.size(); j++)
        {
            sum += nums[j];
            if (sum >= target)
            {
                minLen = min(minLen, j - i + 1);
                break;
            }
        }
    }
    if (minLen != INT_MAX)
    {
        return minLen;
    }
    else
    {
        return 0;
    }
}

//滑动窗口
int minSubArrayLen(int target, vector<int>& nums) {
    int minLen = INT_MAX;
    int i = 0;
    int sum = 0;
    for (int j = 0; j < nums.size(); j++)
    {
        sum += nums[j];
        while (sum >= target)
        {
            minLen = min(minLen, j - i + 1);
            sum -= nums[i];
            i++;
        }
    }
    if (minLen != INT_MAX)
    {
        return minLen;
    }
    else
    {
        return 0;
    }
}

