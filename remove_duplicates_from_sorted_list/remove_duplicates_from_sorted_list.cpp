#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p = head;

        if (!p || !p->next) {
            return p;
        }

        int cur = p->val;
        ListNode* p1 = p->next;
        while (p1) {
            while (p1 && p1->val == cur) {
                p1 = p1->next;
            }
            if (p1) {
                p->next = p1;
                p = p->next;
                cur = p->val;
                p1 = p->next;
            } else {
                p->next = nullptr;
            }
        }

        return head;
    }
};

int main() {
    Solution solution;

    ListNode* head = new ListNode(1);
    ListNode* p = head;

    ListNode* n1 = new ListNode(1);
    p->next = n1;
    p = p->next;
    ListNode* n2 = new ListNode(3);
    p->next = n2;
    p = p->next;
    ListNode* n3 = new ListNode(3);
    p->next = n3;
    p = p->next;

    ListNode* r = solution.deleteDuplicates(head);

    ListNode* p1 = r;
    while (p1) {
        cout << p1->val << " ";
        p1 = p1->next;
    }
    cout << endl;

    return 0;
}