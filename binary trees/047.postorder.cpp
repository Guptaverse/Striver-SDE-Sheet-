// Iterative approach using 2 stacks
class Solution {
public:
    vector<int> ans;
    vector<int> postorderTraversal(TreeNode* root) {
        if (root==NULL){
            return ans;
        }
        stack<TreeNode*>st1,st2;
        st1.push(root);
        while(!st1.empty()){
            root = st1.top();
            st1.pop();
            st2.push(root);
            if(root->left) st1.push(root->left);
            if(root->right) st1.push(root->right);
        }
        while(!st2.empty()){
            ans.push_back(st2.top()->val);
            st2.pop();
        }
        return ans;
    }
};

// recursive

class Solution {
public:
    vector<int> ans;
    vector<int> postorderTraversal(TreeNode* root) {
       if (root==NULL){
            return { };
        }
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        ans.push_back(root->val);
        return ans;
    }
};