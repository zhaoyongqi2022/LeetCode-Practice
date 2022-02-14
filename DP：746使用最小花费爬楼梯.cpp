#include <iostream>
using namespace std;

#include<vector>
#include<algorithm>

int minCostClimbingStairs(vector<int>& cost) {
    int costLength = cost.size();
    if (costLength <= 1) return cost[costLength - 1];

    vector<int> dp(costLength);
    //注意这里的初始化并没有初始化为爬到第0或者1台阶所需的最少体力
    dp[0] = cost[0];
    dp[1] = cost[1];
    for (int i = 2; i < costLength; i++) {
        dp[i] = min(dp[i - 1], dp[i - 2])+cost[i];
    }
    return min(dp[costLength - 1], dp[costLength - 2]);//这里并没有直接返回最后一个dp元素而是比较了最后两个值
}


//int minCostClimbingStairs(vector<int>& cost) {
//    vector<int> dp(cost.size());
//    dp[0] = cost[0];
//    dp[1] = cost[1];
//    for (int i = 2; i < cost.size(); i++) {
//        dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
//    }
//    // 注意最后一步可以理解为不用花费，所以取倒数第一步，第二步的最少值
//    return min(dp[cost.size() - 1], dp[cost.size() - 2]);
//}


//int main()
//{
//    vector<int> cost = {0,1,1,0};
//    int result = minCostClimbingStairs(cost);
//
//	system("pause");
//	return 0;
//}