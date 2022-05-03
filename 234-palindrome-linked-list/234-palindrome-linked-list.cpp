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
    bool isPalindrome(ListNode* head) {
        vector<int> arr;
        
        ListNode* curr = head;
        while(curr != NULL) {
            arr.push_back(curr->val);
            curr = curr->next;
        }
        
        curr = head;
        int i = arr.size() - 1;
        while(curr != NULL) {
            if(curr->val != arr[i])
                return false;
            
            curr = curr->next;
            i--;
        }
        return true;
    }
};