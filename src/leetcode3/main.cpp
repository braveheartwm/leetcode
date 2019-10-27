#include <iostream>

using namespace std;

/*
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

int lengthOfLongestSubstring(string s) {
    int max = 0,k=0,j;
    // 遍历整个字符串
    for(int i = 0; i < s.size(); ++i) {
        // 判断新来的字符串与之前的是否有相同的，如果相同则跳出本次循环
        for (j = k; j < i; ++j) {
            if (s[i] == s[j]) {
                k = j + 1;
                cout << "=== i=" << i << " j=" << j << " k=" << k<< endl;
                break;
            }
        }
        if (i-k + 1 > max) {
            max = i-k+1;
            cout << "*** i=" << i << " j=" << j << " k=" << k<< endl;
        } 
    }
    return max;
}

int main()
{
    string str = "abcababcd";
    cout << lengthOfLongestSubstring(str) << endl;
    return 0;
}
