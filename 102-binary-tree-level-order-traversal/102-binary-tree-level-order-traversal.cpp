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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL){
            return {};
        }
        vector<vector<int>>ans;
        vector<int>level;
        queue<TreeNode*> tree;
        tree.push(root);
        tree.push(NULL);
        
        while(tree.size() > 1){
            TreeNode * top = tree.front();
            tree.pop();
            
            if(top == NULL){
                ans.push_back(level);
                level.clear();
                tree.push(NULL);
            }
            else{
                level.push_back(top->val);
                
                if(top->left){
                    tree.push(top->left);
                }
                if(top->right){
                    tree.push(top->right);
                }
            }
        }
        ans.push_back(level);
        return ans;
    }
};