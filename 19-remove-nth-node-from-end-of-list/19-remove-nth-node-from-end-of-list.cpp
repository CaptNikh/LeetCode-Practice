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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int count = 1;
        ListNode* curr = head;
        while(curr->next != NULL)
        {
            curr = curr->next;
            count++;
        }
        
        // cout << count;
       
        
        
        int pos = count - n + 1;
        curr = head;
        ListNode* temp = NULL;
        int i = 1;
        
        if(pos == 1)
        {
            ListNode* temp = head->next;
            delete head;
            return temp;
        }
        while(i < pos) {
            temp = curr;
            curr = curr->next;
            i++;
        }
        
        temp->next = curr->next;
        delete curr;
        return head;
    }
};