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
    int ans=INT_MAX;
    void sol( TreeNode* root , int h){
        if(root==NULL ) return ;
        
        if(root->left==NULL && root->right==NULL) {
            ans=min(ans, h);
        }
        sol(root->left,h+1);
        sol(root->right,h+1);
    }
    int minDepth(TreeNode* root) {
        
        if(root==NULL) return 0;
        sol(root,1);
        return ans;
    }
};