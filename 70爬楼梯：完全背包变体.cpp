#include <iostream>
using namespace std;
#include <vector>

// n:¥���ܽ���
// m:ÿ����1....m
int climb(int& n, vector<int>& obj)
{
	if (n <= 2)
	{
		return n;
	}
	vector<int> dp(n + 1, 0);
	dp[0] = 1;

	//i��1��ʼ
	for (int i = 1; i <= n; i++)//��������������
	{
		for (int j = 0; j < obj.size(); j++)//�ڲ������Ʒ
		{
			if (i >= obj[j])
			{
				dp[i] += dp[i - obj[j]];
			}
		}
	}
	return dp.back();
}