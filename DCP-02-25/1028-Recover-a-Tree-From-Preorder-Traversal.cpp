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
    TreeNode* recoverTree(string traversal, int depth){
        if(i == traversal.size()) return NULL;
        int currdep = 0, val = 0;

        while(traversal[i] == '-') {currdep++;i++;}

        if(currdep < depth){
            i -= currdep;
            return NULL;
        }

        while(isdigit(traversal[i])){
            val = val*10 + traversal[i] - '0';
            i++;
        }

        TreeNode* node = new TreeNode(val);

        node->left = recoverTree(traversal, depth+1);
        node->right = recoverTree(traversal, depth+1);

        return node;
    }
    TreeNode* recoverFromPreorder(string traversal) {
        stack<TreeNode*> st;
        int i = 0;
        while(i < traversal.size()){
            int currdep = 0;
            while(i < traversal.size() && traversal[i] == '-'){
                currdep++;
                i++;
            }
            
            int val = 0;
            while(isdigit(traversal[i])){
                val = val*10 + traversal[i] - '0';
                i++;
            }

            TreeNode* node = new TreeNode(val);

            while(currdep < st.size()){
                st.pop();
            }
            if(!st.empty()){
                if(!st.top()->left){
                    st.top()->left = node;
                }
                else{
                    st.top()->right = node;
                }
            }
            st.push(node);
        }

        while(st.size() > 1){
            st.pop();
        }

        return st.top();
        // return recoverTree(traversal, 0);
    }

};