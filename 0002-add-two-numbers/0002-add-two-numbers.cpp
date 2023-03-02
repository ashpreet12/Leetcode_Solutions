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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * sum = NULL;
        int carry = 0;
        
        while(l1 != NULL && l2 != NULL){
            int digitSum = carry + l1->val + l2->val;
            sum = addNode(sum,digitSum % 10);
            carry = digitSum / 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1 != NULL){
            int digitSum = carry + l1->val;
            sum = addNode(sum,digitSum % 10);
            carry = digitSum / 10;
            l1 = l1->next;
        }
        
        while(l2 != NULL){
            int digitSum = carry + l2->val;
            sum = addNode(sum,digitSum % 10);
            carry = digitSum / 10;
            l2 = l2->next;
        }
        
        return carry == 0 ? sum : addNode(sum,carry);
    }
};