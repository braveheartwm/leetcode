#include "simple_calculator.h"

SimpleCalculator::SimpleCalculator() {}

SimpleCalculator::SimpleCalculator(string s) {
    mid_string = s;
    change_equation2post();
    calculate_result();
}

void SimpleCalculator::update_equation(string s) {
    mid_string = s;
    change_equation2post();
    calculate_result();
}

SimpleCalculator::~SimpleCalculator(){

}

void SimpleCalculator::change_equation2post() {
    int n = mid_string.size();
    stack<char> opt_stack;
    bool front_char_is_number = false;
    auto it = mid_string.begin();
    while (it != mid_string.end()) {
        // cout << *it << " ";
        if ((*it) <= '9' && (*it) >= '0') {
            if (!front_char_is_number && it != mid_string.begin()) {
                post_string.push_back(' ');
            }
            post_string.push_back(*it);
            front_char_is_number = true;
        } else if ((*it) == '-' || (*it) == '+') {
            while (!opt_stack.empty() && opt_stack.top() != '(') {
                post_string.push_back(' ');
                post_string.push_back(opt_stack.top());
                opt_stack.pop();
            }
            opt_stack.push((*it));
            front_char_is_number = false;
        } else if ((*it) == '*' || (*it) == '/') {
            while (!opt_stack.empty() && opt_stack.top() != '(' 
                    && (opt_stack.top() == '*' || opt_stack.top() == '/')) {
                post_string.push_back(' ');
                post_string.push_back(opt_stack.top());
                opt_stack.pop();
            }
            opt_stack.push(*it);
            front_char_is_number = false;
        } else if ((*it) == '(') {
            opt_stack.push(*it);
            front_char_is_number = false;
        } else if ((*it) == ')') {
            while(!opt_stack.empty() && opt_stack.top() != '(') {
                post_string.push_back(' ');
                post_string.push_back(opt_stack.top());
                opt_stack.pop();
            }
            opt_stack.pop();
            front_char_is_number = false;
        }
        // cout << *it << " " << "====";
        ++it;
        // cout << post_string << endl;
    }
    while (!opt_stack.empty()) {
        post_string.push_back(' ');
        post_string.push_back(opt_stack.top());
        opt_stack.pop();
    }
}

string SimpleCalculator::get_pos_string() {
    return post_string;
}

void SimpleCalculator::calculate_result() {
    stack<int> ans;
    auto it = post_string.begin();
    while (it != post_string.end()) {
        // cout << *it << endl;
        if ((*it) <= '9' && (*it) >= '0') {
            int number = 0;
            while ((*it) <= '9' && (*it) >= '0') {
                number = number*10 + (*it) - '0';
                ++it;
            }
            ans.push(number);
            // cout << number << endl;
        } else if ((*it) == '+' || (*it) == '-' || (*it) == '*' || (*it) == '/') {
            int b = ans.top();
            ans.pop();
            int a = ans.top();
            ans.pop();
            // cout << "a="<< a << " it=" << *it << " b=" << b << endl;
            if (*it == '+') {
                ans.push(a+b);
                // cout << "push " << a+b << endl;
            }
            if (*it == '-') {
                ans.push(a-b);
                // cout << "push " << a-b << endl;
            }
            if (*it == '*') {
                ans.push(a*b);
                // cout << "push " << a*b << endl;
            }
            if (*it == '/') {
                ans.push(a/b);
                // cout << "push " << a/b << endl;
            }
        }
        ++it;
    }
    result = ans.top();
}

int SimpleCalculator::get_result() {
    return result;
}