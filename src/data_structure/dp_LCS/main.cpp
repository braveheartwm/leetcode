#include <iostream>
#include <vector>

using namespace std;

string find_LCS(string s1, string s2)
{
    string res;
    int n = s1.size();
    int m = s2.size();
    vector<int> tmp(m+1, 0);
    vector<vector<int>> max_len(n+1, tmp);
    vector<char> tmp_char(m+1, ' ');
    vector<vector<char>> label(n+1,tmp_char);
    for(int i = 0; i < n+1; ++ i) {
        max_len[i][0] = 0;
    }

    for (int j = 0; j < m+1; ++ j) {
        max_len[0][j] = 0;
    }

    for(int i = 1; i < n+1; ++i) {
        for (int j = 1; j < m+1; ++j) {
            if(s1[i-1] == s2[j-1]) {
                max_len[i][j] = max_len[i-1][j-1] + 1;
                label[i][j] = 'M';
            } else if (max_len[i-1][j] >= max_len[i][j-1]) {
                max_len[i][j] = max_len[i-1][j];
                label[i][j] = 'U';
            } else {
                max_len[i][j] = max_len[i][j-1];
                label[i][j] = 'R';
            }
        }
    }
    int max = 0; 
    int i_x = 0,i_y = 0;
    for (int i = 1; i < n+1; ++ i) {
        for (int j = 1; j < m+1; ++ j) {
            if(max_len[i][j] > max) {
                max = max_len[i][j];
                i_x = i;
                i_y = j;
            }
        }
    }

    while(i_x > 0 && i_y > 0) {
        if (label[i_x][i_y] == 'M') {
            res.insert(res.begin(),s1[i_x-1]);
            i_x --;
            i_y --;
        } else if (label[i_x][i_y] == 'U') {
            i_x --;
        } else {
            i_y --;
        }
    }
    // for (auto a:max_len) {
    //     for (auto b:a) {
    //         cout << b << " ";
    //     }
    //     cout << endl;
    // }
    // for (auto a:label) {
    //     for (auto b:a) {
    //         cout << b << " ";
    //     }
    //     cout << endl;
    // }
    return res;
}

int main()
{
    string s1("SDBDDD");
    string s2("DDADD");
    cout << "s1=" << s1 << endl;
    cout << "s2=" << s2 << endl;
    cout << "The answer is:" << find_LCS(s1, s2) << endl;
    return 0;
}
