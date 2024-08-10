class Solution {
  public:
    // Function to rotate a linked list.
    Node* rotate(Node* head, int k) {
        // Your code here
        Node* leftLastNode = NULL;
        Node* rightStartNode = NULL;
        Node* rightLastNode = NULL;
        
        Node* currNode = head;
        int count = 0;
        while(currNode != NULL){
            count++;
            currNode = currNode -> next;
        }
        if(count == k) return head;
        currNode = head;
        
        while(currNode != NULL){
            k--;
            if(k == 0) leftLastNode = currNode;
            if(k == -1) rightStartNode = currNode;
            if(currNode -> next == NULL) rightLastNode = currNode;
            currNode = currNode -> next;
        }
        rightLastNode -> next = head;
        leftLastNode -> next = NULL;
        return rightStartNode;
    }
};
