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
class BSTIterator {
public:
    
    // 3 7 9 15 20
    vector<int > in;
    int i;
    void inorder( TreeNode* root){
        if(!root) return ;
        inorder(root->left);
        in.push_back(root->val);
        inorder(root->right);
    }
    BSTIterator(TreeNode* root) {
        in.clear();
        inorder(root);
        i=0;
    }
    
    int next() {
        return in[i++];
    }
    
    bool hasNext() {
        return i <in.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */