#include <iostream>
using namespace std;

#include<vector>
#include<algorithm>

int maxSubArray(vector<int>& nums) {
	int result = INT_MIN;
	int sum = 0;
	for (int i = 0; i < nums.size(); i++) {
		sum += nums[i];
		if (sum > result) result = sum;//ȷ������������к͵���ֹλ��
		if (sum < 0) sum = 0;//ȷ������������к͵���ʼλ��
	}
	return result;
}


//int main()
//{
//
//
//	system("pause");
//	return 0;
//}