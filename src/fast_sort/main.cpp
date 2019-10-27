#include <iostream>
#include <vector>
#include <stdlib.h>
#include <ctime>
#include "quick_sort.hpp"

using namespace std;

vector<int> fast_sort(vector<int> v);
vector<int> normal_sort(vector<int> v);

int main()
{
    clock_t start_time, end_time0, end_time1;
    vector<int> v;
    for (int i = 0; i < 15; ++i)
    {
        int a = rand() % 9;
        v.push_back(a);
    }

    cout << "v:";
    for (int l = 0; l < v.size(); ++l)
    {
        cout << v[l] << " ";
    }
    cout << endl;

    start_time = clock();
    auto fast_v = fast_sort(v);
    end_time0 = clock();
    auto normal_v = normal_sort(v);
    end_time1 = clock();

    cout << "fast sorted:";
    for (int l = 0; l < fast_v.size(); ++l)
    {
        cout << fast_v[l] << " ";
    }
    cout << endl;

    cout << "normal sorted:";
    for (int l = 0; l < normal_v.size(); ++l)
    {
        cout << normal_v[l] << " ";
    }
    cout << endl;

    cout << "The fast sort run time is: " << \
        (double)(end_time0 - start_time) / CLOCKS_PER_SEC << "s" << endl;
    cout << "The normal sort run time is: " << \
        (double)(end_time1 - end_time0) / CLOCKS_PER_SEC << "s" << endl;
    cout << "====================" << endl;
    start_time = clock();
    quick_sort(v, 0, v.size()-1);
    end_time0 = clock();
    cout << "The quick sort run time is: " << \
        (double)(end_time0 - start_time) / CLOCKS_PER_SEC << "s" << endl;
    cout << "v:";
    for (int l = 0; l < v.size(); ++l)
    {
        cout << v[l] << " ";
    }
    cout << endl;
    return 0;
}

vector<int> fast_sort(vector<int> v)
{
    if (v.empty())
    {
        return v;
    }
    else if (v.size() == 1)
    {
        return v;
    }
    else if (v.size() == 2)
    {
        if (v[0] > v[1])
        {
            swap(v[0], v[1]);
        }
        return v;
    }

    int i = 0;
    int last_index = v.size() - 1;
    int next_index = i + 1;

    while (next_index < last_index)
    {
        while (v[i] >= v[next_index] && next_index < v.size())
        {
            ++next_index;
        }
        while (v[i] < v[last_index] && last_index > 0)
        {
            --last_index;
        }
        if (last_index > next_index)
        {
            swap(v[last_index], v[next_index]);
        }
    }
    vector<int> v1;
    vector<int> v2;
    if (next_index == v.size())
    {
        v1.insert(v1.end(), v.begin() + 1, v.end());
        v2.insert(v2.end(), v.begin(), v.begin() + 1);
    }
    else
    {
        v1.insert(v1.end(), v.begin(), v.begin() + last_index + 1);
        v2.insert(v2.end(), v.begin() + last_index + 1, v.end());
    }

    v1 = fast_sort(v1);
    v2 = fast_sort(v2);
    for (int i = 0; i < v2.size(); ++i)
    {
        v1.push_back(v2[i]);
    }
    return v1;
}

vector<int> normal_sort(vector<int> v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        for (int j = 0; j < v.size() - 1 - i; ++j)
        {
            if (v[j] > v[j + 1])
            {
                swap(v[j], v[j + 1]);
            }
        }
    }
    return v;
}