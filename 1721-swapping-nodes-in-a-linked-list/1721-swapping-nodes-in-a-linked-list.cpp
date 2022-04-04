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
    
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* l1 = NULL, *l2 = NULL;
        for(auto  p = head; p != NULL; p = p->next){
            l2 = (l2 == NULL)? NULL:l2->next;
            if( --k == 0){
                l1 = p;
                l2 = head;
            }
        }
        swap(l1->val,l2->val);
        return head;
    }
};