class Solution {
public:
    int getLength(ListNode * head){
        int count = 0;
        while(head != NULL){
            count++;
            head = head->next;
        }
        return count;
    }
    
    ListNode * deleteNthNode(ListNode * head, int n){
        if(head == NULL){
            return NULL;
        }
        if(n == 1){
            return head->next;
        }
        
        ListNode * temp = head;
        while(n > 2) {
            temp = temp->next;
            n--;
        }
        temp->next = temp->next->next;
        return head; 
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int nodeToBeRemoved = getLength(head) - n + 1;
        return deleteNthNode(head,nodeToBeRemoved);
    }
};