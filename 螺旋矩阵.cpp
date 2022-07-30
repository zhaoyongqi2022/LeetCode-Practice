#include <iostream>
using namespace std;
#include <vector>

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> result(n, vector<int>(n, 0));
    int startx = 0, starty = 0; //ÿ���������ʼ����ֹ
    int loop = n / 2; //��Ҫ������Ȧ��
    int mid = n / 2; //��������м�λ��
    int count = 1; //��Ҫ�����ֵ
    int offset = 1; //ÿ��ѭ�����ұ߽綼Ҫ����һλ

    while (loop--)
    {
        int i = startx;
        int j = starty;

        //����[)
        for (j = startx; j < n - offset; j++)
        {
            result[i][j] = count++;
        }

        //����[)
        for (i = startx; i < n - offset; i++)
        {
            result[i][j] = count++;
        }

        //����[)
        for (; j > starty; j--)
        {
            result[i][j] = count++;
        }

        //����[)
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