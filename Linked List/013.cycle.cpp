/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Naive approach : Using HashSet or we can also use HashMap
// TC : O(N*Log(N)), SC : O(N) 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL) return false;
        ListNode* temp =head;
        set<ListNode*>s;
        while(temp!=NULL){
           if(s.count(temp)) return true;
            s.insert(temp);
            temp =temp->next;
            }
        return false;
    }
};

// optimized : TC : O(N), SC : O(1)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head ||!head->next) return false;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            if(slow==fast) return true;
            slow = slow->next;
            fast = fast->next->next;           
        }
        return false;      
    }
};

