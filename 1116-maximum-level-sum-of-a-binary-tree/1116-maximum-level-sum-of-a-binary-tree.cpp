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
    int maxLevelSum(TreeNode* root) {
        if(!root) return 0;
        
        queue<TreeNode*> q;
        int ct = 0, maxi = INT_MIN, ind = 0;

        q.push(root);

        while(!q.empty()){
            int size = q.size();
            int sum = 0;

            for(int i=0;i<size;i++){
                TreeNode* curr = q.front();
                q.pop();

                sum += curr->val;

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }

            ct++;

            if(sum > maxi){
                maxi = sum;
                ind = ct;
            }
        }

        return ind;
    }
};