#include <iostream>
using namespace std;
#include <vector>

int lastStoneWeight(vector<int>& stones)
{
	int sum = 0;
	for (auto itStone = stones.begin(); itStone != stones.end(); itStone++)
	{
		sum += (*itStone);
	}

	int target = sum / 2;
	vector<int> dp(target + 1, 0);

	for (int i = 0; i < stones.size(); i++)
	{
		for (int j = target; j >= stones[i]; j--)
		{
			dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
		}
	}
	return (sum - dp.back()) - dp.back();
}


//int main()
//{
//	int a[6] = { 2,7,4,1,8,1};
//	vector<int> stones(a[0], a[0] + 6);
//
//
//	int last = lastStoneWeight(stones);
//	cout << last << endl;
//
//	system("pause");
//	return 0;
//}