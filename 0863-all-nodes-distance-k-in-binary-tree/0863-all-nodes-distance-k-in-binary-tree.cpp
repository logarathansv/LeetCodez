/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        queue<TreeNode*> q;
        unordered_map<TreeNode*, TreeNode*> mp; // tracks parent nodes
        vector<pair<int, int>> distvect;

        q.push(root);
        while(!q.empty()){
            int s = q.size();
            for(int i=0;i<s;i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left) {
                    mp[node->left] = node;
                    q.push(node->left);
                }
                if(node->right) {
                    mp[node->right] = node;
                    q.push(node->right);
                }
            }
        }
        vector<int> ans;
        unordered_map<TreeNode*, bool> vis;

        q.push(target);
               
        while(k-- && !q.empty()){
            int s = q.size();
            for(int i=0;i<s;i++){
                TreeNode* node = q.front();q.pop();
                 vis[node] = 1;
                if(node->left && !vis[node->left])
                    q.push(node->left);
                if(node->right && !vis[node->right])
                    q.push(node->right);
                if(mp[node] && !vis[mp[node]])
                    q.push(mp[node]);
            }
        }

        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};