class Solution {
public:
    Node * levelOrder(Node * root){
        if(root == NULL){
            return NULL;
        }
        queue<Node *> q;
        q.push(root);
        q.push(NULL);
        
        while(q.size() > 1){
            Node * top = q.front();
            q.pop();
            if(top == NULL){
                q.push(NULL);
            }else{
                top->next = q.front();
                if(top->left){
                    q.push(top->left);
                }
                if(top->right){
                    q.push(top->right);
                }
            }
        }
        return root;
    }
   
    Node* connect(Node* root) {
        return levelOrder(root);
    }
};