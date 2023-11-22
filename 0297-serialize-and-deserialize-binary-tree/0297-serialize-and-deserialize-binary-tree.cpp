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
    void ser(TreeNode* root, string &s){
        
        if(root==NULL){
            s+="null,";
            return;
        }
     
          s+=to_string(root->val)+",";
          ser(root->left,s);
          ser(root->right,s);
    }
    string serialize(TreeNode* root) {
        string s="";
        ser(root,s);
        return s;
    }
    
    

    // Decodes your encoded data to tree.
    
    TreeNode* des(queue<string> &q) 
    {
        string s = q.front();
        q.pop();
        
        if(s == "null") return NULL;
        
        TreeNode* root = new TreeNode(stoi(s));
        root->left = des(q);
        root->right = des(q);
        return root;
    }
    TreeNode* deserialize(string data) {
        queue< string> q;
        string s="";
        for( char ch:data){
            if(ch==','){
                q.push(s);
                s="";
            }
            else s+=ch;
        }
        return des(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));