#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

vector<int> twoSum(vector<int> &nums, int target);
int search_vec(vector<int> &nums, vector<int> &index, int l, int r);
void quik_sort(vector<int> &nums, vector<int> &index, int l, int r);
void print_vec(vector<int> &vec);

int main()
{
    vector<int> nums = {-3, -3};
    int target = -6;
    vector<int> index;
    vector<int> result = twoSum(nums, -6);
    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}

vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> result;
    vector<int> index;
    for (int i = 0; i < nums.size(); ++i)
    {
        index.push_back(i);
    }
    quik_sort(nums, index, 0, nums.size()-1);
    int i = 0;
    int j = nums.size() - 1;
    while (nums[i] + nums[j] != target)
    {
        // cout << "num" << endl;
        if (nums[i] + nums[j] > target)
        {
            j--;
        }
        else if (nums[i] + nums[j] < target)
        {
            i++;
        }
    }
    result.push_back(index[i]);
    result.push_back(index[j]);
    return result;
}
void quik_sort(vector<int> &nums, vector<int> &index, int l, int r)
{
    // cout << "l=" << l << " r=" << r << endl;
    // if (r <= l)
    //     return;
    if (l < r)
    {
        int q = search_vec(nums, index, l, r);
        // cout << "q = " << q << endl;
        quik_sort(nums, index, l, q - 1);
        quik_sort(nums, index, q + 1, r);
    }
}
int search_vec(vector<int> &nums, vector<int> &index, int l, int r)
{
    int x = nums[l];
    int x_index = index[l];
    int i = l;
    int j = r;
    while (i < j)
    {
        while (nums[j] >= x && j > i)
        {
            j--;
            // cout << "j=" << j;
        }
        if (j > i)
        {
            nums[i] = nums[j];
            index[i] = index[j];
        }
        while (nums[i] <= x && i < j)
        {
            i++;
        }
        if (j > i)
        {
            nums[j] = nums[i];
            index[j] = index[i];
        }
    }
    nums[i] = x;
    index[i] = x_index;
    return i;
}

void print_vec(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}