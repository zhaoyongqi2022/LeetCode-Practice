#include <iostream>
using namespace std;

#include<vector>
#include<algorithm>

int integerBreak(int n) {
    vector<int> dp(n+1, 0);

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 1;

    for (int i = 3; i <= n; i++) {
        for (int j = 1; j < i-1; j++) {
            dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j])); //注意这里必须比较dp[i]本身，因为如果不比较那么默认每次输出的dp[i]都是j取值为i-2的值，dp[i]会被自动覆盖
            //dp[i] = max(j * (i - j), j * dp[i - j]);
        }
    }
    return dp[n];
}

int main() {

    int answer = integerBreak(6);

    system("pause");
    return 0;
}