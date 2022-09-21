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
    int helper(TreeNode* node){
        if(!node) return 0;
        return max(helper(node->left),helper(node->right))+1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        
        int left = helper(root->left);
        int right = helper(root->right);
        if(abs(left-right)<=1 && isBalanced(root->left) && isBalanced(root->right)) return true;
        return false;
        
    }
};