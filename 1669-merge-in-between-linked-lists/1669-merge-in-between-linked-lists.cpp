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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
      ListNode* temp = list1;
        int curr = 0;
        
        while(curr != a - 1){
            temp = temp->next;
            curr++;
        }
        
        ListNode* temp2 = temp;
        
        while(curr != b)
        {
            curr++;
            temp2 = temp2->next;
        }
        
        ListNode* temp3 = list2;
        while(temp3->next != NULL)
            temp3 = temp3->next;
        
        
        temp ->next = list2;
        temp3->next = temp2->next;
        
        return list1;
        
        
        
    }
};