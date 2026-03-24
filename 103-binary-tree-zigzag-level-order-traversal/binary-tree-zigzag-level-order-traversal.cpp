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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr)
        {
            return ans;
        }
        queue<TreeNode* > q;
        q.push(root);
        int level = 0;
        bool flag = false;
        while(!q.empty()){
            int size = q.size();
            level++;
            vector<int> curr;
            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                curr.push_back(node->val);
                if(node->left != nullptr){
                    q.push(node->left);
                } 
                if(node->right != nullptr){
                    q.push(node->right);
                }
            }
            if(flag){//level % 2 == 0
                reverse(curr.begin(),curr.end());
            }
            ans.push_back(curr);
            flag = !flag;
        }
        return ans;
    }
};