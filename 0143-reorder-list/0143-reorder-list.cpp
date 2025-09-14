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
    void reorderList(ListNode* head) {
        if(!head || !head->next) return ;
        ListNode* f = head;
        ListNode* s = head;

        while(f != nullptr && f->next != nullptr){
            f = f->next->next;
            s = s->next;
        }

        ListNode* prev = nullptr;
        ListNode* t = s->next;
        s->next = nullptr;

        while(t != nullptr){
            ListNode* front = t->next;
            t->next = prev;
            prev = t;
            t = front;
        }

        f = head;s = prev;

        while(s != nullptr){
            ListNode* fn = f->next;
            ListNode* sn = s->next;
            f->next = s;
            s->next = fn;
            s = sn;f =fn;
        }
    }
};