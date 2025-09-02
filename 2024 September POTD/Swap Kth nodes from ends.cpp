class Solution {
  public:
    Node* swapKth(Node* head, int k) {
        // code here
        Node* curr = head;
        Node* firstNode = NULL;
        Node* secondNode = NULL;
        while(curr != NULL){
            k--;
            if(k == 0){
                firstNode = curr;
            }
            curr = curr -> next;
            if(secondNode != NULL) {
                secondNode = secondNode -> next;
                
            }
            if(k == 0){
                secondNode = head;
                // cout << secondNode -> data;
            }
        }
        
        if(firstNode == NULL) return head;
        swap(firstNode -> data, secondNode -> data);
        return head;
    }
};
