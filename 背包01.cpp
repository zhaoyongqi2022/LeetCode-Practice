#include <iostream>

using namespace std;

#include <vector>

void print2DVector(vector<vector<int>> dp)
{
	for (auto i = dp.begin(); i != dp.end(); i++)
	{
		for (auto j = 0; j < (*i).size(); j++)
		{
			cout << (*i)[j] << " ";
		}
		cout << endl;
	}
}

void bag01()
{
	// get useful information
	vector<int> weight = { 1, 3, 4 };
	vector<int> value = { 15, 20, 30 };
	int bagWeight = 4;

	// define dp array
	vector<vector<int>> dp(weight.size(), vector<int>(bagWeight + 1, 0));
	print2DVector(dp);
	cout << endl;

	// initialize dp[0][j]
	// watch out the boundary for loop: (j=1 or j=0?), (j<bagWeight or j<=bagWeight?)
	for (auto j = 1; j <= bagWeight; j++)
	{
		dp[0][j] = value[0];
	}
	print2DVector(dp);
	cout << endl;

	// dynamic programming
	// boundary of for loop: (i=1 or i=0)?
	for (auto i = 1; i < weight.size(); i++)
	{
		// watch out the boundary for loop: (j=1 or j=0?), (j<bagWeight or j<=bagWeight?)
		for (auto j = 1; j <= bagWeight; j++)
		{
			if (j < weight[i])
			{
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
			}
		}
	}

	print2DVector(dp);

	cout << endl;
	cout << dp[weight.size()-1][bagWeight] << endl;
}


//int main()
//{
//
//	bag01();
//
//	system("pause");
//	return 0;
//}