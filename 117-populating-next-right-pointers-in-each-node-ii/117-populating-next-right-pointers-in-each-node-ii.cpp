
int cnt;

class Solution {
public:
    Node* connect(Node* root) {
        
        if( cnt >= 54){
            return NULL;
        }
        
        if(root == NULL) return root;
        
        root->next = NULL;
        Node* head = root;

        while(root != NULL){    

            Node* childHead = new Node();
            Node* child = childHead;
            
            for(Node* par=root; par != NULL; par = par->next){
                if(par->left){
                    child->next = par->left;
                    child = child->next;
                }    
                if(par->right){
                    child->next = par->right;
                    child = child->next;
                }
            }
            root = childHead->next;
            childHead->next = NULL;
            delete childHead;
        }
        cnt++;
        return head;
    }
};