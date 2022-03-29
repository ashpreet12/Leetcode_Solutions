class Solution {
public:
    ListNode* removeElements(ListNode * head, int val) {
        if(head == NULL){
            return NULL;
        }
        ListNode * prev = NULL;
        ListNode * temp = head;
        
        while(temp != NULL){
            
            if(temp->val == val && temp == head){
                temp = temp->next;
                head = temp;
                continue;
            }
            else if(temp->val == val){
                prev->next = temp->next;
                temp = temp->next;
                continue;
            }
            
            
            
            prev = temp;
            temp = temp->next;
        }
        return head;
    }
};