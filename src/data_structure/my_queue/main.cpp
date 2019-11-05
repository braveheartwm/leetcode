#include <iostream>

using namespace std;

template <class T>
class MyQueue {
public:
    MyQueue(int size = 4);
    ~MyQueue();
    bool is_empty();
    void push(T x);
    T pop();
private:
    int rear;
    int front;
    int size;
    T *element;
};

template <class T>
MyQueue<T>::MyQueue(int size) {
    this->size = size > 4 ? size : 4;
    element = new T[this->size];
    rear = front = 0;
}

template <class T>
MyQueue<T>::~MyQueue() {
    delete[] element;
}

template<class T>
void MyQueue<T>::push(T x) {
    if ((rear+1) % size == front) {
        T *tmp = element;
        element = new T[size*2];
        int i = front,j=0;
        while (i != rear)
        {
            element[j] = tmp[i];
            i = (i+1) % size;
            ++ j;
        }
        front = 0;
        rear = j;
        size = size * 2;
    }

    element[rear] = x;
    rear = (rear + 1) % size;
}

template<class T>
T MyQueue<T>::pop() {
    if(!is_empty()) {
        T ans = element[front];
        front = (front + 1) % size;
        return ans;
    } else {
        throw "empty queue";
    }
}

template <class T>
bool MyQueue<T>::is_empty() {
    return rear == front;
}

int main()
{
    MyQueue<int> my_queue;
    for(int i = 0; i < 5; ++i) {
        my_queue.push(i);
    }
    my_queue.pop();
    my_queue.push(8);
    while (!my_queue.is_empty()) {
        cout << my_queue.pop() << " ";
    }
    cout << endl;
    return 0;
}
