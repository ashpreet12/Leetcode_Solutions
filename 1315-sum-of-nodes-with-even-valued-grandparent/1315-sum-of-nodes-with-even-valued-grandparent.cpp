class Solution {
public:
    int ans = 0;
    int sumEvenGrandparent(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        
        if(root->val % 2 == 0){
            
            if(root->left && root->left->left){
                ans += root->left->left->val;
            }
            if(root->left && root->left->right){
                ans += root->left->right->val;
            }
            if(root->right && root->right->left){
                ans += root->right->left->val;
            }
            if(root->right && root->right->right){
                ans += root->right->right->val;
            }
        }
        
        sumEvenGrandparent(root->left);
        sumEvenGrandparent(root->right);
        
        return ans;
    }
};