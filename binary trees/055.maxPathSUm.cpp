class Solution {
public:
    int maxi=INT_MIN;
    int helper(TreeNode* node)
    {
        if(node == NULL) return 0;
        int l_sum = max(0,helper(node->left));
        int r_sum = max(0,helper(node->right));
        maxi = max(maxi,l_sum+r_sum+node->val);
        return node->val + max(l_sum , r_sum);
    }
    int maxPathSum(TreeNode* root) {
        helper(root);
        return maxi;
    }
};