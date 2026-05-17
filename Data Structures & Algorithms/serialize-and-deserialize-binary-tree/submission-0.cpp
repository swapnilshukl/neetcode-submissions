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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string s = "";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node == NULL) s.append("#,");
            else s.append(to_string(node->val)+',');
            if(node!=NULL){
                q.push(node->left);
                q.push(node->right);
            }
        }
       // cout<<s;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
         if (data.empty()) return nullptr;
        
        stringstream s(data);
        string str;
        getline(s, str, ',');
        
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
             TreeNode* parent = q.front();
            q.pop();
            
            // Process Left Child
            if (getline(s, str, ',')) {
                if (str != "#") {
                    parent->left = new TreeNode(stoi(str));
                    q.push(parent->left);
                }
            }

            // Process Right Child
            if (getline(s, str, ',')) {
                if (str != "#") {
                    parent->right = new TreeNode(stoi(str));
                    q.push(parent->right);
                }
            }
        }
        return root;
    }
};
