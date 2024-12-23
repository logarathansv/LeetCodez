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
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int swaps = 0;
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if(node->left != nullptr)
                    q.push(node->left);
                if(node->right != nullptr)
                    q.push(node->right);
            }
            vector<int> sorted = level;
            sort(sorted.begin(), sorted.end());
            unordered_map<int, int> mp;
            for(int i=0;i<level.size();i++){
                mp[level[i]] = i;
            } 
            for(int i=0;i<level.size();i++){
                if(sorted[i] != level[i]){
                    swaps++;
                    int pos = mp[sorted[i]];
                    mp[level[i]] = pos;
                    swap(level[pos], level[i]);
                }
            }
        }
        return swaps;
    }
};