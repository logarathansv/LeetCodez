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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long>> q;

        q.push({root, 0});
        long long maxi = LLONG_MIN;

        while(!q.empty()){
            int s = q.size();
            long long fir = q.front().second;
            long long sec = 0;

            for(int i=0;i<s;i++){
                auto ele = q.front();
                q.pop();

                TreeNode* node = ele.first;
                long long width = ele.second;

                width -= fir;
                if(i == s-1) sec = width;

                if(node->left)
                q.push({node->left, 2*width});
                if(node->right)
                q.push({node->right, 2*width+1});
            }

            maxi = max(maxi, sec+1);
        }

        return maxi;
    }
};