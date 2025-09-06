class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        
        Node* fast = head;
        Node* slow = head;
        
        while(fast != NULL && fast -> next != NULL){
            
            fast = fast -> next -> next;
            slow = slow -> next;
            if(fast == slow) break;
        }
        if(fast == NULL || fast -> next == NULL) return 0;
        
        int count = 1;
        while(fast -> next != slow) {
            fast = fast -> next;
            count++;
        }
        return count;
    }
};
