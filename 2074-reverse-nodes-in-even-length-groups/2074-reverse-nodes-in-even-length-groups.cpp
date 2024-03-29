class Solution {
public:
    void reverseGroups(ListNode* p, int groupsize){           
        ListNode* tail = p->next, *temp;
        for(int i=1; i < groupsize; i++){
            temp = p->next;
            p->next = tail->next;
            tail->next = tail->next->next;
            p->next->next = temp;
        }
    }
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        int groupsize = 2;
        ListNode* prev = head, *start = head, *end = head;
        
        while(end != NULL && end->next != NULL){
            
            int tempsize = groupsize;
            while( tempsize && end->next != NULL){
                start = end;
                end = end->next;
                tempsize--;
            }
            
            if(groupsize%2){
                if( tempsize && tempsize&1) 
                    reverseGroups(prev, groupsize-tempsize);
                prev = end;
            }
            else{            
                if( (tempsize)%2 == 0 ) {
                    start = prev->next;
                    reverseGroups(prev, groupsize-tempsize);
                    prev = end = start;
                }
            }
            groupsize++;
        }            
        return head;
    }
};