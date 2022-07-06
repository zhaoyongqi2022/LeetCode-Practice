#include <iostream>
using namespace std;
#include <vector>

int longestCommonSubsequence(string text1, string text2) {
    vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));

    for (int i = 1; i <= text1.size(); i++)
    {
        for (int j = 1; j <= text2.size(); j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1; //�����ǰ�ַ���ͬ�����һ
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); //�����ǰ�ַ�����ͬ����ֱ�Ƚ�text1[0, i - 1], text2[0, j - 2] �� text1[0, i - 2], text2[0,  j - 1] Ȼ��ȡ���ֵ
            }
        }
    }

    return dp[text1.size()][text2.size()];
}