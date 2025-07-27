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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head; 
        ListNode* even = nullptr;
        ListNode* odd = head;
        ListNode* heade = nullptr;

        while(odd != nullptr && odd->next != nullptr){
            if(even == nullptr) {even = odd->next;heade = even;}
            else {even->next = odd->next;even = even->next;}
            
            cout<<"1";
            if(odd->next->next == nullptr) break;

            odd->next = odd->next->next;
            odd = odd->next;
        }
        even->next = nullptr;
        odd->next = heade;

        return head;
    }
};