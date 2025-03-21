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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(root == NULL) return -1;
        priority_queue<long long> pq;
        queue<TreeNode *> q;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int size = q.size();
            long long sum = 0;
            level ++;
            for(int i=0;i<size;i++){
                TreeNode* nd = q.front();
                q.pop();

                sum += nd->val;
                if(nd->left != nullptr){
                    q.push(nd->left);
                }
                if(nd->right != nullptr){
                    q.push(nd->right);
                }
            }

            pq.push(sum);
        }
        for(int i=1;i<k;i++){
            pq.pop();
        }
        return k>level?-1:pq.top();
    }
};