
class Solution {
public:
    bool isMirror(TreeNode * root_1, TreeNode * root_2){
        if(root_1 == NULL && root_2 == NULL){
            return true;
        }
        if(root_1 == NULL || root_2 == NULL){
            return false;
        }
        return (root_1->val == root_2->val && isMirror(root_1->left,root_2->right) && isMirror(root_1->right,root_2->left));
    }
    bool isSymmetric(TreeNode* root) {
        return isMirror(root->left,root->right);
    }
};