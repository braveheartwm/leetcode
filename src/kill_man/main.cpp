#include <iostream>
#include <cmath>
#include "second_max.h"

using namespace std;

template <class T>
struct ListNode {
    T data;
    ListNode* next;
    ListNode(T data) {
        this->data = data;
        this->next = NULL;
    }
    template <class Ty>
    friend ostream& operator<<(ostream& out, ListNode<Ty>*list);
};

template <class T>
ostream& operator<<(ostream& out, ListNode<T>*list) {
    out << "[";
    ListNode<T> *tmp = list;

    while(tmp) {
        out << tmp->data << " ";
        tmp = tmp->next;
    }
    out << "]";
    return out;
}
template <class T>
void killMan(ListNode<T> *list, int start, int d) {
    if(!list) {
        return;
    }
    int index = 0;
    int counter = 0;
    int len = 0;
    ListNode<int> *head_node = NULL;
    ListNode<int> **ptr_node = &head_node;
    ListNode<T> *tmp = list;
    while(tmp) {
        (*ptr_node) = new ListNode<int>(index);
        index ++;
        tmp = tmp->next;
        ptr_node = &((*ptr_node)->next);
        ++len;
    }
    
    index = 0;
    ListNode<int> *tmp_new = head_node;
    while(index < start) {
        tmp_new = tmp_new->next;
        if(tmp_new == NULL) {
            tmp_new = head_node;
        }
        ++index;
    }
    
    while(len > 1) {
        if (tmp_new->data != -1) {
            ++counter;
        }
        if(counter == d) {
            --len;
            tmp_new->data = -1;
            counter = 0;
        }
        tmp_new = tmp_new->next;
        if(tmp_new == NULL) {
            tmp_new = head_node;
        }
    }
    tmp = list;
    tmp_new = head_node;
    while(tmp_new->data == -1) {
        tmp = tmp->next;
        tmp_new = tmp_new->next;
    }
    cout <<head_node <<  "answer is:" << tmp->data << endl;
    // return tmp->data;
}

template <class T>
void killMan1(ListNode<T> *list, const int start, const int d) {
    if(!list) {
        return;
    }
    ListNode<T> *start_node = NULL;
    ListNode<T> *head_node = list;
    int len = 0;
    int index = 0;
    while(list) {
        if (!list->next) {
            ++len;
            if (index < start) {
                ++index;
            } else if (index == start && !start_node) {
                start_node = list;
            }
            list->next = head_node;
            // list = head_node;
            break;
        }
        ++len;
        if (index < start) {
            ++ index;
        } else if(index == start && !start_node) {
            start_node = list;
        }
        list = list->next;
    }
    while(index <= start && !start_node) {
        if (index == start && !start_node) {
            start_node = list->next;
        }
        list = list->next;
        ++ index;
    }
    cout << "len:" << len << " start_node:" << start_node->data << endl;
    int counter = 0;
    while(len > 1) {
        ++counter;
        if(counter == d-1) {
            ListNode<T> *p = start_node->next;
            start_node->next = p->next;
            cout << "delete:" << p->data << endl;
            delete p;
            --len;
            counter = 0;
        }
        start_node = start_node->next;
        // cout << len << endl;
    }
    cout << start_node->data<< endl;
}


int main()
{
    // ListNode<char>* head_node = new ListNode<char>('A');
    // ListNode<char>* tmp1,*tmp2;
    // tmp1 = head_node->next;
    // tmp2 = head_node;
    // for(int i = 1; i < 6; ++i) {
    //     tmp1 = new ListNode<char>(i+'A');
    //     tmp2->next = tmp1;
    //     tmp2 = tmp1;
    // }
    // tmp1 = head_node;
    // while(tmp1) {
    //     tmp1 = tmp1->next; 
    // }
    // cout << head_node << endl;
    // killMan(head_node,1,3);
    // killMan1(head_node,1,3);
    int a[8];
    for (int i = 0; i < 8; ++i) {
        a[i] = rand()%99;
        cout << a[i] << " ";
    }
    cout << endl;
    cout << second_max(a,8) << endl;
    return 0;
}
