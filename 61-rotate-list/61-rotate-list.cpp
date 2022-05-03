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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)
            return NULL;
        ListNode* tail = NULL;
        
        ListNode* curr = head;
        
        int count = 0;
        
        while(curr != NULL) {
            count++;
            tail = curr;
            curr = curr->next;
        }
        
        k = k % count;
        if(k == 0)
            return head;
        int i = 0;
        curr = head;
        ListNode* prev = NULL;
        while(i < count - k) {
            i++;
            prev = curr;
            curr = curr->next;     
        }
        prev->next = NULL;
        tail->next = head;
        
        return curr;                        
    }
};