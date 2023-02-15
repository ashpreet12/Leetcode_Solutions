class Solution {
public:
    void invertTreeReccursive(TreeNode * &root){
        if(root == NULL){
            return;
        }
        TreeNode * temp = root->left;
        root->left = root->right;
        root->right = temp;
        invertTreeReccursive(root->left);
        invertTreeReccursive(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        invertTreeReccursive(root);
        return root;
    }
};