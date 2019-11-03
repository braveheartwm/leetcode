#include <iostream>

using namespace std;

template <class T>
class ChainList {
    class ListNode {
      public:
        T value;
        ListNode *next;
        ListNode() {
            next = NULL;
        }
        ListNode(T data, ListNode* next=NULL) {
            this->data = data;
            this->next = next;
        }
    };
  private:
    ListNode* heading=NULL;
  public:
    ChainList();
    ChainList(T value[], int n);
    ~ChainList();
    bool isEmpty();
    int length();
    T get(int i);
    bool set(int i, T x);
    template <class Ty>
    friend ostream &operator<<(ostream &out, ChainList<Ty>&list);
    bool insert(int i, T x);
    bool remove(int i, T &old_x);
    void clear();
    void print();
    int get_size();
};


int main()
{
    cout << "Hello LeetCode!!!" << endl;
    return 0;
}
