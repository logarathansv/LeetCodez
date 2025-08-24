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
        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto ele:lists){
            while(ele != nullptr){
                pq.push(ele->val);
                ele = ele->next;
            }
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while(!pq.empty()){
            int num = pq.top();pq.pop();

            temp->next = new ListNode(num);
            temp = temp->next;
        }

        return dummy->next;
    }
};