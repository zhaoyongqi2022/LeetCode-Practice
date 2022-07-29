#include <iostream>
using namespace std;
#include <vector>

vector<int> sortedSquares(vector<int>& nums) {
    /*for (int i = 0; i < nums.size(); i++)
    {
        nums[i] = nums[i] * nums[i];
    }

    for (int i = 0; i < nums.size() - 1; i++)
    {
        int j = i;
        while (nums[j] > nums[j + 1] && j + 1 < nums.size())
        {
            int mid = nums[j + 1];
            nums[j + 1] = nums[j];
            nums[j] = mid;
            j++;
        }
    }
    return nums;*/

    int k = nums.size() - 1;
    vector<int> result(nums.size(), 0);
    for (int i = 0, j = nums.size() - 1; i <= j;)
    {
        if (nums[i] * nums[i] < nums[j] * nums[j])
        {
            result[k--] = nums[j] * nums[j];
            j--;
        }
        else
        {
            result[k--] = nums[i] * nums[i];
            i++;
        }
    }
    return result;
}


