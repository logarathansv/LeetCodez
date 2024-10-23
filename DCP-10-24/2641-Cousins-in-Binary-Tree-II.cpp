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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<int> level;
        while(!q.empty()){
            int size = q.size();
            
            int sum = 0;
            for(int i=0;i<size;i++){
                TreeNode* fr = q.front();
                q.pop();
                sum += fr->val;

                if(fr->left != nullptr){
                    q.push(fr->left);
                }
                if(fr->right != nullptr){
                    q.push(fr->right);
                }
            }
            level.push_back(sum);
        }
        q.push(root);
        int lvl = 1;
        root->val = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* fr = q.front();
                q.pop();
                int sib = (fr->left ? fr->left->val : 0) + (fr->right ? fr->right->val : 0);


                if(fr->left != nullptr){
                    fr->left->val = level[lvl] - sib;
                    q.push(fr->left);
                }
                if(fr->right != nullptr){
                    fr->right->val = level[lvl] - sib;
                    q.push(fr->right);
                }
            }
            lvl++;
        }
        return root;
    }
};