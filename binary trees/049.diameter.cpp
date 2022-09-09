class Solution {
public:
    int height(TreeNode* node){
        if(!node) return 0;
        return max(height(node->left),height(node->right))+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;       
        return max(diameterOfBinaryTree(root->left),max(diameterOfBinaryTree(root->right),height(root->left)+height(root->right)));
    }
};