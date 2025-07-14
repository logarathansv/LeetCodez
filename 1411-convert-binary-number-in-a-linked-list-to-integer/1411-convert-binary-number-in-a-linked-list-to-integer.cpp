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
    int getDecimalValue(ListNode* head) {
        string ans;

        while(head){
            ans += to_string(head->val);

            head = head->next;
        }

        cout<<ans;

        int res = 0, j = ans.size()-1;


        for(auto ch:ans){
            if(ch == '1') {res += pow(2,j);}
            j--;
        }

        return res;
    }
};