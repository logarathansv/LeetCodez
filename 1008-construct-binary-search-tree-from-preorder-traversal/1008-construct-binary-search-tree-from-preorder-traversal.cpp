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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return bst(preorder, i, INT_MAX);
    }

    TreeNode* bst(vector<int>& pre, int& ind, int upper){
        if(ind >= pre.size() || pre[ind] > upper) return nullptr;

        TreeNode* node = new TreeNode(pre[ind++]);
        node->left = bst(pre, ind, node->val); 
        node->right = bst(pre, ind, upper); 
    
        return node;
    }
};