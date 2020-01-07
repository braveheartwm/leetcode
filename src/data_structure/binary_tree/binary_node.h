#include <iostream>

template <class T>
class BinaryNode
{
private:
public:
    T data;
    BinaryNode* left;
    BinaryNode* right;
    BinaryNode(T data,
        BinaryNode<T>* left = NULL,
        BinaryNode<T>* right = NULL);
    ~BinaryNode();
};
template <class T>
BinaryNode<T>::BinaryNode(
    T data,
    BinaryNode<T>* left,
    BinaryNode<T>* right)
{
    this->data = data;
    this->left = left;
    this->right = right;
}

template<class T>
BinaryNode<T>::~BinaryNode()
{
}
