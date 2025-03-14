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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = nullptr, *next = nullptr;
        ListNode* curr = dummy;
        ListNode* l1 = dummy;

        for (int i = 0 ; i < left ; i++) {
            l1 = curr;
            curr = curr->next;
        }

        ListNode* l = curr;

        for (int j = left; j <= right ; j++ ){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        l1->next = prev;
        l->next = curr;

        return dummy->next;

    }
};