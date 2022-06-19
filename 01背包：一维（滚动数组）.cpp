#include <iostream>
using namespace std;

#include <vector>

void printVector(vector<int> v)
{
	for (auto i = v.begin(); i != v.end(); i++)
	{
		cout << (*i) << endl;
	}
}

//int main()
//{
//	vector<int> weight = { 1, 3, 4 };
//	vector<int> value = { 15, 20, 30 };
//	int bagWeight = 4;
//
//	vector<int> dp(bagWeight + 1, 0); // mistake 3
//	printVector(dp);
//	cout << " " << endl;
//
//	for (int i = 0; i < weight.size(); i++)
//	{
//		//for (int j = bagWeight; j > 0; j--): mistake 1: j >= weight[i]; 背包容量不小于物品重量
//		for (int j = bagWeight; j >= weight[i]; j--)
//		{
//			dp[j] = max(dp[j], dp[j - weight[i]] + value[i]); // mistake 2
//		}
//	}
//
//	cout << dp[bagWeight] << endl;
//	cout << " " << endl;
//
//	printVector(dp);
//
//	system("pause");
//	return 0;
//}