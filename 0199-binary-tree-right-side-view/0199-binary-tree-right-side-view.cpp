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
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr) return {};
        queue<TreeNode*> q;

        q.push(root);
        vector<int> rightside;

        while(!q.empty()){
            int size = q.size();
            int val = -1;

            for(int i=0;i<size;i++){
                TreeNode* curr = q.front();
                q.pop();

                val = curr->val;

                if(curr->left != nullptr) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }

            rightside.push_back(val);
        }

        return rightside;
    }
};