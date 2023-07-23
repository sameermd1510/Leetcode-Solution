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
    unordered_map< TreeNode* , int> dp;
    int rob(TreeNode* root) {
        
        if(root==NULL) return 0;
        if(dp.count(root)) return dp[root];
        
        int l_max=0,r_max=0;
        
        if(root->left){
            l_max=max(l_max , rob(root->left->left)+rob(root->left->right));
        }
        if(root->right){
            r_max=max(r_max , rob( root->right->left)+rob(root->right->right));
        }
        
        // max( root.val + valofLeftGrandchildern + value of rightGrandChildern  , leftchild+rightchild);
        return dp[root]=max( root->val+l_max+r_max , rob(root->left)+rob(root->right));
    }
};