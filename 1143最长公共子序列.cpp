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
                dp[i][j] = dp[i - 1][j - 1] + 1; //如果当前字符相同，则加一
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); //如果当前字符不相同，则分别比较text1[0, i - 1], text2[0, j - 2] 和 text1[0, i - 2], text2[0,  j - 1] 然后取最大值
            }
        }
    }

    return dp[text1.size()][text2.size()];
}