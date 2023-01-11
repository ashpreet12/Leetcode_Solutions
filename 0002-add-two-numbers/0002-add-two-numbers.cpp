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
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode*head = NULL;
        ListNode*prev = NULL;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        vector<int> add;
        int carry = 0;
        
        while(temp1!=NULL && temp2!=NULL){
            
            int sum = temp1->val + temp2->val + carry;
            if(sum>9){
                carry = (sum/10)%10;
            }else{
                carry = 0;
            }
            
            //Inserting in Linked List
            
            if(head==NULL){
                ListNode*temp = new ListNode();
                temp->val = sum%10;
                head = temp;
                prev = temp;
            }else{
                ListNode*temp = new ListNode();
                temp->val = (sum%10);
                prev->next = temp;
                prev = temp;
            }
            
            
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        
        
        
        if(temp1==NULL){
            
            while(temp2!=NULL){
               int sum = temp2->val + carry;
                if(sum>9){
                    carry = (sum/10)%10;
                }else{
                    carry = 0;
                } 
                
                ListNode*temp = new ListNode();
                temp->val = (sum%10);
                prev->next = temp;
                prev = temp;
                
                temp2 = temp2->next;
            }
          
        }
        
        else if(temp2==NULL){
            while(temp1!=NULL){
               int sum = temp1->val + carry;
                if(sum>9){
                    carry = (sum/10)%10;
                }else{
                    carry = 0;
                } 
                
                ListNode*temp = new ListNode();
                temp->val = (sum%10);
                prev->next = temp;
                prev = temp;
                
                temp1 = temp1->next;
            }
        }
        
        if(carry!=0){
                ListNode*temp = new ListNode();
                temp->val = carry;
                prev->next = temp;
                prev = temp;
        }
        
        return head;
    }
};