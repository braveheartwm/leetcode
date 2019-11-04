#include <iostream>
#include <string>
#include <stack>

using namespace std;

class SimpleCalculator {
public:
    SimpleCalculator();
    SimpleCalculator(string s);
    ~SimpleCalculator();
    void update_equation(string s);
    int get_result();
    string get_pos_string();
private:
    void change_equation2post();
    void calculate_result();
    int result = 0;
    string post_string;
    string mid_string;
};