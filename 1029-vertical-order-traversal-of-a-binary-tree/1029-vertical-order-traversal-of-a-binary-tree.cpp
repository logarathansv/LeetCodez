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
    struct cmp{
        bool operator()(pair<int, int>& a, pair<int, int>& b){
            if(a.second == b.second) return a.first>b.first;
            else return a.second>b.second;
        }
    };
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, priority_queue<pair<int, int>, vector<pair<int,int>>, cmp>> mp;
        queue<tuple<TreeNode*, int, int>> q;

        q.push({root, 0, 0});
        while(!q.empty()){
            auto [ele, pos, dep] = q.front();
            q.pop();
            mp[pos].push({ele->val, dep});

            if(ele->left != nullptr){
                q.push({ele->left, pos-1, dep+1});
            }
            if(ele->right != nullptr){
                q.push({ele->right, pos+1, dep+1});
            }
        }

        vector<vector<int>> ans;
        for(auto &ele:mp){
            // sort(ele.second.begin(), ele.second.end(), cmp);
            vector<int> res;
            while(!ele.second.empty()){
                res.push_back(ele.second.top().first);
                ele.second.pop();
            }
            ans.push_back(res);
        }

        return ans;
    }
};