TreeNode * top = q.front();
q.pop();
if(top == NULL){
level ++;
levels.push_back(isEvenLevel(q));
if(level >= 2 && levels[level - 2]){
requiredSum += sumLevel(q);
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
}
int sumEvenGrandparent(TreeNode* root) {
if(root == NULL){
return 0;
}
}
};