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
    vector<tuple<int,int,int>> nodes;
    void DFS(TreeNode* root, int row, int col){
        if(!root){
            return ;
        }
        nodes.push_back({col,row,root->val});
        DFS(root->left,row+1,col-1);
        DFS(root->right,row+1,col+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        DFS(root,0,0);
        sort(nodes.begin(),nodes.end());
        vector<vector<int>> ans;
        int preCol = INT_MIN;

        for(auto& [col,row,val] : nodes){
            if(col != preCol){
                ans.push_back({});
                preCol = col;
            }
            ans.back().push_back(val);
        }
        return ans;
    }
};