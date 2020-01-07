#include <iostream>
#include <vector>
#include<limits.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        }
        if (prices.size() == 2) {
            return prices[1]-prices[0] > 0 ? prices[1]-prices[0]: 0;
        }
        vector<int> diff(prices.size()-1);
        // cout << diff.size() << endl;
        for(int i = 0; i < diff.size(); ++ i) {
            diff[i] = prices[i+1] - prices[i];
            cout << diff[i] << " ";
        }
        cout << endl;
        int res = INT_MIN, sum = 0;
        for(int i = 0; i < diff.size(); ++ i) {
            sum = max(sum+diff[i], 0);
            res = max(res, sum);
            cout << i << " " << sum << " " << res << endl;
        }
        return res > 0 ? res : 0;
    }
};

int main()
{
    // cout << "Hello LeetCode!!!" << endl;
    vector<int> prices = {1, 4, 2};
    Solution s;
    cout << s.maxProfit(prices) << endl;
    return 0;
}
