#include <iostream>
using namespace std;

#include<vector>
#include<algorithm>

int fibNumbers(int n) {
	//如果n为初始化值，则直接返回
	if (n <= 1) return n;

	//n>=2
	vector<int> dp(n+1);
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}



//int main()
//{
//	int n = 10;
//	int result = fibNumbers(10);
//
//	system("pause");
//	return 0;
//}