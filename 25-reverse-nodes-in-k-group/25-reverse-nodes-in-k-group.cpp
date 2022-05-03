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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head, *prevFirst = NULL;
        bool isFirst = true;
        
        int n = 0;
        while(curr != NULL) {
            curr = curr->next;
            n++;
        }
        curr = head;
        while(curr != NULL && n - k >= 0) {
            
            ListNode* prev = NULL, *first = curr;
            int count = 1;
            while(curr != NULL && count <= k) {
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
                count++;
            }
            n -= k;
            if(isFirst) {
                head = prev;
                isFirst = false;
            }
            
            if(prevFirst == NULL) {
                prevFirst = first;
            }
            else {
                prevFirst->next = prev;
                prevFirst = first;
            }        
        }
        
        if(!isFirst && n - k != 0) {
            prevFirst->next = curr;
        }
        
        return head;
        
    }
};