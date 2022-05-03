/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        Node* curr = head;
        
        while(curr != NULL)
        {
            Node* temp = new Node(curr->val);
            temp->next = curr->next;
            curr->next = temp;
            curr = curr->next->next;
        }
        
        Node* prev = NULL;
        curr = head;
        
        while(curr != NULL) {
            prev = curr;
            curr = curr->next;
            curr->random = prev->random != NULL ? prev->random->next : NULL;  
            curr = curr->next;
        }
        
        Node* head1 = NULL;
        curr = head;
        
        if(curr != NULL)
        {   
            Node* copy = curr->next;
            head1 = copy;
            
            while(curr != NULL && copy != NULL)
            {
                curr->next = curr->next != NULL ? curr->next->next : NULL;
                copy->next = copy->next != NULL ? copy->next->next : NULL;  
                curr = curr->next;
                copy = copy->next;
            }
            
        }
        
        return head1;
        
    }
};