class Solution {
public:
    int calculateHeight(TreeNode * root){
        if(root == NULL){
            return 0;
        }
        return 1 + max(calculateHeight(root->left) , calculateHeight(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        
        int left = calculateHeight(root->left);
        int right = calculateHeight(root->right);
        return abs(left - right) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};