#include <iostream>
using namespace std;
#include <vector>

int maxProfit(int k, vector<int>& prices) {
    if (prices.size() == 0) return 0;//���Ǳ߽����
    vector<vector<int>> dp(prices.size(), vector<int>(2 * k + 1, 0)); //�����������������ɹ�Ʊ�۸�����ĳ��Ⱦ�����
    for (int j = 1; j < 2 * k + 1; j += 2)
    {
        dp[0][j] = -prices[0];//��0�����е��������ֽ�Ϊ-prices[0]
    }

    for (int i = 1; i < prices.size(); i++)//��Ϊ֮ǰ��ʼ���˵�0�죬��˴ӵ�1�쿪ʼ
    {
        for (int j = 0; j < 2 * k - 1; j += 2)//ͨ��j������ż�����������Ӷ����ƹ�Ʊ������״̬
        {
            dp[i][j + 1] = max(dp[i - 1][j] - prices[i], dp[i - 1][j + 1]);
            dp[i][j + 2] = max(dp[i - 1][j + 1] + prices[i], dp[i - 1][j + 2]);
        }
    }
    return dp[prices.size() - 1][2 * k];
}