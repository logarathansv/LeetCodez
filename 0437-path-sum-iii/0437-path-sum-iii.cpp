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
    int ans = 0;
    void findPath(TreeNode* root, long long sum){
        if(root == nullptr) return;
        if(sum == root->val) ans++;

        findPath(root->left, sum - root->val);
        findPath(root->right, sum - root->val);

    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root){
            findPath(root, targetSum);
            pathSum(root->left, targetSum);
            pathSum(root->right, targetSum);
        }

        return ans;
    }
};