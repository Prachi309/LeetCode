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
    void getPath(TreeNode* root,  vector<string > &ans,
        vector<int>& path){
        
        if(root==NULL) return;
        
        path.push_back(root->val);
        
        if(root->left==NULL && root->right==NULL){
          string currentPath = to_string(path[0]);
            for (int i = 1; i < path.size(); ++i) {
                currentPath += "->" + to_string(path[i]);
            }
            ans.push_back(currentPath);
        }
        
        else{
            getPath(root->left,ans,path);
            getPath(root->right,ans,path);
        }
        path.pop_back();
        
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string > ans;
        vector<int> path;
        
        if(root==NULL) return ans;
        
         getPath(root, ans, path);
        return ans;
    }
};