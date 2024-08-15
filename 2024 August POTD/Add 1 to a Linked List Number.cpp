class Solution {
  public:
    Node* addOne(Node* head) {
        // Your Code here
        // return head of list after adding one
        Node* prevNoneNine = NULL;
        Node* curr = head;
        
        while(curr != NULL){
            if(curr -> data < 9) prevNoneNine = curr;
            curr = curr -> next;
        }
        if(prevNoneNine == NULL){
            Node* node = new Node(1);
            node -> next = head;
            curr = head;
            while(curr != NULL){
                curr -> data = 0;
                curr = curr -> next;
            }
            return node;
        }
        prevNoneNine -> data += 1;
        curr = prevNoneNine -> next;
        while(curr != NULL){
            curr -> data = 0;
            curr = curr -> next;
        }
        return head;
    }
};
