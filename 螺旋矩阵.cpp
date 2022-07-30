#include <iostream>
using namespace std;
#include <vector>

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> result(n, vector<int>(n, 0));
    int startx = 0, starty = 0; //每层遍历的起始和终止
    int loop = n / 2; //需要遍历的圈数
    int mid = n / 2; //矩阵的最中间位置
    int count = 1; //需要赋予的值
    int offset = 1; //每次循环，右边界都要收缩一位

    while (loop--)
    {
        int i = startx;
        int j = starty;

        //上行[)
        for (j = startx; j < n - offset; j++)
        {
            result[i][j] = count++;
        }

        //右列[)
        for (i = startx; i < n - offset; i++)
        {
            result[i][j] = count++;
        }

        //下行[)
        for (; j > starty; j--)
        {
            result[i][j] = count++;
        }

        //左列[)
        for (; i > startx; i--)
        {
            result[i][j] = count++;
        }

        startx++;
        starty++;
        offset++;
    }

    if (n % 2 == 1)
    {
        result[mid][mid] = count;
    }
    return result;
}