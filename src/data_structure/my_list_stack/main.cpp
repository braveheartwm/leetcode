#include <iostream>
#include "node.h"

using namespace std;

template <class T>
class MyListStack{
public:
    MyListStack();
    ~MyListStack();
    bool is_empty();
    void push(T x);
    T pop();
    T get();
private:
    int size;
    int len;
    Node<T> *head;
};

template <class T>
T MyListStack<T>::get() {
    if (head == NULL) {
        throw "empty stack";
    }
    return head->data;
}

template <class T>
T MyListStack<T>::pop() {
    if (head == NULL) {
        throw "empty stack";
    }
    T tmp = head->data;
    Node<T> *p = head;
    head = head->next;
    delete p;
    return tmp;
}

template <class T>
void MyListStack<T>::push(T x) {
    head = new Node<T>(x, head);
}

template <class T>
MyListStack<T>::MyListStack() {
    head = NULL;
}

template <class T>
MyListStack<T>::~MyListStack() {
    Node<T> *p = head, q;
    if (p != NULL) {
        q = p;
        p = p->next;
        delete q;
    }
}

template <class T>
bool MyListStack<T>::is_empty() {
    return (head == NULL);
}

int main()
{
    MyListStack<int> *ms = new MyListStack<int>();
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
