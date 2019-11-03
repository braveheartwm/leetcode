#include "quick_sort.hpp"

int change_sort(vector<int> &v, int start, int end)
{
    int i = start, j = end;
    int x = v[i];
    while(i < j)
    {
        while(x < v[j] && j > i)
        {
            j--;
        }
        if(j > i) 
        {
            v[i] = v[j];
            i ++;
        }
        while(x > v[i] && i < j)
        {
            i ++;
        }
        if (i < j)
        {
            v[j] = v[i];
            j --;
        }
    }
    v[i] = x;
    return i;
}

void quick_sort(vector<int> &v, int l, int r)
{
    if (l < r)
    {
        int i = change_sort(v, l, r);
        quick_sort(v, l, i-1);
        quick_sort(v, i+1, r);
    }
}