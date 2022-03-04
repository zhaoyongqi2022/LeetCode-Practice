#include <iostream>
using namespace std;

#include<vector>
#include<algorithm>

//此题还可以使用动态规划算法

int wiggleMaxLength(vector<int>& nums) {
	int preDiff = 0;
	int curDiff = 0;
	int result = 1;

	for (int i = 0; i < nums.size() - 1; i++) {
		curDiff = nums[i + 1] - nums[i];//由于这里使用了i+1,因此for循环中i最多到nums.size()-1，否则就会溢出

		//这里preDiff是有等号的，因为在只有两个元素时会有用e.g.,[2,5]
		if ((preDiff <= 0 && curDiff > 0) || (preDiff >= 0 && curDiff < 0)) {
			result++;
			preDiff = curDiff;// 这一步很关键，preDiff必须得不断更新
		}
	}
	return result;
}

//做此类题一定要注意边界，只有两个元素的如[2,5]是很好的例子

//int main()
//{
//	vector<int> nums = { 1,17,5,10,13,15,10,5,16,8 };
//	int result = wiggleMaxLength(nums);
//
//
//	system("pause");
//	return 0;
//}