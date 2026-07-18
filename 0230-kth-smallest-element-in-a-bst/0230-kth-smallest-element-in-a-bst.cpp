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
    int val;
    int kthSmallest(TreeNode* root, int k) {
        findkth(root, k);
        return val;
    }
    void findkth(TreeNode* root, int& k){
        if(root){
            findkth(root->left, k);
            if(--k == 0) {
                val = root->val;return;
            }
            findkth(root->right, k);
        }
    }
};