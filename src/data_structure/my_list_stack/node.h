template <class T>
struct Node
{
    T data;
    Node *next;
    Node(T x) {
        data = x;
        next = NULL;
    }
    Node(T x, Node *next) {
        data = x;
        this->next = next;
    }
};
