class Solution {
  public:
    int count(struct Node* head, int key) {
        // add your code here
        int count = 0;
        Node* curr = head;
        while(curr != NULL){
            if(curr -> data == key) count++;
            curr = curr -> next;
        }
        return count;
    }
};
