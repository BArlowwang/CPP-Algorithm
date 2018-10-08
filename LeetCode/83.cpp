/**
* LeetCode The 26th problem :remove-duplicates-from-sorted-list
* Auth:Barlowwang
* Date:2018-10-08
**/ 
#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode *deleteDuplicates(ListNode *head)
{
    ListNode *prev = head->next, *current = head;
    while (prev != NULL)
    {
        if (prev->val == current->val)
        {
            current->next = prev->next;
            delete prev;
            prev = current->next;
        }
        else
        {
            current = current->next;
            prev = prev->next;
        }
    }
    return head;
}
int main()
{
    int t, n;
    cin >> t;
    cin >> n;
    ListNode *head = new ListNode(n);
    ListNode *p = head;
    for (int i = 0; i < t - 1; i++)
    {
        cin >> n;
        ListNode *temp = new ListNode(n);
        p->next = temp;
        p = temp;
    }
    head = deleteDuplicates(head);
    while (head != NULL)
    {
        cout << head->val << "  ";
        p = head;
        head = head->next;
        delete p;
    }
    cout << endl;
    system("pause");
}

