#include <iostream>
using namespace std;
#include <vector>

int maxProfit(vector<int>& prices) {
    if (prices.size() == 0) return 0; //考虑边界情况
    vector<vector<int>> dp(prices.size(), vector<int>(4, 0));
    dp[0][0] = -prices[0]; //考虑初始化：主要考虑第0天

    for (int i = 1; i < prices.size(); i++) //从第一天开始考虑
    {
        dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][3], dp[i - 1][1]) - prices[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][3]);
        dp[i][2] = dp[i - 1][0] + prices[i];
        dp[i][3] = dp[i - 1][2];
    }

    return max(dp[prices.size() - 1][1], max(dp[prices.size() - 1][2], dp[prices.size() - 1][3])); //最后返回状态2,3,4的最大值
}