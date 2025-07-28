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
    int ct = 0;
    void countgood(TreeNode* root, int val){
        if(root == nullptr) return;

        if(root->val >= val) ct++;

        countgood(root->left, max(val, root->val));
        countgood(root->right, max(val, root->val));
    }
    int goodNodes(TreeNode* root) {
        if(root == nullptr) return 0;

        countgood(root, root->val);

        return ct;
    }
};