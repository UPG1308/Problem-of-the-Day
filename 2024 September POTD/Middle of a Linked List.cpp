class Solution {
  public:
    /* Should return data of middle node. If linked list is empty, then -1 */
     int getMiddle(Node* head) {
        if (head == NULL || head->next == NULL) return head->data;
        Node* sloPtr = head;
        Node* fasPtr = head;
        while(fasPtr != NULL && fasPtr->next != NULL){
            sloPtr = sloPtr->next;
            fasPtr = fasPtr-> next-> next;
        }
        return sloPtr->data;
    }
};
