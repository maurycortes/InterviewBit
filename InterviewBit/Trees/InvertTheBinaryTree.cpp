void mirror(TreeNode * A){
    if(!A)
        return;
    mirror(A->left);
    mirror(A->right);
    TreeNode *temp;
    temp=A->left;
    A->left=A->right;
    A->right=temp;
}
TreeNode* Solution::invertTree(TreeNode* root) {
    mirror(root);
    return root;
}