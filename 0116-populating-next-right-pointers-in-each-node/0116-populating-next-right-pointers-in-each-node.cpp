/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        Node* node = root;
        Node* nxt = nullptr;
        if(!root->next)
        nxt = root->left;

        while(node && nxt){
            node->left->next = node->right;
            if(node->next){
                node->right->next = node->next->left;
            }

            node = node->next;
            if(!node){
                node = nxt;
                nxt = node->left;
            }
        }

        return root;
    }
};