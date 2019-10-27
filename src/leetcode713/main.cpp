#include <iostream>
#include <vector>

using namespace std;
/*
给定一个正整数数组 nums。

找出该数组内乘积小于 k 的连续的子数组的个数。

示例 1:

输入: nums = [10,5,2,6], k = 100
输出: 8
解释: 8个乘积小于100的子数组分别为: [10], [5], [2], [6], [10,5], [5,2], [2,6], [5,2,6]。
需要注意的是 [10,5,2] 并不是乘积小于100的子数组。
说明:

0 < nums.length <= 50000
0 < nums[i] < 1000
0 <= k < 10^6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subarray-product-less-than-k
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
// int numSubarrayProductLessThanK(vector<int> &nums, int k)
// {
//     int result = 0;
//     int n = nums.size();
//     vector<double> double_num(n,0);
//     for (int i = 0; i < n; ++i)
//     {
//         double_num[i] = (double)nums[i];
//         if (double_num[i] < k)
//         {
//             result ++;
//         }
//     }
//     for (int i = 1; i < n; ++ i)
//     {
//         for(int j = 0; j < n - i; ++ j)
//         {
//             double_num[j] = double_num[j] * nums[j+i];
//             if (double_num[j] < k)
//             {
//                 result ++;
//             }
//         }
//     }
//     return result;
// }

int numSubarrayProductLessThanK(vector<int> &nums, int k)
{
    // if (k == 0 || k == 1)
    //     return 0;
    // int l = 0;
    // int prod = 1; //存储nums[l]~nums[r]的累积
    // int res = 0;
    // for (int r = 0; r < nums.size(); r++)
    // {
    //     prod *= nums[r];
    //     while (prod >= k)
    //     {
    //         prod /= nums[l++];
    //     }
    //     res += r - l + 1;
    // }
    // return res;
    if (k<=1) {
        return 0;
    }
    int l = 0;
    int prod = 1;
    int res = 0;
    for (int r = 0; r < nums.size(); ++r) {
        prod *= nums[r];
        while (prod >= k) {
            prod /= nums[l];
            ++l;
        }
        res += r - l + 1;
    }
    return res;
}

int main()
{
    vector<int> nums(10000,1);
    cout << numSubarrayProductLessThanK(nums, 6172) << endl;
    return 0;
}

/*
双指针法，如果一个子串的乘积小于k，那么他的每个子集都小于k，
而一个长度为n的数组，他的所有连续子串数量是1+2+...n，但是
会和前面的重复。 比如例子中[10, 5, 2, 6]，第一个满足条件
的子串是[10]，第二个满足的是[10, 5]，但是第二个数组的子集
[10]和前面的已经重复了，因此我们只需要计算包含最右边的数字的
子串数量，就不会重复了，也就是在计算[10, 5]这个数组的子串是，
只加入[5]和[10, 5]，而不加入[10]，这部分的子串数量刚好是r - l + 1
*/