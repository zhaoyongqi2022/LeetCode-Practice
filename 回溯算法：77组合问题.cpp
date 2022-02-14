#include <iostream>
using namespace std;

#include<vector>


vector<int> path;
vector<vector<int>> result;

void backtracking(int n, int k, int startIndex) {
	if (path.size() == k) {
		result.push_back(path);
		return;
	}

	for (int i = startIndex; i <= n; i++) { //剪枝操作就是限制for循环的遍历次数：如果for循环起始位置之后的元素个数不满足我们需要的元素个数就没有必要再进行遍历了
		// 1.已选择个数：path.size()
		// 2.还需要的元素个数：k-path.size()
		// 3.for循环中最多可以从n-(k-path.size())+1开始遍历 （这里的+1可以自己举个例子试试）
		path.push_back(i);
		backtracking(n, k, i + 1);
		path.pop_back();
	}
}

//int main()
//{
//	int n = 4;
//	int k = 2;
//	int startIndex = 0;
//	backtracking(n, k, startIndex);
//	system("pause");
//	return 0;
//}