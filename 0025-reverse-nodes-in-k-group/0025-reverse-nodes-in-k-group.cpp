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
    pair<ListNode*, pair<ListNode*, ListNode*>> reverseList(ListNode* node, int k){
        ListNode* prev = nullptr;
        ListNode* temp = node;

        ListNode* head = node;

        for(int i=0;i<k && temp != nullptr;i++){
            ListNode* f = temp->next;
            temp->next = prev;
            prev = temp;
            temp = f;
        }

        return {prev, {head, temp}};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next) return head;
        int ct = 0;

        ListNode* tp = head;
        while(tp != nullptr){
            ct++;tp = tp->next;
        }

        ListNode* newhead = new ListNode(-1);
        ListNode* temp = newhead;
        ListNode* prev = nullptr;
        ListNode* nexthead = head;

        for(int i=0;i<ct/k;i++){
                auto ele = reverseList(nexthead, k);
                temp->next = ele.first;
                prev = ele.second.first;
                nexthead = ele.second.second;

                temp = prev;
        }

        if(prev != nullptr) prev->next = nexthead;

        return newhead->next;
    }
};