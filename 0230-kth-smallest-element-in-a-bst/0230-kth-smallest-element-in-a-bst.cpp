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
    void inorder(TreeNode* node, int &cnt, int k , int &ksmall){
        if(!node || cnt>=k) return;
        
        inorder(node->left, cnt, k, ksmall);
        
        cnt++;
        
        if(cnt==k){
            ksmall= node->val;
            return;
        }
        
        inorder(node->right,cnt,k,ksmall);
        
        
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt=0;
        int ksmall=INT_MIN;
        inorder(root, cnt, k, ksmall);
        
        return ksmall;
        
        
    }
};