#include <iostream>
using namespace std;
#include <vector>
#include <string>

int countSubstrings(string s) {
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false)); //必须初始化为false:不明白dp[0][0]为什么不能初始化为true，因为第一个字母肯定回文

    int count = 0;
    for (int i = s.size(); i >= 0; i--)//从下往上，从左向右遍历：因为dp[i][j]依赖于dp[i+1][j-1]
    {
        for (int j = i; j < s.size(); j++)
        {
            if (s[i] == s[j])
            {
                if (j - i <= 1)
                {
                    dp[i][j] = true;
                    count++;
                }
                else if (dp[i + 1][j - 1])//递推公式非常重要
                {

                    dp[i][j] = true;
                    count++;
                }
            }
        }
    }
    return count;
}