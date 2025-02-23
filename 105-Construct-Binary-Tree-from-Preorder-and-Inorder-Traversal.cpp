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
    TreeNode* build(vector<int>& preorder, int ps, int pe, vector<int>& inorder, int is, int ie, unordered_map<int,int>& mp){
        if(ps > pe || is > ie) return NULL;
        
        TreeNode* node = new TreeNode(preorder[ps]);
        int inRoot = mp[node->val];
        int numRem = inRoot - is;
        
        node->left = build(preorder, ps+1, ps+numRem, inorder, is, inRoot-1, mp);
        node->right = build(preorder, ps+numRem+1, pe, inorder, inRoot+1, ie, mp);

        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, mp);
    }
};