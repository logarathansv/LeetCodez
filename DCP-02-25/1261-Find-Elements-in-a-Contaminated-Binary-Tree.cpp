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
class FindElements {
public:
    TreeNode* root;
    unordered_set<int> st;
    FindElements(TreeNode* root) {
        this->root = root;
        root->val = 0;
        initialize(root);   
    }
    void initialize(TreeNode* root){
        // if(root) return ;
        // cout<<root->val;
        st.insert(root->val);
        if(root->left){
            root->left->val = root->val * 2 + 1;
            initialize(root->left);
        }
        if(root->right){
            root->right->val = root->val * 2 + 2;
            initialize(root->right);
        }
    }
    bool find(int target) {
        return st.find(target) != st.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */