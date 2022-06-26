#include <iostream>
using namespace std;
#include <vector>

int numSquares(int& n)
{
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    ////�ȱ�����Ʒ������������
    //for (int i = 1; i * i <= n; i++) //������Ʒ
    //{
    //    for (int j = 1; j <= n; j++) // ������������
    //    {
    //        if (j >= i * i)
    //        {
    //            dp[j] = min(dp[j], dp[j - i * i] + 1);
    //        }
    //    }
    //}


    //�ȱ��������ٱ�����Ʒ
    for (int i = 0; i <= n; i++) //������������:i��0����1��ʼ������Ҫ��
    {
        for (int j = 1; j * j <= i; j++) //������Ʒ����Ҫ����j*j<= i,����ĵ��ںŲ�����ʡ��
        {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }
    return dp.back();
}

//int main()
//{
//    int n = 5;
//    int res = numSquares(n);
//    system("pause");
//    return 0;
//}