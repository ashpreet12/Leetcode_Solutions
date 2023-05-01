class Solution {
public:
    ListNode* getLastNode(ListNode * head){
        if(head == NULL){
            return NULL;
        }
        ListNode * curr = head;
        while(curr->next != NULL){
            curr = curr->next;
        }
        return curr;
    } 
    ListNode* addNode(ListNode * head, int value){
        ListNode * temp = new ListNode(value);
        ListNode * curr = head;
        
        if(head == NULL){
            return temp;
        }
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = temp;
        return head;
    } 
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL){
            return NULL;
        }
        ListNode * lessThan = NULL;
        ListNode * notLessThan = NULL;
        
        ListNode * temp = head;
        while(temp != NULL){
            if(temp->val < x){
                lessThan = addNode(lessThan,temp->val);
            }else{
                notLessThan = addNode(notLessThan,temp->val);
            }
            temp = temp->next;
        }
        ListNode * join = getLastNode(lessThan);
        if(join != NULL){
            join->next = notLessThan;
        }
        
        return join!= NULL ? lessThan : notLessThan;
        
    }
};