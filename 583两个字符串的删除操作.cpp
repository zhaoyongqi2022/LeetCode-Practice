#include <iostream>
using namespace std;
#include <vector>
#include <string>

void printVec(vector<vector<int>>& vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[0].size(); j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}

int minDistance(string word1, string word2) {
    vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));

    for (int i = 0; i <= word1.size(); i++)
    {
        dp[i][0] = i;
    }

    for (int j = 0; j <= word2.size(); j++)
    {
        dp[0][j] = j;
    }

    for (int i = 1; i <= word1.size(); i++)
    {
        for (int j = 1; j <= word2.size(); j++)
        {
            if (word1[i - 1] == word2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + 2));
            }
        }
    }

    printVec(dp);

    return dp[word1.size()][word2.size()];
}
