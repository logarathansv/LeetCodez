/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void istree(TreeNode* t, vector<int>& l){
        if(t == nullptr) return;
        if(t->left == nullptr && t->right == nullptr){
            l.push_back(t->val);return;
        }

        istree(t->left, l);
        istree(t->right, l);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> l1, l2;

        istree(root1, l1);
        istree(root2, l2);

        return l1 == l2;
    }
};