/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int cnt1 = 0;
        int cnt2 = 0;
        
//         0 0 0 0 
                 // 0   
        
        
        ListNode* curr = headA;
        while(curr != NULL) {
            cnt1++;
            curr = curr->next;
        }
        curr = headB;
        while(curr != NULL) {
            cnt2++;
            curr = curr->next;
        }
        
        if(cnt1 > cnt2) {
            int a = cnt1 - cnt2;
            
            curr = headA;
            while(a--)
                curr = curr->next;
            
            ListNode* curr1 = headB;
            
            while(curr!=NULL && curr1 != NULL)
            {
                if(curr == curr1)
                    return curr;
                curr = curr->next;
                curr1 = curr1->next;
            } 
        }
        else {
            int a = cnt2 - cnt1;
            
            curr = headB;
            while(a--)
                curr = curr->next;
            
            ListNode* curr1 = headA;
            
            while(curr!=NULL && curr1 != NULL)
            {
                if(curr == curr1)
                    return curr;
                curr = curr->next;
                curr1 = curr1->next;
            } 
        }
        
        return NULL;
    }
};