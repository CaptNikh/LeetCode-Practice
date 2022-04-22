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
public: //requires 2 traversal and O(n) extra space
    ListNode* reverseList(ListNode* head) {
        vector<int> arr;
        ListNode* curr = head;
        while(curr != NULL) {
            arr.push_back(curr->val);
            curr = curr->next;
        }
        curr = head;
        int n = arr.size();
        int i = 1;
        while(curr != NULL)
        {
            curr->val = arr[n - i];
            i++;
            curr = curr->next;
        }
        return head;
    }
};