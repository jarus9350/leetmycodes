/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dumb = new ListNode(0);

        int carry = 0;

        ListNode* temp = dumb;
        while (l1 || l2) {
            int newVal =  (l1 ? l1->val : 0 ) + (l2 ? l2->val : 0 );
            int nodeVal = (newVal + carry)%10;
            carry = (newVal + carry)/10;
            ListNode* newNode = new ListNode(nodeVal);
            temp->next = newNode;
            temp = temp->next;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        if (carry) {
            ListNode* newNode = new ListNode(carry);
            temp->next = newNode;
        }

        return dumb->next;
        
    }
};