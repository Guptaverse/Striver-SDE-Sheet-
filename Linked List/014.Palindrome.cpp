// optimized : TC : O(N) , SC : O(1)+O(auxiliary space of recursive call)
class Solution {
public:
    ListNode* temp;
    bool helper(ListNode* node)
    {
        if(node==NULL)
            return true;
        bool flag=helper(node->next);
        bool check=node->val==temp->val;
        temp=temp->next;
        return flag&&check;
    }
    bool isPalindrome(ListNode* head) {
        
        temp=head;
        return helper(head);
    }
};