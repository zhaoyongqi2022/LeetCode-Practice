#include <iostream>
using namespace std;

#include<vector>
#include<algorithm>

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

    int rowSize = obstacleGrid.size();
    int columnSize = obstacleGrid[0].size();
    if (rowSize == 0 || columnSize == 0) return NULL;

    if (obstacleGrid[0][0] == 1) return NULL;

    for (int i = 0; i < rowSize; i++) {
        obstacleGrid[i][0] = 1;
    }

    for (int j = 0; j < columnSize; j++) {
        obstacleGrid[0][j] = 1;
    }

    for (int i = 1; i < rowSize; i++) {
        for (int j = 1; j < columnSize; j++) {
            if (obstacleGrid[i][j] == 1) {
                obstacleGrid[i][j] = 0;
                break;
            }
            obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
        }
    }

    return obstacleGrid[rowSize - 1][columnSize - 1];
}

int main() {
    vector<vector<int>> obstacleGrid = { {0,0,0},{0,1,0},{0,0,0} };
    int answer = uniquePathsWithObstacles(obstacleGrid);
    //int rowSize = obstacleGrid.size();

    system("pause");
    return 0;
}