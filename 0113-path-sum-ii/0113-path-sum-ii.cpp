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
    void findpathSum(TreeNode* root, int target, vector<vector<int>>& paths, vector<int>& path){
        if(root == nullptr) return;

        target -= root->val;
        path.push_back(root->val);

        if(!root->left && !root->right && target == 0)
                paths.push_back(path);
        else{
                findpathSum(root->left, target, paths, path);
                findpathSum(root->right, target, paths, path);
        }

        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return {};
        vector<vector<int>> paths;
        vector<int> path;

        findpathSum(root, targetSum, paths, path);

        return paths;
    }
};