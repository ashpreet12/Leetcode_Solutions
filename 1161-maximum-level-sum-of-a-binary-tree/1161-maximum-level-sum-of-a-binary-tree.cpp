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
    int calculateSum(queue<TreeNode *> q){
        int sum = 0;
        while(!q.empty()){
            sum += q.front()->val;
            q.pop();
        }
        return sum;
    }
    int maxLevelSum(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        int level = 1;
        int max_sum = root->val;
        int max_level = 1;
        
        while(q.size() > 1){
            TreeNode * top = q.front();
            q.pop();
            
            if(top == NULL){
                level++;
                if(calculateSum(q) > max_sum){
                   max_level = level;
                   max_sum = calculateSum(q);
                } 
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
        return max_level;
    }
};