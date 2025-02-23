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
    TreeNode* build(vector<int>& inorder, int is, int ie, vector<int>& postorder, int ps, int pe, unordered_map<int, int>& mp){
        if(ps > pe || is > ie) return NULL;

        cout<<postorder[pe]<<\ \;
        TreeNode* node = new TreeNode(postorder[pe]);
        int inRoot = mp[node->val];
        int numsRem = inRoot - is;

        node->left = build(inorder, is, inRoot-1, postorder, ps, ps+numsRem-1, mp);
        node->right = build(inorder, inRoot+1, ie, postorder, ps+numsRem, pe-1, mp);

        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        return build(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, mp);
    }
};