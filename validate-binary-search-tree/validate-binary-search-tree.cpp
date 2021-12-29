
class Solution {
public:
    bool isAscending(vector<int> arr){
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] <= arr[i-1]){
                return false;
            }
        }
        return true;
    }
    void inorderTraversal(TreeNode* root,vector<int> &inorder){
        if(root == NULL){
            return;
        }
        
        if(root->left != NULL){
           inorderTraversal(root->left,inorder); 
        }
        
        inorder.push_back(root->val);
        
        if(root->right != NULL){
           inorderTraversal(root->right,inorder); 
        } 
    }
    bool isValidBST(TreeNode* root) {
        vector<int> inorder;
        inorderTraversal(root,inorder);
     
        return isAscending(inorder);
    }
};