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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;

        ListNode* dumb = new ListNode(0);

        for (int i = 0 ; i < lists.size() ; i++){
            auto a = lists[i];
            if (a){
                pq.push({a->val,a});
            }
            
        }

        ListNode* temp = dumb;
        while (pq.size()){
            auto [val, node] = pq.top();
            pq.pop();

            temp->next = node;
            temp = temp->next;

            if (node->next) {
                pq.push({node->next->val,node->next});
            }
        }

        temp->next = nullptr;
        return dumb->next;

    }
};