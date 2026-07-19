/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr) return "#";
        string str = "";

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();q.pop();
            
            if(node == nullptr) str += "#,";
            else{
                str += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }
        }

        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "#") return nullptr;
        stringstream ss(data);
        string s;

        getline(ss, s, ',');
        queue<TreeNode*> q;
        
        TreeNode* node = new TreeNode(stoi(s));
        q.push(node);
        while(!q.empty()){
            TreeNode* curr = q.front();q.pop();
            if(!getline(ss, s, ',')) break;
            if(s != "#"){
                curr->left = new TreeNode(stoi(s));
                q.push(curr->left);
            } 
            if(!getline(ss, s, ',')) break;
            if(s != "#"){
                curr->right = new TreeNode(stoi(s));
                q.push(curr->right);
            } 
        }

        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));