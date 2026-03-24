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
    int maxPathDown(TreeNode* root){
        if(root == nullptr){
            return 0;
        }

        int left = max(0,maxPathDown(root->left));
        int right = max(0, maxPathDown(root->right));

        return root->val + max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        if(root == nullptr) return INT_MIN;

        int leftsum = max(0,maxPathDown(root -> left));
        int rightsum = max(0,maxPathDown(root->right));
        int curr_sum = root -> val + leftsum + rightsum;

        int leftsubtree = maxPathSum(root->left);
        int rightsubtree = maxPathSum(root->right);

        return max({curr_sum,leftsubtree,rightsubtree});
    }
};