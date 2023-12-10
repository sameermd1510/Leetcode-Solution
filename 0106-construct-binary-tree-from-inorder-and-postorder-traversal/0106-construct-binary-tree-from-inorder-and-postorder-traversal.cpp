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
    /*
    inorder   = [4 2 5 1 6 3 7]
    postorder = [4 5 2 6 7 3 1]

    So root would be 1 here and Left array which lay left of 1 is [4 2 5] and Right of 1 is [6 3 7]
    so left_inorder_array =  [4 2 5] and right_inorder_arry = [6 3 7]

    using 6 [ which is just rigth of 1] we are going to devide Postorder_array into two part
    [4 5 2] and [6 7 3]
    */
    unordered_map< int, int> mi,mp;
    TreeNode* sol( vector< int>& in, int x, int y, vector< int>& po, int a,int b){
        
        if( x> y || a > b) return NULL;
        TreeNode* root=new TreeNode(po[b]);
        
        int si=mi[po[b]];
        int li=si-x;
        
//         int rootIndex = mi[postorder[postEnd]];
//         int leftSubtreeSize = rootIndex - inStart;

//         root->left = buildTreeHelper(inorder, inStart, rootIndex - 1, postorder, postStart, postStart + leftSubtreeSize - 1);
//         root->right = buildTreeHelper(inorder, rootIndex + 1, inEnd, postorder, postStart + leftSubtreeSize, postEnd - 1);
        root->left=sol(in ,x,si-1 , po, a, a+li-1);
        root->right=sol( in,si+1 ,y, po, a+li, b-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& po) {
        
        if(in==po && in.size()==1) return new TreeNode(in[0]);
        for( int i=0;i<in.size();i++) mi[in[i]]=i;
        for( int i=0;i<po.size();i++) mp[po[i]]=i;
        return sol( in,0,in.size()-1 , po,0,po.size()-1);
    }
};