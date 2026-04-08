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
    TreeNode* helper(TreeNode* root){
        //if there is no left child ,right me jao
        if(root->left == nullptr){
            return root = root->right;
        }
        //if there is no right chid, left me jao
        if(root->right == nullptr){
            return root = root->left;
        }
        TreeNode* rightchild = root->right;
        TreeNode* lastright = findsuccessor(root->left);

        lastright->right = rightchild;
        return root->left;
    }
    TreeNode* findsuccessor(TreeNode* root){
        while(root->right != nullptr){
            root = root->right;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root ==  nullptr){
            return nullptr;
        }
        if(root->val == key){
            return helper(root);
        }
        TreeNode* curr = root;
        while(curr != nullptr){
            if(curr->val > key){
                if(curr->left != nullptr && curr->left->val == key){
                    curr->left = helper(curr->left);
                    break;
                }
                else{
                    curr = curr->left; 
                }
            }
            else{
                if(curr->right != nullptr && curr->right->val == key){
                    curr->right = helper(curr->right);
                    break;
                }
                else{
                    curr = curr->right;
                }
            }
        }
        return root;
    }
};