/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode * detectedNode = NULL;
        unordered_set<ListNode *> s;
        
        ListNode * temp = head;
        while(temp != NULL){
            if(s.find(temp) != s.end()){
                detectedNode = * s.find(temp);
                return detectedNode;
            }
            s.insert(temp);
            temp = temp->next;
            
        }
        return detectedNode;
    }
};