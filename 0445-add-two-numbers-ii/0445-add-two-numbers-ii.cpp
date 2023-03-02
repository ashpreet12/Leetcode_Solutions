class Solution {
public:
    ListNode* addNode(ListNode * head,int val){
        ListNode * temp = new ListNode(val);
        if(head == NULL){
            return temp;
        }
        ListNode * curr = head;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = temp;
        return head;
    } 
    ListNode* reverseLinkedList(ListNode * head){
        ListNode * prevPtr = NULL;
        ListNode * currPtr = head;
        ListNode * nextPtr = NULL;
        
        while(currPtr != NULL){
            if(currPtr->next == NULL){
                head = currPtr;
            }
            nextPtr = currPtr->next;
            currPtr->next = prevPtr;
            prevPtr = currPtr;
            currPtr = nextPtr;
        }
        return head;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * rev_l1 = reverseLinkedList(l1);
        ListNode * rev_l2 = reverseLinkedList(l2);
        ListNode * sum = NULL;
        int carry = 0;
        
        while(rev_l1 != NULL && rev_l2 != NULL){
            int digitSum = carry + rev_l1->val + rev_l2->val;
            sum = addNode(sum,digitSum % 10);
            carry = digitSum / 10;
            rev_l1 = rev_l1->next;
            rev_l2 = rev_l2->next;
        }
        
        while(rev_l1 != NULL){
            int digitSum = carry + rev_l1->val;
            sum = addNode(sum,digitSum % 10);
            carry = digitSum / 10;
            rev_l1 = rev_l1->next;
        }
        
        while(rev_l2 != NULL){
            int digitSum = carry + rev_l2->val;
            sum = addNode(sum,digitSum % 10);
            carry = digitSum / 10;
            rev_l2 = rev_l2->next;
        }
        
        return carry == 0 ? reverseLinkedList(sum) : reverseLinkedList(addNode(sum,carry));
    }
};