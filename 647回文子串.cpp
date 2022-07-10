#include <iostream>
using namespace std;
#include <vector>
#include <string>

int countSubstrings(string s) {
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false)); //�����ʼ��Ϊfalse:������dp[0][0]Ϊʲô���ܳ�ʼ��Ϊtrue����Ϊ��һ����ĸ�϶�����

    int count = 0;
    for (int i = s.size(); i >= 0; i--)//�������ϣ��������ұ�������Ϊdp[i][j]������dp[i+1][j-1]
    {
        for (int j = i; j < s.size(); j++)
        {
            if (s[i] == s[j])
            {
                if (j - i <= 1)
                {
                    dp[i][j] = true;
                    count++;
                }
                else if (dp[i + 1][j - 1])//���ƹ�ʽ�ǳ���Ҫ
                {

                    dp[i][j] = true;
                    count++;
                }
            }
        }
    }
    return count;
}