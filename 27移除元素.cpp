#include <iostream>
using namespace std;
#include <vector>

int removeElement(vector<int>& nums, int val) {
    //int counter = 0;
    int size = nums.size();
    for (int i = 0; i < size; i++)
    {
        //counter++;
        if (nums[i] == val)
        {
            //counter--;
            for (int j = i; j < size - 1; j++)
            {
                nums[j] = nums[j + 1];
            }
            size--;//Ԫ�ظ���֮��size��ȥһ
            i--;//ÿ��Ԫ������ǰ��һλ
        }
    }
    //return counter;
    return size;

    //˫ָ�뷨
    int slowIndex = 0;
    for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++)
    {
        if (nums[fastIndex] != val)
        {
            nums[slowIndex] = nums[fastIndex];
            slowIndex++;
        }
    }
    return slowIndex;
}


