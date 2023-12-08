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
    string sol( TreeNode* root,TreeNode* p){
        
        if( (p->left==NULL && p->right==NULL) || ( root==NULL && p->right==NULL) ) return "";
        
        if(root==NULL && p->left==NULL ) return "()";
        
        
        return "("+to_string(root->val)+sol(root->left,root)+sol(root->right,root)+")";
    }
    string tree2str(TreeNode* root) {
        
        string ans="";
        ans+=to_string(root->val);
        ans+=sol(root->left,root);
        ans+=sol(root->right,root);
        return ans;
    }
};