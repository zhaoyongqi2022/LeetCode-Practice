#include <iostream>
using namespace std;

#include<vector>
#include<algorithm>

//���⻹����ʹ�ö�̬�滮�㷨

int wiggleMaxLength(vector<int>& nums) {
	int preDiff = 0;
	int curDiff = 0;
	int result = 1;

	for (int i = 0; i < nums.size() - 1; i++) {
		curDiff = nums[i + 1] - nums[i];//��������ʹ����i+1,���forѭ����i��ൽnums.size()-1������ͻ����

		//����preDiff���еȺŵģ���Ϊ��ֻ������Ԫ��ʱ������e.g.,[2,5]
		if ((preDiff <= 0 && curDiff > 0) || (preDiff >= 0 && curDiff < 0)) {
			result++;
			preDiff = curDiff;// ��һ���ܹؼ���preDiff����ò��ϸ���
		}
	}
	return result;
}

//��������һ��Ҫע��߽磬ֻ������Ԫ�ص���[2,5]�Ǻܺõ�����

//int main()
//{
//	vector<int> nums = { 1,17,5,10,13,15,10,5,16,8 };
//	int result = wiggleMaxLength(nums);
//
//
//	system("pause");
//	return 0;
//}