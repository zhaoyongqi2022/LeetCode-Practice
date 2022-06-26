#include <iostream>
using namespace std;
#include <vector>

int numSquares(int& n)
{
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    ////先遍历物品再来遍历容量
    //for (int i = 1; i * i <= n; i++) //遍历物品
    //{
    //    for (int j = 1; j <= n; j++) // 遍历背包容量
    //    {
    //        if (j >= i * i)
    //        {
    //            dp[j] = min(dp[j], dp[j - i * i] + 1);
    //        }
    //    }
    //}


    //先遍历容量再遍历物品
    for (int i = 0; i <= n; i++) //遍历背包容量:i从0或者1开始并不重要，
    {
        for (int j = 1; j * j <= i; j++) //遍历物品：重要的是j*j<= i,这里的等于号并不能省略
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