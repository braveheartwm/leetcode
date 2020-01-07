#include <iostream>
#include <vector>
#include "binary_tree.h"

using namespace std;

int main()
{
    vector<char> pre_list = {'A', 'B', 'D', NULL, 'G', NULL, NULL, NULL, 'C', 'E', NULL, NULL, 'F', 'H'};
    BinaryTree<char> tree(pre_list);
    cout << "pre order: ";
    tree.preOrder();
    cout << "mid order: ";
    tree.midOrder();
    cout << "post order: ";
    tree.postOrder();
    vector<char> pre_list1 =  {'A', 'B', 'D', 'G', 'C', 'E', 'F', 'H'};
    vector<char> mid_list1 =  {'D', 'G', 'B', 'A', 'E', 'C', 'H', 'F'};
    BinaryTree<char> tree1(pre_list1, mid_list1);
    cout << "===============" << endl;
    cout << "pre order: ";
    tree1.preOrder();
    cout << "mid order: ";
    tree1.midOrder();
    cout << "post order: ";
    tree1.postOrder();
    return 0;
}
