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

	for (int i = 1; i <= s.size(); i++) //������������
	{
		for (int j = 0; j < i; j++) //������Ʒ
		{
			string word = s.substr(j, i - j); //substr����ʼλ�ã� ��ʼ���꣩
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