#include <iostream>
using namespace std;

#include<vector>
#include<algorithm>



int uniquePaths(int m, int n) {
    if (m <= 0 || n <= 0) return NULL;

    vector<vector<int>> dp(m, vector<int>(n, 0));
    // Initialization of the first row
    for (int i = 0; i < m; i++) {
        dp[i][0] = 1;
    }

    // Initialization of the first column
    for (int j = 0; j < n; j++) {
        dp[0][j] = 1;
    }

    // Double for-loop to realize dynamic programming
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return dp[m - 1][n - 1];
}