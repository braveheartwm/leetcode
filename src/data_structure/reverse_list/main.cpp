#include <iostream>

using namespace std;

template <class T>
struct Node
{
    T data;
    Node* next;
    Node(){}
    Node(T x) {
        data = x;
        next = NULL;
    }
    Node(T x, Node *next) {
        this->data = x;
        this->next = next;
    }
};

template <class T>
Node<T>* reverse_list(Node<T> *head) {
    Node<T> *pre_node = NULL, *p = head;
    while (p != NULL) {
        Node<T> *tmp = p->next;
        p->next = pre_node;
        pre_node = p;
        p = tmp;
    }
    return pre_node;
}

int main()
{
    Node<int> *head = NULL; //记录list头
    Node<int> **p = NULL;
    for (int i = 0; i < 5; ++ i) {
        if (head == NULL) {
            head = new Node<int>(i);
            p = &(head->next);
        } else {
            *p = new Node<int>(i);
            p = &((*p)->next);
        }
    }
    head = reverse_list<int>(head);
    while(head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
    return 0;
}
