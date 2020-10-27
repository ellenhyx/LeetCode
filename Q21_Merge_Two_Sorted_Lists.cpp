#include <cstddef>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        // return iterative(l1,l2);
        return recursive(l1, l2);
    }

private:
    ListNode* iterative(ListNode *l1, ListNode *l2)
    {
        if (!l1)
            return l2;
        else if (!l2)
            return l1;
        ListNode *head = new ListNode();
        ListNode *res = head;
        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                res->next = new ListNode(l1->val);
                l1 = l1->next;
                res = res->next;
            }
            else
            {
                res->next = new ListNode(l2->val);
                l2 = l2->next;
                res = res->next;
            }
        }
        if (!l1)
        {
            res->next = l2;
        }
        else if (!l2)
        {
            res->next = l1;
        }
        return head->next;
    }

    ListNode* recursive(ListNode *l1, ListNode *l2)
    {
        if (!l1)
            return l2;
        else if (!l2)
            return l1;
        ListNode *res = nullptr;
        if (l1->val <= l2->val)
        {
            res = new ListNode(l1->val);
            l1 = l1->next;
        }
        else
        {
            res = new ListNode(l2->val);
            l2 = l2->next;
        }
        res->next = mergeTwoLists(l1, l2);
        return res;
    }
};
