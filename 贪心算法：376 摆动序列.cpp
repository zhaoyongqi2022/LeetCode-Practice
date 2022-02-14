#include <iostream>
using namespace std;

#include<vector>
#include<algorithm>


int wiggleMaxLength(vector<int>& nums) {
	int preDiff = 0;
	int curDiff = 0;
	int result = 1;

	for (int i = 0; i < nums.size() - 1; i++) {
		curDiff = nums[i + 1] - nums[i];
		if ((preDiff <= 0 && curDiff > 0) || (preDiff >= 0 && curDiff < 0)) {
			result++;
			preDiff = curDiff;
		}
	}
	return result;
}

int main()
{
	vector<int> nums = { 1,17,5,10,13,15,10,5,16,8 };
	int result = wiggleMaxLength(nums);


	system("pause");
	return 0;
}