#include <iostream>

using namespace std;

template<class T>
struct Node {
    T data;
    Node* next;
    Node() {}
    Node(T x) {
        data = x;
        next = NULL;
    }
};


template<class T>
T second_max(T a[],int n)
{
    // if (n < 2) {
    //     throw "error";
    // }
    // T result = a[0];
    // Node<T> list[n];
    // for (int i = 0;i < n; ++i) {
    //     list[i].data = a[i];
    // }
    // for(int i = 0; i < (n)/2; ++i) {
    //     if(a[2*i] > a[2*i+1]) {
    //         list[2*i].next = new Node<T>(a[2*i+1]);
    //     } else {
    //         list[2*i+1].next = new Node<T>(a[2*i]);
    //         b[i] = a[2*i+1];
    //     }
    // }
    // if (n %2 != 0) {
    //     b[(n+1)/2-1] = a[n-1];
    //     // cout << "aaa"<< endl;
    // }
    // for (int i = 0; i < (n+1)/2; ++i) {
    //     cout << b[i] << " ";
    // }
    // cout << endl;
    // return result;
    T max = a[0],second = a[1];
    if(a[0] < a[1]) {
        max = a[1];
        second = a[0];
    }
    for(int i = 2; i < n; ++i) {
        if (a[i] > max) {
            second = max;
            max = a[i];
        } else if (a[i] > second) {
            second = a[i];
        }
    }
    return second;
}

template <class T>
T second_max_list(T a[], int n) {
    T result = a[0];
    Node<T> list[n];
    for (int i = 0;i < n; ++i) {
        list[i].data = a[i];
    }
}