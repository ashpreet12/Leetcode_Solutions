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
    ListNode* oddEvenList(ListNode* head) {
        
        if(head == NULL || head->next == NULL || head->next->next == NULL){
            return head;
        }
        ListNode * evenHead = NULL;
        ListNode * evenTemp = NULL;
        ListNode * oddTemp = head;
        ListNode * oddPrev = NULL;
        
        while(oddTemp != NULL && oddTemp->next != NULL ){
            
            
            if(evenHead == NULL){
                evenHead = oddTemp->next;
                evenTemp = evenHead;
            }else{
                
                evenTemp->next = oddTemp->next;
                evenTemp = evenTemp->next;
            }
            oddPrev = oddTemp;
            oddTemp->next = oddTemp->next->next;
            oddTemp = oddTemp->next;
        }
        
        evenTemp->next = NULL;
        
        if(oddTemp!= NULL){
            oddTemp->next = evenHead;
        }else{
            oddPrev->next = evenHead;
        }
        
        return head;
        
    }
};