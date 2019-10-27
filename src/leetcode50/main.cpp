#include <iostream>
#include <limits.h>

using namespace std;

/**
实现 pow(x, n) ，即计算 x 的 n 次幂函数。

示例 1:

输入: 2.00000, 10
输出: 1024.00000
示例 2:

输入: 2.10000, 3
输出: 9.26100
示例 3:

输入: 2.00000, -2
输出: 0.25000
解释: 2-2 = 1/22 = 1/4 = 0.25
说明:

-100.0 < x < 100.0
n 是 32 位有符号整数，其数值范围是 [−231, 231 − 1] 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/powx-n
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
double myPow(double x, int n)
{
    double res = 0.0;
    bool is_negtive = false;
    bool is_int_min = false;
    if (n < 0)
    {
        is_negtive = true;
    }
    if (n == INT_MIN)
    {
        is_int_min = true;
        n = n + 1;
    }
    n = abs(n);
    if (n == 1)
    {
        res = x;
    }
    else if (n == 0)
    {
        res = 1.0;
    }
    else if (n % 2 == 0)
    {
        double a = myPow(x, n / 2);
        res = a * a;
    }
    else
    {
        double a = myPow(x, n / 2);
        res = a * a * x;
    }
    if (is_int_min)
    {
        res *= x;
    }
    if (is_negtive)
    {
        res = 1.0 / res;
    }
    return res;
}

int main()
{
    cout << myPow(5, -5) << endl;
    return 0;
}
