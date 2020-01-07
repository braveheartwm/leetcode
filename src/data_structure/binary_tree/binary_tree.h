#include "binary_node.h"
#include <vector>
using namespace std;

template <class T>
class BinaryTree
{
public:
    BinaryTree(); // 构造空二叉树

    BinaryTree(vector<T> &pre_list); // 以标明空子树的先根序列构造一颗二叉树

    // 以先根和中根序列构造一颗二叉树
    BinaryTree(vector<T> &pre_list, vector<T> &mid_list);

    // 析构函数
    ~BinaryTree(){};

    // 判断是否为空二叉树
    bool is_empty();

    int count(); //二叉树节点个数

    int height(); //二叉树高度

    void preOrder(); //先根遍历二叉树

    void midOrder(); // 中根遍历二叉树

    void postOrder(); // 后根遍历二叉树

    // 查找首次出现值为value的节点
    BinaryNode<T> *search(T value);

    BinaryNode<T> *get_parent();

public:
    BinaryNode<T> *root;

private:
    void preOrder(BinaryNode<T> *node);
    void midOrder(BinaryNode<T> *node);
    void postOrder(BinaryNode<T> *node);
    BinaryNode<T> *create(vector<T> &pre_list, int &i);
    BinaryNode<T> *create(vector<T> &pre_list,
                          vector<T> &mid_list,
                          int pre_start,
                          int mid_start,
                          int n);
};

template <class T>
BinaryTree<T>::BinaryTree()
{
    root = NULL;
}

// 以标明空子树的先根序列构造一颗二叉树
template <class T>
BinaryTree<T>::BinaryTree(vector<T> &pre_list)
{
    int i = 0;
    root = create(pre_list, i);
}

template <class T>
BinaryNode<T> *BinaryTree<T>::create(vector<T> &pre_list, int &i)
{
    BinaryNode<T> *p = NULL;
    if (i < pre_list.size())
    {
        T elem = pre_list[i];
        i++;
        if (elem)
        {
            p = new BinaryNode<T>(elem);
            p->left = create(pre_list, i);
            p->right = create(pre_list, i);
        }
    }
    return p;
}

template <class T>
BinaryTree<T>::BinaryTree(vector<T> &pre_list, vector<T> &mid_list)
{
    // int i = 0;
    root = create(pre_list, mid_list, 0, 0, pre_list.size());
}

template <class T>
BinaryNode<T> *BinaryTree<T>::create(vector<T> &pre_list,
                                     vector<T> &mid_list,
                                     int pre_start,
                                     int mid_start,
                                     int n)
{
    BinaryNode<T> *p = NULL;
    if (n > 0)
    {
        T elem = pre_list[pre_start];
        p = new BinaryNode<T>(elem);
        int i = 0;
        while (i < n && elem != mid_list[mid_start + i])
        {
            i++;
        }
        p->left = create(pre_list,
                         mid_list,
                         pre_start + 1,
                         mid_start,
                         i);
        p->right = create(pre_list,
                          mid_list,
                          pre_start + i + 1,
                          mid_start + i + 1,
                          n - 1 - i);
    }
    return p;
}

template <class T>
void BinaryTree<T>::preOrder()
{
    preOrder(root);
    cout << endl;
}

template <class T>
void BinaryTree<T>::preOrder(BinaryNode<T> *node)
{
    if (!node)
    {
        return;
    }
    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

template <class T>
void BinaryTree<T>::midOrder()
{
    midOrder(root);
    cout << endl;
}

template <class T>
void BinaryTree<T>::midOrder(BinaryNode<T> *node)
{
    if (!node)
        return;
    midOrder(node->left);
    cout << node->data << " ";
    midOrder(node->right);
}

template <class T>
void BinaryTree<T>::postOrder()
{
    postOrder(root);
    cout << endl;
}

template <class T>
void BinaryTree<T>::postOrder(BinaryNode<T> *node)
{
    if (!node)
        return;
    postOrder(node->left);
    postOrder(node->right);
    cout << node->data << " ";
}