/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool dfs(TreeNode* root, TreeNode* p, vector<TreeNode* >& Path){
        if(!root){
            return false;
        }
        Path.push_back(root);
        if(root == p){
            return true;
        }
        if(dfs(root->left,p,Path) || dfs(root->right,p,Path)){
            return true;
        }
        Path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode* > PathP,PathQ;
        dfs(root,p,PathP);
        dfs(root,q,PathQ);
        int i = 0;
        TreeNode* lca = nullptr;
        while(i < PathP.size() && i < PathQ.size()){
            if(PathP[i] == PathQ[i]){
                lca = PathP[i];
            }
            i++;
        }
        return lca;
    }
};