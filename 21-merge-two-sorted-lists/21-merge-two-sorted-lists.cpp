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
    ListNode * add(ListNode * head,int val){
        if(head == NULL){
            return new ListNode(val);
        }
        ListNode * temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new ListNode(val);
        return head;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode * ptr1 = list1;
        ListNode * ptr2 = list2;
        ListNode * mergedList = NULL;
        while(ptr1 != NULL && ptr2 != NULL){
            if(ptr1 -> val < ptr2 -> val){
                mergedList = add(mergedList,ptr1 ->val);
                ptr1 = ptr1->next;
            }else{
                mergedList = add(mergedList,ptr2 ->val);
                ptr2 = ptr2->next;
            }
        }
        while(ptr1){
             mergedList = add(mergedList,ptr1 ->val);
             ptr1 = ptr1->next;
        }
        while(ptr2){
             mergedList = add(mergedList,ptr2 ->val);
             ptr2 = ptr2->next;
        }
        
        return mergedList;
    }
};