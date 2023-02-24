class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root == NULL){
            return {};
        }
        queue<Node*>q;
        q.push(root);
        q.push(NULL);
        vector<int> level;
        vector<vector<int>> orderSeq;
        
        while(q.size() > 1){
            Node * top = q.front();
            q.pop();
            
            if(top == NULL){
                orderSeq.push_back(level);
                level.clear();
                q.push(NULL);
            }else{
                level.push_back(top->val);
                for(auto node : top->children){
                    q.push(node);
                }
            }
        }
        orderSeq.push_back(level);
        return orderSeq;
    }
};