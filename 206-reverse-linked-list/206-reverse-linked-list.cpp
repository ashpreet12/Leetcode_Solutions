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
    ListNode* reverseList(ListNode* head) {
        ListNode * prev = NULL;
        ListNode * curr = head;
        ListNode * nextP = NULL;
        
        while(curr != NULL){
            if(curr->next == NULL){
                head = curr;
            }
            nextP = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextP;
        }
        return head;
    }
};