#include <iostream>

using namespace std;

template <class T>
class MyStack{
public:
    MyStack(int size = 64);
    ~MyStack();
    bool is_empty();
    void push(T x);
    T pop();
    T get();
private:
    int size;
    int len;
    T *element;
};

template <class T>
T MyStack<T>::get() {
    if (len == 0) {
        throw "empty stack";
    }
    return element[len - 1];
}

template <class T>
T MyStack<T>::pop() {
    if (len == 0) {
        throw "empty stack";
    }
    -- len;
    return element[len];
}

template <class T>
void MyStack<T>::push(T x) {
    if (len < size) {
        element[len] = x;
        ++ len;
    } else {
        size = size * 2;
        T *tmp = new T[size];
        for (int i = 0; i < len; ++ i) {
            tmp[i] = element[i];
        }
        tmp[len] = x;
        ++ len;
        element = tmp;
    }
}

template <class T>
MyStack<T>::MyStack(int size) {
    this->size = size > 64 ? size : 64;
    element = new T[this->size];
    len = 0;
}

template <class T>
MyStack<T>::~MyStack() {
    delete[] element;
}

template <class T>
bool MyStack<T>::is_empty() {
    return (len == 0);
}

int main()
{
    MyStack<int> *ms = new MyStack<int>();
    ms->push(1);
    ms->push(2);
    for(int i = 0; i < 65; ++i) {
        ms->push(i);
    }
    while(!ms->is_empty()) {
        cout << " " << ms->pop();
    }
    cout << endl;
    return 0;
}
