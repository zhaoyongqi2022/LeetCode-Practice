#include <iostream>
using namespace std;

#include<vector>
#include<algorithm>

int minCostClimbingStairs(vector<int>& cost) {
    int costLength = cost.size();
    if (costLength <= 1) return cost[costLength - 1];

    vector<int> dp(costLength);
    //ע������ĳ�ʼ����û�г�ʼ��Ϊ������0����1̨���������������
    dp[0] = cost[0];
    dp[1] = cost[1];
    for (int i = 2; i < costLength; i++) {
        dp[i] = min(dp[i - 1], dp[i - 2])+cost[i];
    }
    return min(dp[costLength - 1], dp[costLength - 2]);//���ﲢû��ֱ�ӷ������һ��dpԪ�ض��ǱȽ����������ֵ
}


//int minCostClimbingStairs(vector<int>& cost) {
//    vector<int> dp(cost.size());
//    dp[0] = cost[0];
//    dp[1] = cost[1];
//    for (int i = 2; i < cost.size(); i++) {
//        dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
//    }
//    // ע�����һ���������Ϊ���û��ѣ�����ȡ������һ�����ڶ���������ֵ
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