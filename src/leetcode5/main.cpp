#include <iostream>
#include <vector>
using namespace std;

/*
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-palindromic-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <=1) {
            return s;
        }
        string res;
        int n = s.size();
        vector<char> vec;
        vec.push_back('#');
        for (int i = 0; i < n; ++i) {
            vec.push_back(s[i]);
            vec.push_back('#');
        }
        int m = vec.size();
        int start = 0, end = 0;
        int head = 0, tail = 0;
        int max = 0;
        for (int i = 0; i < m-1; ++ i) {
            start = i;
            end = i;
            while((start >=0) && (end <= m-1)&&(vec[start] == vec[end]) ) {
                if(end - start+1 > max) {
                    max = (end-start)+1;
                    head = start;
                    tail = end;
                } 
                --start;
                ++ end;
            }
        }
        head= (head)/2;
        tail=(tail-1)/2;
        return s.substr(head,tail-head+1);
    }
};

int main()
{
    Solution s;
    cout << s.longestPalindrome("babad") << endl;
    return 0;
}
