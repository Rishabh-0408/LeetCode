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
    void dfs(TreeNode* root, vector<string>& ans,string str){
        if(root == nullptr){
            return;
        }
        if(!str.empty()){
            str += "->";
        }
        str += to_string(root->val);
        if(root->left == nullptr && root->right == nullptr){
            ans.push_back(str);
            //str.clear();
        }
        dfs(root->left,ans,str);
        dfs(root->right,ans,str);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(root == nullptr){
            return ans;
        }
        string str = "";
        dfs(root,ans,str);
        return ans;
    }
};