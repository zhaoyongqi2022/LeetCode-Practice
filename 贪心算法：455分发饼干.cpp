#include <iostream>
using namespace std;

#include<vector>
#include<algorithm>


int cookiesDistribution(vector<int>& g, vector<int>& s) {
	//先对输入的饼干和孩子数组进行排序
	sort(g.begin(), g.end());
	sort(s.begin(), s.end());

	//两个数组的大小
	int gLength = g.size();
	int sLength = s.size();

	//初始化计数变量
	int count = 0;

	////方法1

	////外层for循环控制饼干
	//for (int i = sLength - 1; i >= 0; i--) {
	//	//内层for循环控制孩子
	//	for (int j = gLength - 1; j >= 0; j--) {
	//		if (s[i] >= g[j]) {
	//			//满足条件之后计数+1
	//			count++;
	//			//下次遍历时从当前位置的前一个开始遍历
	//			gLength=j;
	//			break;
	//		}
	//	}
	//}

	//方法2
	int index = sLength - 1;
	for (int i = gLength - 1; i >= 0; i--) {
		if (index >= 0 && s[index] >= g[i]) {
			count++;
			index--;
		}
	}
	//在方法2中，先遍历了孩子，内圈遍历饼干，每次满足条件，饼干-1，这样更简单。
	//技巧：遍历饼干并没有再另起一个for循环，而是直接采用自减的方式，这是常用的技巧
	return count;
}



//int main()
//{
//	vector<int> g = { 1, 2, 7, 10 };
//	vector<int> s = { 1,3,5,9, };
//	int result = cookiesDistribution(g, s);
//
//
//	system("pause");
//	return 0;
//}