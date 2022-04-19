/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return root;
        
        root->next = NULL;

        Node* head = root;

        while(root->left != NULL){
        
            Node* childHead = new Node();
            Node* child = childHead;
            
            for( Node* par = root; par != NULL; par = par->next){                
                child->next = par->left;
                child = child->next;
                
                child->next = par->right;
                child = child->next;
            }
            root = root->left;
            
            childHead->next = NULL;
            delete childHead;
        }
        
        return head;
    }
};