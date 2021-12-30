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
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL){
            return {};
        }
        vector<int>rightView;
        
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        
        while(q.size() > 1){
            TreeNode * top = q.front();
            q.pop();
            
            if(q.front() == NULL){
                rightView.push_back(top->val);
            }
            if(top == NULL){
                q.push(NULL);
            }else{
                if(top->left){
                    q.push(top->left);
                }
                
                if(top->right){
                    q.push(top->right);
                }
                
            }
        }
        return rightView;
    }
};