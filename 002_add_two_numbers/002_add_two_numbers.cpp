#include <iostream>
#include <iterator>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* ret = NULL, *p1, *p2, *pr, *node;
        int increase = 0;
        for (p1 = l1, p2 = l2; increase != 0 || p1 != NULL || p2 != NULL; 
            p1 = p1 == NULL ? p1 : p1->next, 
            p2 = p2 == NULL ? p2 : p2->next) 
        {
            int val = 0;
            val += p1 == NULL ? 0 : p1->val;
            val += p2 == NULL ? 0 : p2->val;
            val += increase;
            if (val >= 10) {
                val = val - 10;
                increase = 1;
            } 
            else 
            {
                increase = 0;
            }
            node = new ListNode(val);

            if (ret == NULL) {
                ret = pr = node;
            }
            else
            {
                pr = pr->next = node;
            }
        }
        return ret;
    }
    void release(ListNode* l)
    {
        ListNode *p, *q;
        for (p = l; p != NULL; )
        {
            q = p;
            p = p->next;
            delete q; 
        }
    }
    ListNode* alloc(int vals[], size_t size)
    {
        ListNode *head = NULL, *p;
        cout << "size: " << size << endl;
        for (int i = 0; i < size; i ++)
        {
            cout << "i: " << i 
                << ", vals[" << i << "]: " << vals[i] << endl;
            ListNode *node = new ListNode(vals[i]);
            if (head == NULL) 
            {
                head = p = node;
            } 
            else
            {
                p = p->next = node; 
            }
        }
        return head;
    }
    void print(ListNode* l)
    {
        for (ListNode *p = l; p != NULL; p = p->next)
        {
            cout << p->val;
            if (p->next != NULL) 
            {
                cout << "->";
            }
        }
    }
};

int main() 
{
    Solution s;
    // 2->4->3 + 5->6->4 = 7->0->8
    cout << "alloc l1" << endl;
    int vals1[] = {5};
    ListNode *l1 = s.alloc(vals1, sizeof(vals1)/sizeof(vals1[0]));
    cout << "alloc l2" << endl;
    int vals2[] = {5};
    ListNode *l2 = s.alloc(vals2, sizeof(vals2)/sizeof(vals2[0]));
    
    s.print(l1);
    cout << " + ";
    s.print(l2);
    cout << " = ";
    ListNode *rst = s.addTwoNumbers(l1, l2);
    s.print(rst);
    cout << endl;

    cout << "release l1" << endl;
    s.release(l1);
    cout << "release l2" << endl;
    s.release(l2);
    cout << "release rst" << endl;
    s.release(rst);

    return 0;
}

