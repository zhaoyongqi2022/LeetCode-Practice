#include <iostream>
using namespace std;
#include <vector>

int binarySearch(vector<int>& nums, int target)
{
	// [left, right]
	int left = 0;
	int right = nums.size() - 1;

	while (left <= right)
	{
		int mid = (right + left) / 2;
		if (nums[mid] == target)
		{
			return mid;
		}
		else if (nums[mid] > target)
		{
			right = mid - 1;
		}
		else if (nums[mid] < target)
		{
			left = mid + 1;
		}
	}
	return -1;

	// [left, right)
	int left = 0;
	int right = nums.size();
	while (left < right)
	{
		int mid = (left + right) / 2;
		if (nums[mid] == target)
		{
			return mid;
		}
		else if (nums[mid] > target)
		{
			right = mid;
		}
		else if (nums[mid] < target)
		{
			left = mid + 1;
		}
	}
	return -1;
}
