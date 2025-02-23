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
    int i = 0;
    unordered_map<int, int> mp2;
    TreeNode* construct(vector<int>& preorder, int ps, int pe, vector<int>& postorder, int os, int oe, unordered_map<int, int>& mp){
        if(ps > pe || os > oe){
            return NULL;
        }
        if (ps == pe) return new TreeNode(preorder[ps]);

        TreeNode* node = new TreeNode(preorder[ps]);
        int postRoot = mp[preorder[ps+1]];
        int numsRem = postRoot - os + 1;

        node->left = construct(preorder, ps+1, ps+numsRem, postorder, os, postRoot, mp);
        node->right = construct(preorder, mp2[postorder[oe-1]], pe, postorder, postRoot+1, oe-1, mp);

        return node;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int, int> mp;
        for(int i=0;i<postorder.size();i++){
            mp[postorder[i]] = i;
            mp2[preorder[i]] = i;
        }
        return construct(preorder, 0, preorder.size()-1, postorder, 0, postorder.size()-1, mp);
    }
};