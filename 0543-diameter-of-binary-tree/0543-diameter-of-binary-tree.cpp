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
    
    int find(TreeNode* node,int & diam){
        if(node==NULL) return 0;
        
        int lh= find(node->left ,diam);
        int rh= find(node->right, diam);
        diam =  max (diam, rh+lh);
        
        return 1+ max(lh,rh);
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        
        
        int diam=0;
        find(root,diam);
        return diam;
    }
};