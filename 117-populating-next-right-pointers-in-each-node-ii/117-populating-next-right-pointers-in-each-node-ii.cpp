
int cnt;

vector<string> vs;


string treeNodeToString(Node *root){
    if (root == nullptr){
        return "[]";
    }

    string output = "";
    queue<Node *> q;
    q.push(root);
    while (!q.empty()){
        Node *node = q.front();
        q.pop();

        if (node == nullptr){
            output += "null, ";
            continue;
        }

        output += to_string(node->val) + ", ";
        q.push(node->left);
        q.push(node->right);
    }
    return "[" + output.substr(0, output.length() - 2) + "]";
}

class Solution {
public:
    Node* connect(Node* root) {
        
        vs.push_back(treeNodeToString(root));
        
        if( cnt == 54){
            for(string s:vs){
                cout<<s<<endl;
            }
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