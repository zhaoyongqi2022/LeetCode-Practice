#include <iostream>
using namespace std;
#include <unordered_set>
#include <vector>
#include <string>

bool wordBreak(string s, vector<string>& wordDict)
{
	unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
	vector<bool> dp(s.size() + 1, false);
	dp[0] = true;

	for (int i = 1; i <= s.size(); i++) //遍历背包容量
	{
		for (int j = 0; j < i; j++) //遍历物品
		{
			string word = s.substr(j, i - j); //substr（起始位置， 开始坐标）
			if (wordSet.find(word) != wordSet.end() && dp[j])
			{
				dp[i] = true;
			}
		}
	}
	return dp.back();
}

//int main()
//{
//	string s = "leetcode";
//	string dict1 = "leet";
//	string dict2 = "code";
//	vector<string> wordDict;
//	wordDict.push_back(dict1);
//	wordDict.push_back(dict2);
//
//	bool res = wordBreak(s,wordDict);
//
//
//	system("pause");
//	return 0;
//}