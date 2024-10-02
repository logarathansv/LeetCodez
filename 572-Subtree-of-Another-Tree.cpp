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
    bool isSame(TreeNode* root, TreeNode* sub){
        if(root == nullptr && sub == nullptr) return true;
        if(root == nullptr || sub == nullptr) return false;
        if(root->val != sub->val) return false;
        return isSame(root->left,sub->left) && isSame(root->right,sub->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr) return false;
        if(isSame(root,subRoot) == true) return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};