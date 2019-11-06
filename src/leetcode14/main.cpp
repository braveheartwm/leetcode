#include <iostream>
#include <vector>

using namespace std;

/*
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"
示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
说明:

所有输入只包含小写字母 a-z 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-common-prefix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        // 如果字符串数组为空，则返回空
        if (strs.size() < 1) {
            return res;
        } else if (strs.size() == 1) {
            return strs[0]; // 如果只有一个字符串，则返回该字符串。
        }
        int k = 0; // 标记比较每个字符串中的位置
        char element;
        if(strs[0] == "")
        {
            return res; // 如果第一个字符串为空字符串，则返回空
        } else {
            element = strs[0][0];// 否则将比较元素置成第一个字符串的第一个字符
        }
        int i = 1;
        while( k < strs[0].size() && i < strs.size()) { // 从头到位比较第一个字符串的每个字符
            if (element != strs[i][k]) { // 如果其他字符串中的第k个元素与比较字符不一致，则跳出循环
                break;
            }
            if (i == strs.size() - 1) { // 如果i已经为最后一个字符串，则表示该k个字符都相等
                ++ k; // 进行下一个比较
                i = 1;// 从头开始比较
                res.push_back(element);//将该字符push到相等字符中
                element = strs[0][k];//下一个待比较字符。
                continue;
            }
            ++ i; // 下一个比较字符串
        }
        return res;
    }
};


int main()
{
    Solution s;
    vector<string> strs = {"aa","aa"};
    cout << s.longestCommonPrefix(strs) << endl;
    return 0;
}
