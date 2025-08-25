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
    int maxPSum(TreeNode* root, int &sum){
        if(root == nullptr) return 0;
        int lsum = max(0, maxPSum(root->left, sum));
        int rsum = max(0, maxPSum(root->right, sum));
        sum = max(lsum + rsum + root->val, sum);

        return root->val + max(lsum, rsum);
    }
    int maxPathSum(TreeNode* root) {
        int sum=INT_MIN;
        maxPSum(root, sum);
        return sum;
    }
};