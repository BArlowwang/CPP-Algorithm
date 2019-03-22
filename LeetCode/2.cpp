/**
* LeetCode The 2nd problem :add-two-numbers
* Auth:Barlowwang
* Date:2018-12-*
**/

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    if (l1 == NULL && l2 == NULL)
    {
        // cout << "NULL";
        return NULL;
    }
    if (l1 == NULL)
    {
        // cout << "l1";
        return l2;
    }
    if (l2 == NULL)
    {
        //   cout << "l2";
        return l1;
    }
    ListNode *head = new ListNode(0);
    ListNode *p = head;
    head->val = (l1->val + l2->val) % 10;
    bool carry = ((l1->val + l2->val) / 10 == 1);
    l1 = l1->next;
    l2 = l2->next;
    while (l1 != NULL && l2 != NULL)
    {
        int tmp = l1->val + l2->val;
        tmp = carry ? tmp + 1 : tmp;
        carry = (tmp / 10 == 1);
        p->next = new ListNode(tmp % 10);
        p = p->next;
        p->next = NULL;
        l1 = l1->next;
        l2 = l2->next;
    }
    if (l1 == NULL)
    {
        while (l2 != NULL)
        {
            int tmp = l2->val;
            tmp = carry ? tmp + 1 : tmp;
            carry = (tmp / 10 == 1);
            p->next = new ListNode(tmp % 10);
            p = p->next;
            p->next = NULL;
            l2 = l2->next;
        }
    }
    if (l2 == NULL)
    {
        while (l1 != NULL)
        {
            int tmp = l1->val;
            tmp = carry ? tmp + 1 : tmp;
            carry = (tmp / 10 == 1);
            p->next = new ListNode(tmp % 10);
            p = p->next;
            p->next = NULL;
            l1 = l1->next;
        }
    }
    if (carry)
    {
        p->next = new ListNode(1);
        p->next->next = NULL;
    }
    return head;
}