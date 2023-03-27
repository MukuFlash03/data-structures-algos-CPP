class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* nxt = node->next;
        node->val = nxt->val;
        node->next = nxt->next;
        delete nxt;
    }
};

/* Soln 2
class Solution {
public:
    void deleteNode(ListNode* node) {
        *node = *node->next;
    }
};
*/