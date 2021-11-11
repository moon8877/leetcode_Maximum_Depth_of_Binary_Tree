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
    int maxDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        vector<int> leafDepth;
        int count = 1;
        dfs(root,leafDepth,count);
        return *std::max_element(leafDepth.begin(),leafDepth.end());
    }
    void dfs(TreeNode* root,vector<int>& leafDepth,int count){
        if(root->left==nullptr && root->right==nullptr){
            leafDepth.push_back(count);
            return;
        }
        if(root->left){
            dfs(root->left,leafDepth,count+1);
        }
        if(root->right){
            dfs(root->right,leafDepth,count+1);
        }
        
    }
};
