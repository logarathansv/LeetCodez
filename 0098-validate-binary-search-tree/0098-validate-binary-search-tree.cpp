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
    bool isvalid(TreeNode* root, long mini, long maxi){
        if(root == nullptr) return true;

        if(root->val >= maxi || root->val <= mini) return false;
        return isvalid(root->left, mini, root->val) && isvalid(root->right, root->val, maxi);
    }
    bool isValidBST(TreeNode* root) {
        return isvalid(root, (long)INT_MIN+INT_MIN, (long)INT_MAX+INT_MAX);
    }
};