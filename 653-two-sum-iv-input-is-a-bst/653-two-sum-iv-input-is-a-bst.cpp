class Solution {
public:
    void inorder(TreeNode * root,vector<int> &in){
        if(root == NULL){
            return;
        }
        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right,in);
    }
    bool find(vector<int> v,int target){
        int left = 0;
        int right = v.size() - 1;
        
        while(left < right){
            if(v[left] + v[right] == target){
                return true;
            }
            else if(v[left] + v[right] > target){
                right--;
            }else{
                left++;
            }
        }
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> in;
        inorder(root,in);
        return find(in,k);
    }
};