class Solution {
  public:
     void deleteAlt(struct Node *head) {
        Node* temp=head;
        while(temp && temp->next){
            temp->next = temp->next->next;
            temp = temp->next;
        }
    }
};
