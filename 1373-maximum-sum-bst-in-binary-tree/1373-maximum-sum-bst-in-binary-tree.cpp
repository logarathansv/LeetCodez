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
class Node{
public:
    int mini, maxi, maxisum;
    Node(int minnode, int maxnode, int maxsum){
        this->mini = minnode;
        this->maxi = maxnode;
        this->maxisum = maxsum;
    }
};
class Solution {
public: 
    int ans = 0;
    Node func(TreeNode* root){
        if(!root) return Node(INT_MAX, INT_MIN, 0);

        auto left = func(root->left);
        auto right = func(root->right);

        if(left.maxi < root->val && root->val < right.mini){
            int curr = root->val + left.maxisum + right.maxisum;
            ans = max(curr, ans);
            return Node(min(left.mini, root->val), max(right.maxi, root->val), curr);
        }

        return Node(INT_MIN, INT_MAX, 0);
    }
    int maxSumBST(TreeNode* root) {
        func(root);
        return ans;
    }
};