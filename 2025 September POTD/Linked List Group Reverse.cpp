class Solution {
  public:

    Node* reverse(Node* head) {
        Node* prev = NULL;
        while (head != NULL) {
            Node* temp = head -> next;
            head -> next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
    
    Node *reverseKGroup(Node *head, int k) {
        Node* ans = NULL;
        Node* prev = NULL;
        Node* ptr = head;
        int idx = 1;
        
        while (ptr != NULL) {
            Node* nex = ptr;
            for (int i = 1; i < k; i++) {
                if (nex -> next == NULL) break;
                nex = nex -> next;
            }

            Node* temp = nex -> next;
            nex -> next = NULL;
            
            reverse(ptr);
            
            if (ans == NULL) {
                ans = nex;
                prev = ptr;
            }
            else {
                prev -> next = nex;
                prev = ptr;
            }
            
            ptr = temp;
        }
        
        return ans;
    }
};
