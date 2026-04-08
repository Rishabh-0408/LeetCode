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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            // Case 1 & 2: No left child or no right child
            if (!root->left) return root->right;
            if (!root->right) return root->left;

            // Case 3: Two children — find inorder successor
            TreeNode* successor = root->left;
            while (successor->right) {
                successor = successor->right;
            }

            root->val = successor->val;
            root->left = deleteNode(root->left, successor->val);
        }

        return root;
    }
};