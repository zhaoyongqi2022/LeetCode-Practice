#include <iostream>
using namespace std;
#include <vector>


int findMaxForm(vector<string>& strs, int m, int n)
{
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
	for (string str : strs) // traversal object
	{
		int zeroNum = 0;
		int oneNum = 0;
		for (char c : str)
		{
			if (c == '0')
			{
				zeroNum++;
			}
			else
			{
				oneNum++;
			}
		}
		for (int i = m; i >= zeroNum; i--) // traversal volume
		{
			for (int j = n; j >= oneNum; j--)
			{
				dp[i][j] = max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1);
			}
		}
	}
	return dp[m][n];
}


//int main()
//{
//	string str[5] = { "10", "0001", "111001", "1", "0" };
//	vector<string> strs(str, str + 5);
//	int m = 5, n = 3;
//
//	int res = findMaxForm(strs, m, n);
//
//	cout << res << endl;
//
//	system("pause");
//	return 0;
//}