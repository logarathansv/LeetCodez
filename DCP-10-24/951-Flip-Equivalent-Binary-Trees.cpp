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
    bool flip(TreeNode* root1, TreeNode* root2){
        if(root1 == NULL && root2 == NULL) return true;
        else if(root1 == NULL || root2 == NULL) return false;

        return (root1->val == root2->val &&((flip(root1->left, root2->right) || flip(root1->left, root2->left) )&&( flip(root1->right, root2->right) || flip(root1->right, root2->left))));
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return flip(root1, root2);
    }
};