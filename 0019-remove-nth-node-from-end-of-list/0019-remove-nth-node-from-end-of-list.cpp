
class Solution {
public:
    int getLength(ListNode * head){
        int count = 0;
        ListNode * curr = head;
        while(curr != NULL){
            curr = curr->next;
            count++;
        }
        return count;
    }
    ListNode * removeNthNode(ListNode * head,int n){
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
    ListNode * removeNthFromEnd(ListNode* head, int n) {
        int len = getLength(head);
        
        return removeNthNode(head, len - n + 1);
    }
};