
//Naive Approach : TC: O(N) , SC : O(N)
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         ListNode*tempa = headA;
//         ListNode*tempb = headB;
//         set<ListNode*> s;
//         while(tempa!=NULL){
//             s.insert(tempa);
//             tempa = tempa->next;
//         }
//         while(tempb){
//             if(s.count(tempb)){
//                 // return tempb;
//                 break;
//             }
//             tempb = tempb->next;
//         }
//         return tempb;
//     }
// };


// optimized approach : TC: O(N), SC: O(1)

/*
initution : 
if I traverse linked list 1 then its length will be L1= m+x(say x is common part length)
similarly for linked list 2 then its length will be L2= n+x

then mathematically ,
    L1 = m+x + add(L2=n+x)
    L2 = n+x + add(L1=m+x)
    
    Now L1 = L2
    
    so when we traversed the Linked list 1 then we point the pointer to head of Linkedlist 2 and do same for Linked list 2, eventually they will meet.

*/


class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode *ptr1 = headA;
		ListNode *ptr2 = headB;
        
		while(ptr1 != ptr2){
			if(ptr1 == NULL){
				ptr1 = headB;
			}
			else{
				ptr1 = ptr1 -> next;
			}
			if(ptr2 == NULL){
				ptr2 = headA;
			}
			else{
				ptr2 = ptr2 -> next;
			}
		}
		return ptr1;
	}
};