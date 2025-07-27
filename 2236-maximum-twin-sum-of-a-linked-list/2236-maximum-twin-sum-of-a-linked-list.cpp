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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        vector<int> ele;

        while(fast != nullptr && fast->next != nullptr){
            ele.push_back(slow->val);

            slow = slow->next;
            fast = fast->next->next;
        }

        // ListNode* prev = nullptr;
        ListNode* tp = slow;int maxi = INT_MIN;
        
        while(tp != nullptr){
            maxi = max(tp->val + ele.back(), maxi);
            ele.pop_back();
            
            tp = tp->next;
            // ListNode* f = tp->next;
            // tp->next = prev;
            // prev = tp;
            // tp = f;
        }

        

        // while(prev != nullptr){
        //     cout<<"1"<<prev->val + head->val;
        //     maxi = max(prev->val + head->val, maxi);

        //     prev = prev->next;
        //     head = head->next;
        // }

        return maxi;
    }
};