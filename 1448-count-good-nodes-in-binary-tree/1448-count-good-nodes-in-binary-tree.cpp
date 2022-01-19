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
    void inorderTraversal(TreeNode * root, int currMax,int & goodNodes){
        if(root == NULL){
            return;
        }
        if(root->val >= currMax){
            currMax = root->val;
            goodNodes++;
        }
        inorderTraversal(root->left,currMax,goodNodes);
        inorderTraversal(root->right,currMax,goodNodes);
    }
    int goodNodes(TreeNode* root) {
        int ans = 0;
        inorderTraversal(root,root->val,ans);
        return ans;
    }
};