/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode* reverse(ListNode* head) {
    
        ListNode* curr = head, *prev = NULL;
        
        while(curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
        
    }
    bool isPalindrome(ListNode* head) {
        // reverse till the middle of the linked list
        
        ListNode* slow = head, *fast = head;
        
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* rev = NULL;
        if(fast == NULL)
            rev = reverse(slow);
        else
            rev = reverse(slow->next);
        
        ListNode* curr = head;
        while(rev != NULL) {
            if(rev->val != curr->val)
                return false;
            
            cout << rev->val << " " << curr->val;
            
            rev = rev->next;
            curr = curr->next;
        }
        
        
        int count = 0;
        curr = head;
        while(curr != NULL) {
            curr = curr->next;
            count++;
            
            if(count > 2)
                break;
        }
        
        if(count == 2){
            if(head->val == head->next->val)
                return true;
            else
                return false;
        }
        
        
        return true;
        
    }
};