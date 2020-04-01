/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        Node* temp = head;
        if(head == NULL) return head;

        Node* current = head;
        
        while(current != NULL)
        {
            if(current->child)
            {
                temp = current->child;
                while(temp->next) temp  = temp->next;
                
                if(current->next)
                {
                    current->next->prev = temp;
                }
                    temp->next = current->next;
                    current->next = current->child;
                    current->child->prev = current;
                current->child = NULL;
                
            }
            current = current->next;
            
        }
        return head;
    }
};