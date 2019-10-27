/**
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int getNumber(ListNode *l)
{
    int result = 0;
    if (l)
    {
        result = l->val;
    }
    return result;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    int overflag = 0;
    ListNode *result = NULL;
    ListNode **tmp = &result;
    while (l1 || l2 || overflag)
    {
        int a = getNumber(l1);
        int b = getNumber(l2);
        *tmp = new ListNode((a + b + overflag) % 10);
        overflag = (a + b + overflag) / 10;
        tmp = &((*tmp)->next);
        if (l1)
            l1 = l1->next;
        if (l2)
            l2 = l2->next;
    }
    return result;
}

ListNode *changeNumberToList(int n)
{
    ListNode *head_node = NULL;
    ListNode **tmp = NULL;
    int a = n % 10;
    head_node = new ListNode(a);
    head_node->next = NULL;
    cout << "add " << a << endl;
    tmp = &(head_node->next);
    n = (n - a) / 10;
    while (n > 0)
    {
        a = n % 10;
        n = (n - a) / 10;
        *tmp = new ListNode(a);
        (*tmp)->next = NULL;
        cout << "add:" << a << endl;
        tmp = &((*tmp)->next);
        // tmp->next = NULL;
    }
    return head_node;
}

void print_list_node(ListNode *l)
{
    ListNode *tmp = l;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

int main()
{
    ListNode *p = changeNumberToList(243);
    ListNode *p2 = changeNumberToList(564);
    ListNode *result = addTwoNumbers(p, p2);
    print_list_node(result);
    return 0;
}
