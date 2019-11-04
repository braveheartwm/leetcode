#include <iostream>
#include "simple_calculator.h"

using namespace std;

int main()
{
    SimpleCalculator simple_cal("100+20*(3000-40)+50");
    cout << simple_cal.get_pos_string() << endl;
    cout << simple_cal.get_result() << endl;
    cout << 100+20*(3000-40)+50 << endl;
    // cout << "Hello LeetCode!!!" << endl;
    return 0;
}
